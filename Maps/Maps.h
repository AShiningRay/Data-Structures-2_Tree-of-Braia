#include "../PlayerData/Inventory.h" // Already includes windows.h library required for the buttons(used for colors too)
#include "../Combat/Combat.h"
#include "../TAD_DialogHash/Dialogs_PlayerLines.h"
#include "../TAD_DialogHash/DialogsNPC.h"
#include "Minimaps.h"
#include "Area1_NavigationScreens.h"

void talkToMerchant();
void talkToNPC2();
void talkToNPC3();
void talkToNPC4();
void talkToNPC5();
void talkToNPC6();
void renderAreaNavigation(unsigned char areaIndex, unsigned char navIndex, unsigned char *playerX, unsigned char *playerY);

void showLogo();
unsigned char enterArea(char *areaName);
void ending();

bool drawSelectMenu();

Hash *playerDialogs = NULL;
Hash_NPC *NPCDialogs = NULL;

void showLogo()
{
    bool start = false;

    while(!start)
        {
            clearConsoleScreen();
            for(unsigned char y = 0; y <49; y++)
            {
                unsigned char xmax = strlen(Title_BG[y]);

                for(unsigned char x = 0; x < xmax; x++)
                    {
                        applyColorPalette(Title_BG[y][x]);
                        putchar(Title_BG[y][x]);
                    }
                    putchar('\n');
            }

            textcolor(LIGHTBLUE);
            useBoldConsoleText();
            moveCursorUpBy((48 / 2 + 35 / 2));
            limitFPS(1000);
            for(unsigned char y = 0; y <29; y++)
            {
                unsigned char xmax = strlen(Title[y]);
                bool skipDraw = true;

                limitFPS(-TARGET_TIME/2500);

                if(y == 25) { limitFPS(1500);}
                for(unsigned char x = 0; x < xmax; x++)
                {
                    //  '.' chars are delimiters for when the title should be drawn with its black BG, we should not draw them, only check
                    if(Title[y][x] == '.' && !skipDraw) { skipDraw = true; continue; }

                    if(skipDraw) { moveCursorRightBy(1); }
                    else { putchar(Title[y][x]); }

                    fflush(stdout);

                    if(Title[y][x] == '.' && skipDraw) { skipDraw = false; }

                    if(y >= 25 && !skipDraw) { textcolor(YELLOW); limitFPS(-TARGET_TIME/1200); }
                }
                
                putchar('\n');
            }
            moveCursorDownBy(12);
            
            for(unsigned char y = 0; y <5; y++) // "Press Ctrl" will be below the title's graphics, so no need to do any BG checks
            {
                unsigned char xmax = strlen(pressCtrl[y]);

                for(unsigned char x = 0; x < xmax; x++)
                {
                    putchar(pressCtrl[y][x]);
                }
                putchar('\n');
            }
            
            textcolor(WHITE);
            textbackground(BLACK);

            unsigned char colorPalette = 0;
            while(1)
            {
                moveCursorUpBy(5);
                textcolor(colorPalette++);
                if(colorPalette > 15) { colorPalette = 0; }
                for(unsigned char y = 0; y <5; y++) // "Press Ctrl" will be below the title's graphics, so no need to do any BG checks
                {
                    unsigned char xmax = strlen(pressCtrl[y]);

                    for(unsigned char x = 0; x < xmax; x++)
                    {
                        putchar(pressCtrl[y][x]);
                    }
                    putchar('\n');
                }
                if(GetAsyncKeyState (VK_ENTER) != 0)
                {
                    restoreConsoleText();
                    return;
                }
                limitFPS(150);
            }
        }
}

