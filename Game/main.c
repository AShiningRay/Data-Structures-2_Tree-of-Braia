#define MINIAUDIO_IMPLEMENTATION

#define MAX_XSIZE 128
#define MAX_YSIZE 56

#include "Audio Engine/audio.h"

//#include "../PlayerData/Inventory.h" // Already includes windows.h library required for the buttons(used for colors too)
#include "gametiming.h"
#ifdef __linux__
#include "linux_keyboard.h"
#endif
#include "consoleCommands.h"
#include "Console_Colors/atari.h"
//#include "../Combat/Combat.h"
#include "../Maps/Maps.h"

int main()
{
    printf("\x1B[0m");
    SetColor(WHITE);
    initFPSLimit();
    if(initAudioEngine() == -1) { return -1; }
#ifdef __linux__
    initKeyboard();
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
