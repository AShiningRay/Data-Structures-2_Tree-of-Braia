#define MINIAUDIO_IMPLEMENTATION

#define MIN_XSIZE 127
#define MIN_YSIZE 56

#include "Audio Engine/audio.h"

//#include "../PlayerData/Inventory.h" // Already includes windows.h library required for the buttons(used for colors too)
#include "gametiming.h"
#ifdef __linux__
#include "linux_keyboard.h"
#include <sys/ioctl.h>
#endif
#include "consoleCommands.h"
#include "Console_Colors/atari.h"
//#include "../Combat/Combat.h"
#include "../Maps/Maps.h"

#ifdef __linux__
void drawSizeRequestScreen(struct winsize *ws);
#endif


int main()
{
    printf("\x1B[0m");
    SetColor(WHITE);
    initFPSLimit();
    if(initAudioEngine() == -1) { return -1; }
#ifdef __linux__

#if defined(TIOCGWINSZ)
    struct winsize ws;

    if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != 0) {
        printf("Could not get window size...");
        exit(1);
    }

    if (ws.ws_col < MIN_XSIZE || ws.ws_row < MIN_YSIZE)
    {
        while (ws.ws_col < MIN_XSIZE || ws.ws_row < MIN_YSIZE)
        {
            if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) != 0) {
                printf("Could not get window size...");
                exit(1);
            }

            clearConsoleScreen();
            drawSizeRequestScreen(&ws);
        }
    }

initKeyboard();
#endif  /* defined(TIOCGWINSZ) */
    
    sleep(4);
#elif _WIN32
    keybd_event ( VK_MENU, 0x36, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, 0, 0 );
    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 );
    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 ); // Forces the console to Full Screen Mode.
#endif

    playBGM("Intro");
    showLogo();
    stopBGM("Intro");

    initEnemies();
    //printf("Enemies Initialized...\n");
    initAreas();
    //printf("Areas Initialized...\n");
    initNavAreas();
    //printf("Navigation Areas Initialized...\n");

    playBGM("NameInput");
    insertCharName(0);

    // Clear inputs from the logo "START GAME" prompt
    if(GetAsyncKeyState(VK_ENTER) != 0){}
    if(GetAsyncKeyState(VK_BACKSPACE) != 0){}

    stopBGM("NameInput");
    unsigned char curArea = 0; // TODO: Loading saved data should alter this index before diving below (i don't really think this will have more than 256 areas)
    while(curArea != ENDING) 
    {
        limitFPS(150);
        curArea = enterArea(AreaNames[curArea]);
    }
    
    ending();

    return 0;
}

void drawSizeRequestScreen(struct winsize *ws)
{
    useBoldConsoleText();
    useItalicConsoleText();
    textcolor(rand() % 16);
    textbackground(BLACK);
    if(ws->ws_row > 6)
        moveCursorDownBy(ws->ws_row / 2 - 3);

    int indent = (ws->ws_col > 33) ? (ws->ws_col / 2 - 16) : 0;

    printCenteredScreen(indent, "┌─────WINDOW SIZE ERROR!!!─────┐\n");
    char sizeMessage[50];
    snprintf(sizeMessage, sizeof(sizeMessage), "│   WINDOW SIZE:  %4d x%4d   │\n", ws->ws_col, ws->ws_row);
    printCenteredScreen(indent, sizeMessage);
    printCenteredScreen(indent, "│   REQUIRED SIZE: 127 x  56   │\n");
    printCenteredScreen(indent, "│──────────────────────────────│\n");
    printCenteredScreen(indent, "│ Please resize your window!!! │\n");
    printCenteredScreen(indent, "└──────────────────────────────┘\n");

    textcolor(WHITE);
    textbackground(BLACK);
    restoreConsoleText();
    usleep(333000);
}