void showIntro()
{
    unsigned short int ypos = 0;
    unsigned char colorIdx = 0;
    unsigned char colors[] = {YELLOW, WHITE, DARKGRAY};
    useBoldConsoleText();
    textcolor(colors[colorIdx]);
    while(true)
    {
        clearConsoleScreen();
        moveCursorDownBy(12);

        printf("┌");
        for(unsigned char i = 0; i < MIN_XSIZE - 2; i++)
            printf("─");
        printf("┐\n");

        for(unsigned short int y = ypos; y < MIN_YSIZE+ypos-24; y++)
        {
            unsigned char xmax = strlen(introStory[y]);

            for(unsigned char x = 0; x < xmax; x++)
            {
                putchar(introStory[y][x]);   
            }
            putchar('\n');
        }

        printf("└");
        for(unsigned char i = 0; i < MIN_XSIZE - 2; i++)
            printf("─");
        printf("┘\n");

        if (ypos < sizeof(introStory) / 128 - 34) { ypos++; }
        else
        {
            limitFPS(500);
            textcolor(colors[colorIdx++]);
            if(colorIdx > 3)
            {
                clearConsoleScreen();
                break;
            }
        }
        
        // Allow it to be skipped with enter
        if(GetAsyncKeyState (VK_ENTER) != 0)
            ypos = sizeof(introStory) / 128 - 34;

        limitFPS(250);
    }
    limitFPS(2000);
    restoreConsoleText();
    textcolor(WHITE);
    textbackground(BLACK);
}

