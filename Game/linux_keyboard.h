#include <fcntl.h>
#include <linux/input.h>
#include <string.h>
#include <termios.h>
#include <pthread.h>
#include <unistd.h>

#define PATH_SIZE 256
#define NUM_KEYS 185
int fd;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for thread safety
pthread_t input_thread;
_Bool key_states[NUM_KEYS]; // Array to hold key states

typedef enum 
{
    VK_ = 0,
    VK_ESC = 1,
    VK_1 = 2,
    VK_2 = 3,
    VK_3 = 4,
    VK_4 = 5,
    VK_5 = 6,
    VK_6 = 7,
    VK_7 = 8,
    VK_8 = 9,
    VK_9 = 10,
    VK_0 = 11,
    VK_MINUS = 12,
    VK_EQUAL = 13,
    VK_BACKSPACE = 14,
    VK_TAB = 15,
    VK_Q = 16,
    VK_W = 17,
    VK_E = 18,
    VK_R = 19,
    VK_T = 20,
    VK_Y = 21,
    VK_U = 22,
    VK_I = 23,
    VK_O = 24,
    VK_P = 25,
    VK_LBRACE = 26,
    VK_RBRACE = 27,
    VK_ENTER = 28,
    VK_LCONTROL = 29,
    VK_A = 30,
    VK_S = 31,
    VK_D = 32,
    VK_F = 33,
    VK_G = 34,
    VK_H = 35,
    VK_J = 36,
    VK_K = 37,
    VK_L = 38,
    VK_SEMICOLON = 39,
    VK_APOSTROPHE = 40,
    VK_GRAVE = 41,
    VK_LSHIFT = 42,
    VK_BACKSLASH = 43,
    VK_Z = 44,
    VK_X = 45,
    VK_C = 46,
    VK_V = 47,
    VK_B = 48,
    VK_N = 49,
    VK_M = 50,
    VK_COMMA = 51,
    VK_DOT = 52,
    VK_SLASH = 53,
    VK_RSHIFT = 54,
    VK_KPASTERISK = 55,
    VK_LALT = 56,
    VK_SPACE = 57,
    VK_CAPSLOCK = 58,
    VK_F1 = 59,
    VK_F2 = 60,
    VK_F3 = 61,
    VK_F4 = 62,
    VK_F5 = 63,
    VK_F6 = 64,
    VK_F7 = 65,
    VK_F8 = 66,
    VK_F9 = 67,
    VK_F10 = 68,
    VK_NUMLOCK = 69,
    VK_SCROLLLOCK = 70,
    VK_KP7 = 71,
    VK_KP8 = 72,
    VK_KP9 = 73,
    VK_KP_MINUS = 74,
    VK_KP4 = 75,
    VK_KP5 = 76,
    VK_KP6 = 77,
    VK_KP_PLUS = 78,
    VK_KP1 = 79,
    VK_KP2 = 80,
    VK_KP3 = 81,
    VK_KP0 = 82,
    VK_KP_DOT = 83,
    VK_ZENKAKUHANKAKU = 85,
    VK_102ND = 86,
    VK_F11 = 87,
    VK_F12 = 88,
    VK_RO = 89,
    VK_KATAKANA = 90,
    VK_HIRAGANA = 91,
    VK_HENKAN = 92,
    VK_MUHENKAN = 93,
    VK_KPJPCOMMA = 94,
    VK_KP_ENTER = 96,
    VK_RCONTROL = 97,
    VK_KPSLASH = 98,
    VK_SYSRQ = 99,
    VK_RIGHTALT = 100,
    VK_LINEFEED = 101,
    VK_HOME = 102,
    VK_UP = 103,
    VK_PAGEUP = 104,
    VK_LEFT = 105,
    VK_RIGHT = 106,
    VK_END = 107,
    VK_DOWN = 108,
    VK_PAGEDOWN = 109,
    VK_INSERT = 110,
    VK_DELETE = 111,
    VK_MACRO = 112,
    VK_MUTE = 113,
    VK_VOLUMEDOWN = 114,
    VK_VOLUMEUP = 115,
    VK_POWER = 116,
    VK_KPEQUAL = 117,
    VK_PAUSE = 119,
    VK_SCALE = 120,
    VK_KPCOMMA = 121,
    VK_HANGEUL = 122,
    VK_HANJA = 123,
    VK_YEN = 124,
    VK_LEFTMETA = 125,
    VK_RIGHTMETA = 126,
    VK_COMPOSE = 127,
    VK_STOP = 128,
    VK_AGAIN = 129,
    VK_PROPS = 130,
    VK_UNDO = 131,
    VK_FRONT = 132,
    VK_COPY = 133,
    VK_OPEN = 134,
    VK_PASTE = 135,
    VK_FIND = 136,
    VK_CUT = 137,
    VK_HELP = 138,
    VK_LMENU = 139,
    VK_CALC = 140,
    VK_SETUP = 141,
    VK_SLEEP = 142,
    VK_WAKEUP = 143,
    VK_FILE = 144,
    VK_SENDFILE = 145,
    VK_DELETEFILE = 146,
    VK_XFER = 147,
    VK_PROG1 = 148,
    VK_PROG2 = 149,
    VK_WWW = 150,
    VK_MSDOS = 151,
    VK_COFFEE = 152,
    VK_ROTATE_DISPLAY = 153,
    VK_CYCLEWINDOWS = 154,
    VK_MAIL = 155,
    VK_BOOKMARKS = 156,
    VK_COMPUTER = 157,
    VK_BACK = 158,
    VK_FORWARD = 159,
    VK_CLOSECD = 160,
    VK_EJECTCD = 161,
    VK_EJECTCLOSECD = 162,
    VK_NEXTSONG = 163,
    VK_PLAYPAUSE = 164,
    VK_PREVIOUSSONG = 165,
    VK_STOPCD = 166,
    VK_RECORD = 167,
    VK_REWIND = 168,
    VK_PHONE = 169,
    VK_ISO = 170,
    VK_CONFIG = 171,
    VK_HOMEPAGE = 172,
    VK_REFRESH = 173,
    VK_EXIT = 174,
    VK_MOVE = 175,
    VK_EDIT = 176,
    VK_SCROLLUP = 177,
    VK_SCROLLDOWN = 178,
    VK_DPAD_UP = 179,
    VK_DPAD_DOWN = 180,
    VK_DPAD_LEFT = 181,
    VK_DPAD_RIGHT = 182,
    VK_DPAD_CENTER = 183,
    VK_MAX = 184
} keyCodes;