unsigned char enterArea(char *areaName) 
{
    bool moved = false;    
    unsigned char encounterChance = 0, levelCap = 9, navIndex = 0, navIndexTmp = 0, areaIndex = 0, playerX = 0, playerY = 0;

    for(unsigned char BGM = 0; BGM < NUM_AREAS; BGM++) { stopBGM(AreaNames[BGM]); }
    playBGM(areaName);

    for(unsigned char area = 0; area < NUM_AREAS; area++) 
    {
        if(strcmp(AreaNames[area], areaName) == 0) 
        { 
            areaIndex = area; 
            break; 
        }
    }

    if(areaIndex == 0) // Hub Town is the only one with NPCs right now.
    {
        playerDialogs = InsertHashData();
        NPCDialogs = InsertHashDataNPC();
    }

    // Update party map position before drawing anything, as their position dictates the minimap area to be shown
    unsigned char areaY = AreaSize[areaIndex] / sizeof(Areas[areaIndex][0]);
    
    for(unsigned char y = 0; y < areaY; y++)
    {
        unsigned char xmax = strlen(Areas[areaIndex][y]);

        for(unsigned char x = 0; x < xmax; x++)
        {
            if (Areas[areaIndex][y][x] == '^' ||
                Areas[areaIndex][y][x] == 'v' ||
                Areas[areaIndex][y][x] == '<' ||
                Areas[areaIndex][y][x] == '>')
            {
                playerX = x;
                playerY = y;
            }
        }
    }

    while(1)
    {
        clearConsoleScreen();

        renderAreaNavigation(areaIndex, navIndex, &playerX, &playerY);
        putchar('\n');

        renderMainPartyStats(NAVIGATION_ACTIONS, "");

        moved = false;

        while (!moved) 
        {
            if(GetAsyncKeyState (VK_W) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                char dirY = 0, dirX = 0;

                if(Areas[areaIndex][playerY][playerX] == '^')      { dirY = -1; }
                else if(Areas[areaIndex][playerY][playerX] == '<') { dirX = -1; }
                else if(Areas[areaIndex][playerY][playerX] == 'v') { dirY = 1;  }
                else if(Areas[areaIndex][playerY][playerX] == '>') { dirX = 1;  }

                switch(Areas[areaIndex][playerY+dirY][playerX+dirX])
                {
                    case '`': case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 92 && areaIndex != 0) // Area 0 is the hub. Shouldn't have enemy encounters
                        {
                            limitFPS(0);
                            enemyEncounter(levelCap-9,levelCap);
                            playBGM(areaName); 
                        }
                        // TODO: Check if there's any special characters close to the party, like a wall, an entrance, etc
                        char tmpchar = Areas[areaIndex][playerY][playerX];
                        Areas[areaIndex][playerY][playerX] = Areas[areaIndex][playerY+dirY][playerX+dirX];
                        Areas[areaIndex][playerY+dirY][playerX+dirX] = tmpchar;
                        playerX += dirX;
                        playerY += dirY;
                        moved = true;
                        do
                        {
                            navIndexTmp = rand() % 3;
                        } while (navIndexTmp == navIndex);
                        navIndex = navIndexTmp;
                        limitFPS(50);
                    } break;
                    case 'G': // Gate
                    {
                        if(character[0].key) { /* TODO */ }
                        else
                        {
                            textcolor(RED);
                            printf("\nYou have not found the key yet!");
                            textcolor(WHITE);
                            limitFPS(1500);
                        }
                    } break;
                    case 'E': // Entrance
                    {
                        return areaIndex + 1; // On the area indices, the first interior is always directly after the area it's located in
                    }break;
                    case 'O': // Outside
                    {
                        return areaIndex - 1;
                    }break;
                    case 'H': // Path to Hub Town
                    {
                        return 0;
                    }break;
                    case 'R':
                    {
                        moved = true;
                        playSFX("HealSpot");
                        for(unsigned char heal = 0; heal < partySize; heal++) 
                        {
                            character[heal].current_HP = character[heal].max_HP;
                            character[heal].current_MP = character[heal].max_MP;
                        }
                        limitFPS(1000);
                    }break;
                    case '?':
                    {
                        moved = true;

                        printf("%s GOT A HP POTION!", character[0].name);
                        limitFPS(1000);
                        Areas[areaIndex][playerY+dirY][playerX+dirX] = ' ';
                        character[0].it.HPpotion += 1;
                    }
                    case 'b' :
                    {
                            moved = true;
                            talkToNPC2();
                    } break;

                    case 'c' :
                    {
                            moved = true;
                            talkToNPC3();
                    } break;

                    case 'd' :
                    {
                            moved = true;
                            talkToNPC4();
                    } break;

                    case 'e' :
                    {
                            moved = true;
                            talkToNPC5();
                    } break;

                    case 'f' :
                    {
                            moved = true;
                            talkToNPC6();
                    } break;
                    case 'm' :
                    {
                        moved = true;
                        talkToMerchant();
                    } break;


                    // Area entry/exit
                    case '1' :
                    {
                        return 1; // Area 1
                    } break;
                    case '2' :
                    {
                        return 3; // Area 2
                    } break;
                }
            }

            else if(GetAsyncKeyState (VK_S) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                char dirY = 0, dirX = 0;

                if(Areas[areaIndex][playerY][playerX] == '^')      { dirY = 1; }
                else if(Areas[areaIndex][playerY][playerX] == '<') { dirX = 1; }
                else if(Areas[areaIndex][playerY][playerX] == 'v') { dirY = -1;  }
                else if(Areas[areaIndex][playerY][playerX] == '>') { dirX = -1;  }

                switch(Areas[areaIndex][playerY+dirY][playerX+dirX])
                {
                    case '`': case ':': case ';': case '.': case ' ':
                    {
                        if(encounterChance >= 87 && areaIndex != 0) // Area 0 is the hub. Shouldn't have enemy encounters
                            {
                                limitFPS(0);
                                enemyEncounter(levelCap-9,levelCap);
                                playBGM(areaName);
                            }
                            // TODO: Check if there's any special characters close to the party, like a wall, an entrance, etc
                            char tmpchar = Areas[areaIndex][playerY][playerX];
                            Areas[areaIndex][playerY][playerX] = Areas[areaIndex][playerY+dirY][playerX+dirX];
                            Areas[areaIndex][playerY+dirY][playerX+dirX] = tmpchar;
                            playerX += dirX;
                            playerY += dirY;
                            moved = true;
                            do
                            {
                                navIndexTmp = rand() % 3;
                            } while (navIndexTmp == navIndex);
                            navIndex = navIndexTmp;
                            limitFPS(50);
                    } break;
                    // Moving back shall not trigger any interactions, as the player can't see the object
                }
            }

            else if(GetAsyncKeyState (VK_A) != 0)
            {
                playBGM("FootStep");
                encounterChance = rand() % 100;

                char dirY = 0, dirX = 0;

                if(Areas[areaIndex][playerY][playerX] == '^')      { Areas[areaIndex][playerY][playerX] = '<'; dirX = -1; }
                else if(Areas[areaIndex][playerY][playerX] == '<') { Areas[areaIndex][playerY][playerX] = 'v'; dirY = 1;  }
                else if(Areas[areaIndex][playerY][playerX] == 'v') { Areas[areaIndex][playerY][playerX] = '>'; dirX = 1;  }
                else if(Areas[areaIndex][playerY][playerX] == '>') { Areas[areaIndex][playerY][playerX] = '^'; dirY = -1; }

                // TODO: Check if there's any special characters close to the party, like a wall, an entrance, etc
                moved = true;
                do
                {
                    navIndexTmp = rand() % 3;
                } while (navIndexTmp == navIndex);
                navIndex = navIndexTmp;
                limitFPS(100);
            }

            else if(GetAsyncKeyState (VK_D) != 0)
            {
                playBGM("FootStep");

                char dirY = 0, dirX = 0;
                if(Areas[areaIndex][playerY][playerX] == '^')      { Areas[areaIndex][playerY][playerX] = '>'; dirX = 1;  }
                else if(Areas[areaIndex][playerY][playerX] == '>') { Areas[areaIndex][playerY][playerX] = 'v'; dirY = 1;  }
                else if(Areas[areaIndex][playerY][playerX] == 'v') { Areas[areaIndex][playerY][playerX] = '<'; dirX = -1; }
                else if(Areas[areaIndex][playerY][playerX] == '<') { Areas[areaIndex][playerY][playerX] = '^'; dirY = -1; }

                // TODO: Check if there's any special characters close to the party, like a wall, an entrance, etc
                moved = true;
                do
                {
                    navIndexTmp = rand() % 3;
                } while (navIndexTmp == navIndex);
                navIndex = navIndexTmp;
                limitFPS(100);
            }
            else if(GetAsyncKeyState (VK_ENTER) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                openInventory();
            }

            else if(GetAsyncKeyState (VK_BACKSPACE) != 0)
            {
                playSFX("OpenMenu");
                moved = true;
                renderPlayerSkillMenu();
            }
            limitFPS(0);
        } // Ends the Move function
    }
}

void talkToMerchant()
{
    SearchHash_NPC(NPCDialogs, 1, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    bool buy = drawSelectMenu();
    if(buy)
        {
            if(character[0].gold >= 250)
                {
                    SearchHash_NPC(NPCDialogs, 2, &npcLine);
                    printf("\n\t\t%s", npcLine.speak);
                    character[0].gold -= 250;
                    character[0].it.HPpotion += 1;
                    character[0].it.MPpotion += 1;
                }

            else if (character[0].it.HPpotion == 9 || character[0].it.MPpotion == 9)
                {
                    SearchHash_NPC(NPCDialogs, 6, &npcLine);
                    printf("\n\t\t%s", npcLine.speak);
                }
            else
                {
                    SearchHash_NPC(NPCDialogs, 5, &npcLine);
                    printf("\n\t\t%s", npcLine.speak);
                }

        }
    else
        {
            SearchHash_NPC(NPCDialogs, 3, &npcLine);
            printf("\n\t\t%s", npcLine.speak);
        }
    limitFPS(700);
    SearchHash_NPC(NPCDialogs, 4, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(2000);
}

void talkToNPC2()
{
    SearchHash_NPC(NPCDialogs, 10, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 4, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(1200);
}

void talkToNPC3()
{
    SearchHash_NPC(NPCDialogs, 8, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 5, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC4()
{
    SearchHash_NPC(NPCDialogs, 11, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 3, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC5()
{
    SearchHash_NPC(NPCDialogs, 9, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 6, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

void talkToNPC6()
{
    SearchHash_NPC(NPCDialogs, 12, &npcLine);
    printf("\n\n\t\t%s", npcLine.speak);
    limitFPS(700);
    SearchHash(playerDialogs, 7, &pLine);
    printf("\n\t\t%s%s", character[0].name, pLine.speak);
    limitFPS(2400);
}

bool drawSelectMenu()
{
    bool moved = false;
    bool yes = true;
    while (1)
        {
            moved = false;

            if(yes)
            {
                printf("\t [ ");
                textcolor(GREEN);
                printf(">> ");
                textcolor(WHITE);
                printf("Yes      No ]");
                printf("\033[20D");
            }

            else
            {
                printf("\t [    Yes   ");
                textcolor(GREEN);
                printf(">> ");
                textcolor(WHITE);
                printf("No ]");
                printf("\033[20D");
            }
            limitFPS(150);
            while(!moved)
            {
                if(GetAsyncKeyState (VK_D) != 0)
                    {
                        moved = true;
                        playSFX("CursorMove");
                        if(yes)
                            {
                                yes = false;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_A) != 0)
                    {
                        moved = true;
                        playSFX("CursorMove");
                        if(!yes)
                            {
                                yes = true;
                                break;
                            }
                    }

                if(GetAsyncKeyState (VK_ENTER) != 0)
                    {
                        moved = true;
                        playSFX("OpenMenu");
                        if(yes) return 1;
                        else return 0;
                    }

            }
        }

    return 0;
}

void showEnding()
{
    unsigned char ymax = 1;
    while(ymax !=50)
        {
            clearConsoleScreen();
                for(unsigned char y = 0; y <ymax; y++)
                {
                    unsigned char xmax = strlen(Credits[y]);

                    for(unsigned char x = 0; x < xmax; x++)
                        {
                            putchar(Credits[y][x]);   
                        }
                    putchar('\n');
                }
            ymax++;
        }
    textcolor(WHITE);
    textbackground(BLACK);
}

void renderAreaNavigation(unsigned char areaIndex, unsigned char navIndex, unsigned char *playerX, unsigned char *playerY)
{
    if(areaIndex > 0) { navIndex += numNavAreas[areaIndex-1]; }
    printf("  ┌─────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    for(unsigned char y = 0; y < NAVAREA_YSIZE; y++) 
    {
        printf("  │");
        for(unsigned char x = 0; x < NAVAREA_XSIZE; x++) 
        {
            char pixelToDraw = navAreas[navIndex][y][x];
            applyColorPalette(pixelToDraw);
            putchar(pixelToDraw);
        }
        textcolor(WHITE);
        textbackground(BLACK);
        printf("│");

        // Draw the mini-map at the side
        if(y == (NAVAREA_YSIZE/2) - 6) 
        { 
            printf(" ┌───── "); 
            useBoldConsoleText();
            textcolor(DARKGRAY);
            printf("MINIMAP");
            textcolor(WHITE);
            restoreConsoleText();
            printf(" ─────┐");
        }

        else if(y > (NAVAREA_YSIZE/2) - 6 && y < (NAVAREA_YSIZE/2) + 6)
        {
            printf(" │");
            unsigned char minimapY = *playerY - 6 + (y - (NAVAREA_YSIZE/2) + 6);
            for(unsigned char minimapX = 0; minimapX < 19; minimapX++) 
            {
                if(minimapY*(strlen(Areas[areaIndex][0])) + *playerX - 7 + minimapX < 0 ||
                minimapY*(strlen(Areas[areaIndex][0])) + *playerX - 7 + minimapX > AreaSize[areaIndex] ||
                *playerX - 7 + minimapX < 0 || minimapY >= AreaSize[areaIndex] / sizeof(Areas[areaIndex][0]) ||
                *playerX - 7 + minimapX >= strlen(Areas[areaIndex][minimapY]))
                {
                    textcolor(WHITE);
                    textbackground(BLACK);
                    putchar(' ');
                }
                else 
                {
                    char pixelToDraw = Areas[areaIndex][minimapY][*playerX - 7 + minimapX];
                    applyColorPalette(pixelToDraw);
                    putchar(pixelToDraw);
                }
            }
            textcolor(WHITE);
            textbackground(BLACK);
            printf("│");
        }
        else if (y == (NAVAREA_YSIZE/2) + 6) { printf(" └───────────────────┘"); }
        textcolor(WHITE);
        textbackground(BLACK);
        printf("\n");
    }
    printf("  └─────────────────────────────────────────────────────────────────────────────────────────────────────┘");
}