char kbdevice[PATH_SIZE];

// Function to check if the device is a keyboard
int isKeyboard(const char *path) 
{
    char device_name[PATH_SIZE];

    int fd = open(path, O_RDONLY);
    if (fd == -1) { return 0; } // Failed to open device

    ioctl(fd, EVIOCGNAME(sizeof(device_name)), device_name);

    printf("DevName:%s\n", device_name);

    // Check for keyboard capabilities
    unsigned char ev_bits[EV_MAX / 8 + 1] = {0};
    if (ioctl(fd, EVIOCGBIT(0, sizeof(ev_bits)), ev_bits) < 0) 
    {
        close(fd);
        return false; // Failed to get event bits
    }

    close(fd);

    if((ev_bits[EV_KEY / 8] & (1 << (EV_KEY % 8))) != 0 && strstr(device_name, "Keyboard") != NULL)
    {
        printf("Using device:%s\n", device_name);
        return true;
    }

    return false;
}

void setTerminal(struct termios oldt) 
{
    struct termios newt;
    tcgetattr(STDIN_FILENO, &oldt);   // Get current terminal settings
    newt = oldt;                      // Copy to new settings
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
}

int kbHit()
{
    struct termios oldt, newt;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    int ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1; // There is an input available
    }

    return 0; // No input
}

void* updateInputs(void* arg) 
{
    if (fd == -1) 
    {
        perror("Failed to open keyboard device");
        return NULL;
    }

    struct input_event ev;
    char ch;
    while (1) 
    {
        /*
        ssize_t n = read(fd, &ev, sizeof(ev));
        if (n == (ssize_t)-1) { continue; }

        if (n == sizeof(ev) && ev.type == EV_KEY) 
        {
            pthread_mutex_lock(&mutex); // Lock the mutex
            key_states[ev.code] = ev.value; // Update key state
            pthread_mutex_unlock(&mutex); // Unlock the mutex
        }
        */
        if (kbHit())
        {
            char ch = getchar();

            pthread_mutex_lock(&mutex);
            
            switch (ch)
            {
                // Escape key
                case 27: key_states[VK_ESC] = 1; 

                // Movement keys
                case 'w': key_states[VK_W] = 1; break;
                case 'a': key_states[VK_A] = 1; break;
                case 's': key_states[VK_S] = 1; break;
                case 'd': key_states[VK_D] = 1; break;

                // Interaction keys
                case '\n': key_states[VK_ENTER] = 1; break;
                case 127: key_states[VK_BACKSPACE] = 1; break;
                
                // We might not need any more mappings than these
                default: break; // Unmapped
            }

            // Sleep for 4ms, we don't need to update inputs all that often, and
            // a 250Hz update rate is more than enough.
            usleep(4000);
            pthread_mutex_unlock(&mutex);
        }
    }

    return NULL;
}

void initKeyboard() 
{
    pthread_create(&input_thread, NULL, updateInputs, NULL); // Start the input thread
}

int GetAsyncKeyState(int keycode) 
{
    if (keycode < 0 || keycode >= NUM_KEYS) { return 0; }

    pthread_mutex_lock(&mutex);
    int state = (key_states[keycode] == 1) ? 0x8000 : 0;
    key_states[keycode] = 0;
    pthread_mutex_unlock(&mutex);
    return state;
}