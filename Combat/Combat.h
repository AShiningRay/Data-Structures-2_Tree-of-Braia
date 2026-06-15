#include "../EnemyData/Enemies.h"
#include "../Maps/Combat_BGs.h"

#define MAGIC_SPELLS_PER_LINE 4
#define CLASS_SKILLS_PER_LINE 4
#define COMBAT_TEXT_MAXLEN 79

#define NAVIGATION_ACTIONS false
#define COMBAT_ACTIONS true

#define PARTY_ESCAPED 127

void enemyEncounter(unsigned char baseLevel, unsigned char levelCap);
void checkPlayerXP();
void characterLeveledUp(unsigned char charIndex, unsigned short int leftOver_XP);

void renderCombatStartAnim();

void renderArea1BG(int animTime);
void renderEnemyCharacters(short int charIndex[3], bool isBoss[3], int animTime);

void renderPlayerSkillMenu();
unsigned char renderPlayerCombatEnemyMenu(bool runEnabled);
unsigned char renderPlayerMagicSpellMenu();
void renderMainPartyStats(bool showCombatActions, char *combatText);
void renderPlayerSkillMenu();
void renderEnemyCombatStat();

unsigned char selectEnemy();
unsigned char playerAttackEnemy(unsigned char enemyIndex);
bool calculateCriticalHitChance(unsigned short int luck);
bool playerUseSpell(char *spell, unsigned char enemyIndex);
bool tryEscape(int charIndex);


void enemyAttackPlayer(unsigned char enemyIndex, unsigned char charIndex);
void enemyDozesOff(unsigned char enemyIndex);

void enemyAction();

void enemyEncounter(unsigned char baseLevel, unsigned char levelCap)
{
    stopBGM("Area1");
    stopBGM("Area2");
    stopBGM("Area3");
    stopBGM("HubWorld");

    moveCursorUpBy(56);
    playSFX("EnemyEncounter");
    for(unsigned char y = 0; y < MAX_YSIZE-1; y++) 
    {
        if(y % 2 == 0)
        {
            for(unsigned char x = 0; x < MAX_XSIZE; x++) 
            {
                putchar(' ');
            }
            limitFPS(-(TARGET_TIME/2000));
            putchar('\n');
        }
        else 
        {
            moveCursorDownBy(1);
        }
    }

    moveCursorUpBy(56);
    for(unsigned char y = 0; y < MAX_YSIZE; y++) 
    {
        if(y % 2 == 1)
        {
            for(unsigned char x = 0; x < MAX_XSIZE; x++) 
            {
                putchar(' ');
            }
            limitFPS(-(TARGET_TIME/2000));
            putchar('\n');
        }
        else 
        {
            moveCursorDownBy(1);
        }
    }

    playBGM("EnemyFight1");

    short int enemiesToRender[3] = {-1, -1, -1}; // Sprite table indices
    bool enemyIsBoss[3] = {false, false, false}; // If the enemy is a boss UNUSED YET
    unsigned char spawnedEnemies = rand();
    
    if(spawnedEnemies % 3 == 0)      { enemiesInEncounter = 3; }
    else if(spawnedEnemies % 2 == 0) { enemiesInEncounter = 2; }
    else                             { enemiesInEncounter = 1; }

    for(unsigned char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        unsigned char enemyLevel = baseLevel + 1 + (rand() % (levelCap-1)); // Enemy Level always goes from "baseLevel+1" to "levelCap"

        if(enemyLevel > 0 && enemyLevel < 5)
        {
            generateEnemy(enemyIndex, "YELLOW BLOB", enemyLevel);
            enemiesToRender[enemyIndex] = 0;
        }

        else if(enemyLevel >= 5 && enemyLevel < 10)
        {
            generateEnemy(enemyIndex, "RED BLOB", enemyLevel);
            enemiesToRender[enemyIndex] = 1;
        }

        else if(enemyLevel > 10 && enemyLevel <= 15)
        {
            generateEnemy(enemyIndex, "C-GUY", enemyLevel);
            enemiesToRender[enemyIndex] = 2;
        }

        else if(enemyLevel > 15 && enemyLevel < 20)
        {
            generateEnemy(enemyIndex, "BIG CHICKEN", enemyLevel);
            enemiesToRender[enemyIndex] = 3;
        }

        else if(enemyLevel > 20 && enemyLevel <= 25)
        {
            generateEnemy(enemyIndex, "ALIEN-V", enemyLevel);
            enemiesToRender[enemyIndex] = 4;
        }

        else if(enemyLevel > 25 && enemyLevel < 30)
        {
            generateEnemy(enemyIndex, "BIG-O", enemyLevel);
            enemiesToRender[enemyIndex] = 5;
        }
    }

    renderEnemyCharacters(enemiesToRender, enemyIsBoss, -(TARGET_TIME/3000));

    checkPlayerXP();
    stopBGM("EnemyFight1");
}

void fightBoss(unsigned char enemyLevel)
{
    stopBGM("Area1");
    stopBGM("Area2");
    stopBGM("Area3");
    stopBGM("HubWorld");

    playBGM("BossFight1");

    short int enemiesToRender[3] = {-1, 0, 0};
    bool enemyIsBoss[3] = {true, false, false};

    if(enemyLevel == 10)
    {
        generateEnemy(0, "CURSED ARMOR", enemyLevel);
        enemiesToRender[0] = 0;
    }

    else if(enemyLevel == 20)
    {
        generateEnemy(0, "CYCLOPS", enemyLevel);
        enemiesToRender[0] = 1;
    }

    else if (enemyLevel == 30)
    {
        generateEnemy(0, "NONAME", enemyLevel);
        enemiesToRender[0] = 2;
    }

    renderEnemyCharacters(enemiesToRender, enemyIsBoss, -(TARGET_TIME/3000));
    checkPlayerXP();
    stopBGM("BossFight1");
}

void renderEnemyCharacters(short int charIndex[3], bool isBoss[3], int animTime) 
{
    char enemyIndex = 0, attackedEnemy = 0;
    int internalAnimTime;
    bool allEnemiesKilled = false, enteringEncounter = true, enemyChanged = true;
    bool hasBoss = false;

    for(int i = 0; i < 3; i++)
        if(isBoss[i])
            hasBoss = true;

    while (1) 
    {
        moveCursorUpBy(56);
        renderEnemyCombatStat();

        // BG should only animate at the start as internal animations (enemy killed, etc) should only affect the foreground.
        if(enteringEncounter) { renderArea1BG(animTime); enteringEncounter = false; } 
        else { renderArea1BG(0); }

        for(enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
        { 
            if(isBoss[enemyIndex]) { charIndex[enemyIndex] += NUM_ENEMIES; } // On the enemy sprite data, bosses are addressed after all normal enemies
        }

        char enemyHeight = 0;
        for(unsigned char y = 0; y < BG_YSIZE-FIGHTSCREEN_Y_PADDING; y++)
        {
            moveCursorLeftBy(FIGHTSCREEN_X_PADDING);
            for(unsigned char enemyDrawIdx = 0; enemyDrawIdx < enemiesInEncounter; enemyDrawIdx++) 
            {
                unsigned char charToRender = charIndex[enemyDrawIdx];
                for(unsigned char x = 0; x < sizeof(enemySprites[charToRender][0]); x++)
                {
                    char pixelToDraw = enemySprites[charToRender][y][x];
                    if(pixelToDraw != ' ' && Enemy[enemyDrawIdx].current_HP > 0) 
                    {
                        applyColorPalette(pixelToDraw);
                        putchar(pixelToDraw); 
                    }
                    else // if the enemy is dead/shouldn't be drawn OR the pixel is empty/transparent
                    {
                        moveCursorRightBy(1);
                    }

                    textcolor(WHITE);
                    textbackground(BLACK);
                }
                moveCursorLeftBy(ENEMY_X_SEPARATOR);
            }
            

            putchar('\n');
            enemyHeight += 1;
            if(animTime != 0 && enemyChanged) { limitFPS(animTime); }
        }

        enemyChanged = false; // Enemies have had their changes applied already, so set this flag as false until needed

        for(unsigned char y = 0; y < BG_YSIZE - FIGHTSCREEN_Y_PADDING - enemySpriteRows[charIndex[enemiesInEncounter-1]]; y++) { moveCursorDownBy(1); }
        SetColor(WHITE);

        allEnemiesKilled = true;
        for(unsigned char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
        {
            if(Enemy[enemyIndex].current_HP > 0) { allEnemiesKilled = false; }
        }

        if(allEnemiesKilled) { break; }

        attackedEnemy = renderPlayerCombatEnemyMenu(!hasBoss);

        // Has the party escaped?
        if(attackedEnemy == PARTY_ESCAPED) { break; }

        if(attackedEnemy >= 0 && Enemy[attackedEnemy].current_HP <= 0)
        {
            char combatText[COMBAT_TEXT_MAXLEN];
            if(isBoss[attackedEnemy]) { playSFX("BossDefeated");}
            else { playSFX("EnemyDefeated"); }
            
            snprintf(combatText, COMBAT_TEXT_MAXLEN, " '%s' was defeated! Party gained %d XP points and +%d gold!", Enemy[attackedEnemy].name, Enemy[attackedEnemy].XP_given, Enemy[attackedEnemy].gold_given);
            renderMainPartyStats(COMBAT_ACTIONS, combatText);
            moveCursorUpBy(10);
            character[0].current_XP += Enemy[attackedEnemy].XP_given;
            character[0].gold += Enemy[attackedEnemy].gold_given;
            limitFPS(1000);
            enemyChanged = true;
        }

        enemyAction();

        if(character[0].current_HP <= 0)
        {
            char combatText[COMBAT_TEXT_MAXLEN];
            snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s died...", character[0].name);
            renderMainPartyStats(COMBAT_ACTIONS, combatText);
            moveCursorUpBy(10);
            break;
        }

        // Clear all player actions from the UI, as this turn is over
        for(unsigned char i = 0; i < partySize; i++) {strcpy(character[i].action,""); }
    } 
    

    limitFPS(1000);
}

void checkPlayerXP()
{
    bool leveledUp = false;
    unsigned short int leftOver_XP = 0;

    if(character[0].current_XP >= character[0].next_XP)
    {
        leveledUp = true;
        leftOver_XP = (character[0].current_XP - character[0].next_XP);
    }

    if(leveledUp == true && character[0].Level < 10)
    {
        characterLeveledUp(0, leftOver_XP);
    }
    else if(character[0].Level == 10) character[0].current_XP = (character[0].next_XP) - 1;
}

void characterLeveledUp(unsigned char charIndex, unsigned short int leftOver_XP) 
{
    char combatText[COMBAT_TEXT_MAXLEN];
    playSFX("LevelUp");
    character[charIndex].Level += 1;
    character[charIndex].max_HP += 250;
    character[charIndex].current_HP = character[charIndex].max_HP;
    character[charIndex].max_MP += 80;
    character[charIndex].current_MP = character[charIndex].max_MP;
    character[charIndex].atk += 16;
    character[charIndex].def += 12;
    character[charIndex].inte += 10;
    character[charIndex].luck += 7;
    character[charIndex].spd += 5;
    character[charIndex].next_XP *= 2;
    character[charIndex].current_XP = 0;
    character[charIndex].current_XP += leftOver_XP;

    snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s Leveled UP to Level %d!!! ", character[charIndex].name, character[charIndex].Level);

    if(character[charIndex].Level == 2)
    {
        learnSkill(character[charIndex].magtree, "AQUA STORM");
        strcat(combatText, " LEARNED AQUA STORM!");
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("AQUA STORM");
    }

    else if(character[charIndex].Level == 4)
    {
        learnSkill(character[charIndex].phystree, "STR BOOST");
        strcat(combatText, " LEARNED STR BOOST!");
        character[charIndex].atk *= 1.20;
        character[charIndex].learnedSkills += 1;
    }

    else if(character[charIndex].Level == 3)
    {
        learnSkill(character[charIndex].magtree, "WIND GUST");
        strcat(combatText, " LEARNED WIND GUST!");
        character[charIndex].luck *= 1.05;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("WIND GUST");
    }

    else if(character[charIndex].Level == 6)
    {
        learnSkill(character[charIndex].magtree, "SCORCH FLAME");
        strcat(combatText, " LEARNED SCORCH FLAME!");
        character[charIndex].inte *= 1.05;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("SCORCH FLAME");
    }

    else if(character[charIndex].Level == 7)
    {
        learnSkill(character[charIndex].phystree, "DEF BOOST");
        strcat(combatText, " LEARNED DEF BOOST!");
        character[charIndex].def *= 1.20;
        character[charIndex].learnedSkills += 1;
    }

    else if(character[charIndex].Level == 8)
    {
        learnSkill(character[charIndex].magtree, "BLIZZARD");
        strcat(combatText, " LEARNED BLIZZARD!");
        character[charIndex].atk *= 1.03;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("BLIZZARD");
    }

    else if(character[charIndex].Level == 9)
    {
        learnSkill(character[charIndex].magtree, "EARTH SMASH");
        strcat(combatText, " LEARNED EARTH SMASH!");
        character[charIndex].def *= 1.03;
        character[charIndex].learnedSpells += 1;
        character[charIndex].spellIndices[character[charIndex].learnedSpells-1] = returnSpellIndex("EARTH SMASH");
    }

    else if(character[charIndex].Level == 10)
    {
        learnSkill(character[charIndex].phystree, "INT BOOST");
        strcat(combatText, " LEARNED INT BOOST!");
        character[charIndex].inte *= 1.25;
        character[charIndex].learnedSkills += 1;
    }

    renderMainPartyStats(COMBAT_ACTIONS, combatText);
    moveCursorUpBy(10);
    limitFPS(1500);
}


// TODO: Also make this commonize all area BGs later on
void renderArea1BG(int animTime) 
{
    for(unsigned char y = 0; y <37; y++)
    {
        unsigned char xmax = strlen(Area1_BG[y]);

        for(unsigned char x = 0; x < xmax; x++)
        {
            applyColorPalette(Area1_BG[y][x]);

            putchar(Area1_BG[y][x]);
        }
        putchar('\n');
        if(animTime != 0) { limitFPS(animTime*2); }
    }
    textcolor(WHITE);
    textbackground(BLACK);
    moveCursorUpBy(BG_YSIZE-FIGHTSCREEN_Y_PADDING);
}

void renderEnemyCombatStat()
{
    char lifepercent; // enemy life bar percentage calculus.
    SetColor(WHITE);
    useBoldConsoleText();
    printf("\t\t\t┌────────────────────────────────────────────────────────────────────────────────┐\n");

    // Enemy Names
    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        if(enemyIndex == 0) { printf("\t\t\t│"); }
        // If there's only one enemy, show its name and lifebar on the center
        if(enemiesInEncounter == 1) 
        { 
            for(char j = 0; j < 26; j++) { putchar(' '); }
            printf("│");
        } 
        
        for(char j = 0; j < (26 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }

        if(Enemy[enemyIndex].current_HP <= 0) 
        { 
            SetColor(DARKGRAY);
            useStrikeThroughConsoleText();
        }
        else { SetColor(YELLOW); }
        printf("%s", Enemy[enemyIndex].name);

        restoreConsoleText();
        useBoldConsoleText();

        for(char j = 0; j < (26 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }
        if(strlen(Enemy[enemyIndex].name) % 2 == 1) { putchar(' '); } // Correction for when names aren't even in length
        SetColor(WHITE);
        printf("│");

        // If we have two enemies, the center area of the life bars has to be empty (there's only a left and right enemy)
        // Additionally, if there's only one enemy, its stats will be shown on the center, so pad the right area as well.
        if(enemiesInEncounter % 2 == 0 && enemyIndex == 0 || enemiesInEncounter == 1) 
        { 
            for(unsigned char j = 0; j < 26; j++) { putchar(' '); } 
            printf("│");
        }
    }
    printf("\n");

    // Enemy HP Bars
    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        if(enemyIndex == 0) { printf("\t\t\t│"); }

        if(enemiesInEncounter == 1) 
        { 
            for(unsigned char j = 0; j < 26; j++) { putchar(' '); }
            printf("│");
        } 
        printf(" HP:(");
        lifepercent = (char) (((float)Enemy[enemyIndex].current_HP / (float)Enemy[enemyIndex].max_HP) * 18);
        if(lifepercent < 0) { lifepercent = 0; } 

        restoreConsoleText();
        textbackground(RED);
        textcolor(RED);
        for(unsigned char i = 0; i < lifepercent; i++) { printf("+"); }
        useBoldConsoleText();
        textbackground(BLACK);
        textcolor(WHITE);

        for(unsigned char i = 20 - lifepercent - 2; i > 0; i--) { printf(" "); }

        printf(")  │");
        if(enemiesInEncounter % 2 == 0 && enemyIndex == 0 || enemiesInEncounter == 1) 
        { 
            for(unsigned char j = 0; j < 26; j++) { putchar(' '); } 
            printf("│");
        }
    }
    printf("\n");

    
    printf("\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n");
    restoreConsoleText();
}

unsigned char selectEnemy() 
{
    char selIndex = 0;

    bool enemyIsSelectable[3] = { false, false, false };

    // Start by having all generated enemies be selectable. If any have their HP below zero, they'll be ruled out below
    for(unsigned char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) { enemyIsSelectable[enemyIndex] = true; }

    while(true) 
    {
        renderMainPartyStats(COMBAT_ACTIONS, "");
        SetColor(WHITE);
        useBoldConsoleText();
        printf("\t\t\t┌────────────────────────────────SELECT YOUR FOE─────────────────────────────────┐\n");

        // Enemy Names
        for(unsigned char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
        {
            if(enemyIndex == 0) { printf("\t\t\t│"); }
            // If there's only one enemy, show its name and lifebar on the center
            if(enemiesInEncounter == 1) 
            { 
                for(unsigned char j = 0; j < 26; j++) { putchar(' '); }
                printf("│");
            }

            if(Enemy[enemyIndex].current_HP <= 0) 
            {
                enemyIsSelectable[enemyIndex] = false;
                if(enemyIsSelectable[selIndex] == false) { selIndex++; }
            }
            
            if (selIndex == enemyIndex) 
            { 
                SetColor(YELLOW);
                printf(" ┼─ "); 
                useUnderlineConsoleText();
            }
            else { printf("    "); }
            for(unsigned char j = 0; j < (22 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }
            
            if(Enemy[enemyIndex].current_HP <= 0) 
            { 
                SetColor(DARKGRAY); 
                useStrikeThroughConsoleText(); 
            }
            printf("%s", Enemy[enemyIndex].name); 

            restoreConsoleText();
            useBoldConsoleText();

            for(unsigned char j = 0; j < (22 - strlen(Enemy[enemyIndex].name))/2; j++) { putchar(' '); }
            if(strlen(Enemy[enemyIndex].name) % 2 == 1) { putchar(' '); } // Correction for when names aren't even in length
            SetColor(WHITE);
            printf("│");

            if(enemiesInEncounter % 2 == 0 && enemyIndex == 0 || enemiesInEncounter == 1) 
            { 
                for(unsigned char j = 0; j < 26; j++) { putchar(' '); } 
                printf("│");
            }
        }
        useBoldConsoleText();
        printf("\n");
        printf("\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n\n");
        restoreConsoleText();
        moveCursorUpBy(14);

        while(true)
        {
            if(GetAsyncKeyState (VK_A) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                selIndex--;
                if(enemyIsSelectable[selIndex] == false) { selIndex--; }
                if(selIndex < 0) { selIndex = enemiesInEncounter-1; }
                break;
            }

            if(GetAsyncKeyState (VK_D) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                selIndex++;
                if(enemyIsSelectable[selIndex] == false) { selIndex++; }
                if(selIndex >= enemiesInEncounter) { selIndex = 0; }
                break;
            }

            if(GetAsyncKeyState (VK_ENTER) != 0)
            {
                playSFX("CombatCursorSelect");
                limitFPS(150);
                return selIndex;
            }

            if(GetAsyncKeyState (VK_BACKSPACE) != 0)
            {
                playSFX("ReturnFromMenu");
                return -1;
            }
            limitFPS(0);
        }
    }
}

unsigned char renderPlayerCombatEnemyMenu(bool runEnabled)
{
    bool atksel = true;
    bool spellsel = false;
    bool actsel = false; // TODO: Unused, as AP skills aren't implemented yet
    bool undosel = false; // TODO: Unused, as there has to be more than one character in the party
    bool runsel = false; // TODO: Unused, as running from battles should be tied to some mechanic
    char enemyAttacked = -1;
    unsigned char curCharacter = 0; // Only one character for now

    while(true)
    {
        renderMainPartyStats(COMBAT_ACTIONS, "");

        SetColor(WHITE);
        useBoldConsoleText();
        printf("\t\t\t┌────────────────────────────────────────────────────────────────────────────────┐\n");
        printf("\t\t\t┌──────────────────────────────SELECT YOUR COMMAND───────────────────────────────┐\n");
        printf("\t\t\t│ ");
        if(atksel) { SetColor(LIGHTGREEN); }
        printf("%s", (atksel ? "┼─" : "  "));
        printf(" BASIC ATTACK   ");
        SetColor(WHITE);
        printf("│ ");
        if(spellsel) { SetColor(LIGHTBLUE); }
        printf("%s", (spellsel ? "┼─" : "  "));
        printf(" MAGIC SPELL   ");
        SetColor(WHITE);
        printf("│ ");
        if(actsel) { SetColor(YELLOW); }
        printf("%s", (actsel ? "┼─" : "  "));
        printf(" CLASS SKILL   ");
        SetColor(WHITE);
        printf("│ ");
        if(undosel) { SetColor(LIGHTCYAN); }
        else if(curCharacter == 0) { SetColor(DARKGRAY); }
        printf("%s", (undosel ? "┼─" : "  "));
        printf(" UNDO   ");
        SetColor(WHITE);
        printf("│");
        if(runsel) { SetColor(BROWN); }
        printf("%s", (runsel ? "┼─" : "  "));
        printf(" FLEE   ");
        SetColor(WHITE);
        printf("│");
        printf("\n\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n");
        restoreConsoleText();
        moveCursorUpBy(14);

        while(true)
        {
            if(GetAsyncKeyState (VK_A) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                if(atksel)
                {
                    atksel = false;
                    
                    if (runEnabled)
                        runsel = true;
                    else if (curCharacter != 0)
                        undosel = true;
                    else
                        actsel = true;
                }
                else if(spellsel)
                {
                    spellsel = false;
                    atksel = true;
                }
                else if(actsel)
                {
                    actsel = false;
                    spellsel = true;
                }
                else if(actsel)
                {
                    actsel = false;
                    spellsel = true;
                }
                else if(undosel)
                {
                    undosel = false;
                    actsel = true;
                }
                else if(runsel)
                {
                    runsel = false;
                    if (curCharacter != 0)
                        undosel = true;
                    else
                        actsel = true;
                }
                break;
            }

            if(GetAsyncKeyState (VK_D) != 0)
            {
                limitFPS(150);
                playSFX("CombatCursorMove");
                if(atksel)
                {
                    atksel = false;
                    spellsel = true;
                }
                else if(spellsel)
                {
                    spellsel = false;
                    actsel = true;
                }
                else if(actsel)
                {
                    actsel = false;

                    if (curCharacter != 0)
                        undosel = true;
                    else if (runEnabled)
                        runsel = true;
                    else
                        atksel = true;
                }
                else if(undosel)
                {
                    undosel = false;
                    runsel = true;
                }
                else if(runsel)
                {
                    runsel = false;
                    atksel = true;
                }
                break;
            }

            if(GetAsyncKeyState (VK_ENTER) != 0)
            {
                playSFX("CombatCursorSelect");
                if(atksel)
                {
                    enemyAttacked = selectEnemy();
                    if(enemyAttacked != -1) 
                    {
                        strcpy(character[0].action,"ATK");
                        playerAttackEnemy(enemyAttacked);
                        return enemyAttacked;
                    }
                    
                }
                else if(spellsel)
                {
                    enemyAttacked = renderPlayerMagicSpellMenu();
                    if(enemyAttacked != -1) { return enemyAttacked; }
                }
                // TODO: Class Skill
                else if(actsel)
                {
                    enemyAttacked = renderPlayerMagicSpellMenu();
                    if(enemyAttacked != -1) { return enemyAttacked; }
                }
                else if(undosel)
                {
                    // TODO: We only have one player now, no undoing of actions.
                }
                else if(runsel)
                {
                    return tryEscape(curCharacter) ? PARTY_ESCAPED : enemyAttacked;
                }
                limitFPS(250);
                break;
            }
            limitFPS(0);
        }
    }
    return -1; // This should never happen
}

// Party UI in combat
void renderMainPartyStats(bool showCombatActions, char *combatText)
{
    char charAt = 0;
    SetColor(WHITE);
    useBoldConsoleText();

    if(showCombatActions) 
    {
        printf("%s\t┌────────────────────────────────────────────────────────────────────────────────┐\n", (showCombatActions ? "\t\t" : "\t "));
        printf("%s\t│ %s", (showCombatActions ? "\t\t" : "\t "), combatText);
        for(unsigned char pad = 0; pad < COMBAT_TEXT_MAXLEN - strlen(combatText); pad++) { printf(" "); }
        printf("│\n");
        printf("%s\t└────────────────────────────────────────────────────────────────────────────────┘\n", (showCombatActions ? "\t\t" : "\t "));

    }
    
    printf("%s\t┌───────────────┬────────────────┬────────────────┬────────────────┬─────────────┐\n", (showCombatActions ? "\t\t" : "\t "));
    
    // Names
    for(unsigned char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        SetColor(WHITE);
        if(i == 0) { printf("%s\t│ ", (showCombatActions ? "\t\t" : "\t ")); }
        if(i < partySize) 
        {
            charAt = 0;
            while(character[i].name[charAt] != '\0') 
            { 
                putchar(character[i].name[charAt]); 
                charAt++; 
            }
            for(unsigned char i = 14 - (charAt+1); i > 0; i--) { printf(" "); }
        }
        else { printf(" ──────────────"); }
        SetColor(WHITE);
        printf(" │");
    }
    printf(" KEY ACTIONS │");
    
    printf("\n");

    SetColor(WHITE);
    printf("%s\t├───────────────┼────────────────┼────────────────┼────────────────┼─────────────┤\n", (showCombatActions ? "\t\t" : "\t "));

    // HP Stats
    for(unsigned char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        if(i == 0) { printf("%s\t│", (showCombatActions ? "\t\t" : "\t ")); }

        SetColor(LIGHTGREEN);
        if(i < partySize)  { printf(" HP: %4d/%4d ",character[i].current_HP, character[i].max_HP); }
        else { printf(" ────────────── "); }
        SetColor(WHITE);
        printf("│");
    }
    printf(" WASD - MOVE │");
    printf("\n");

    // MP Stats
    for(unsigned char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        if(i == 0) { printf("%s\t│", (showCombatActions ? "\t\t" : "\t ")); }
        
        SetColor(LIGHTBLUE);
        if(i < partySize)  { printf(" MP: %4d/%4d ",character[i].current_MP, character[i].max_MP); }
        else { printf(" ────────────── "); }
        SetColor(WHITE);
        printf("│");
    }
    if(showCombatActions) { printf(" ENTER - ACT │"); }
    else { printf("ENTER - ITEMS│"); }
    printf("\n");

    // AP Stats
    for(unsigned char i = 0; i < MAX_PARTY_SIZE; i++) 
    {
        if(i == 0) { printf("%s\t│", (showCombatActions ? "\t\t" : "\t ")); }
        
        SetColor(YELLOW);
        if(i < partySize)  { printf(" AP: %3d/%d   ", 0, 100); } // character[0].current_AP, character[0].max_AP); // AP not implemented yetcharacter[i].current_AP, character[i].max_AP); }
        else { printf(" ────────────── "); }
        SetColor(WHITE);
        printf("│");
    }
    if(showCombatActions) { printf(" BKSP - UNDO │"); }
    else { printf("BKSP - SKILLS│"); }
    printf("\n");

    
    printf("%s\t└──────%s──────┴────────────────┴────────────────┴────────────────┴─────────────┘\n", (showCombatActions ? "\t\t" : "\t "), (strcmp(character[0].action, "") != 0 ? character[0].action : "───"));
    restoreConsoleText();
}

unsigned char renderPlayerMagicSpellMenu()
{
    unsigned char spellsel = 0;
    unsigned char enemyIndex = 0;

    while(true)
    {
        renderMainPartyStats(COMBAT_ACTIONS, "");
        SetColor(WHITE);
        useBoldConsoleText();
        printf("\t\t\t┌────────────────────────────────SELECT THE SPELL────────────────────────────────┐\n");

        for(unsigned char spellIdx = 0; spellIdx < MAGIC_SPELLS_PER_LINE*2; spellIdx++) 
        {
            if(spellIdx == 0) { printf("\t\t\t│"); }
            if(spellIdx == 4) { printf("\n\t\t\t│");  } // 4 magic spells per line (will be the same for class skils)
            
            if(!findSkill(character[0].magtree, availableSpells[character[0].spellIndices[spellIdx]])) 
            { 
                if(spellIdx != 3 && spellIdx != 7) { printf("                   "); } // Last indices of a row need to be 1 space longer
                else { printf("                    "); }
            }
            else 
            {
                if(spellsel == spellIdx) 
                { 
                    SetColor(LIGHTGREEN);
                    printf(" ┼─");
                    useUnderlineConsoleText();
                }
                else { printf("   "); }
                
                printf(" %s", availableSpells[character[0].spellIndices[spellIdx]]);

                restoreConsoleText();
                useBoldConsoleText();

                if(spellIdx != 3 && spellIdx != 7) // Same for padding, last indices of a row need to be 1 space longer
                { 
                    for(unsigned char pad = 0; pad < 15-strlen(availableSpells[character[0].spellIndices[spellIdx]]); pad++) { putchar(' '); }
                }
                else 
                {
                    for(unsigned char pad = 0; pad < 16-strlen(availableSpells[character[0].spellIndices[spellIdx]]); pad++) { putchar(' '); } 
                }
            }
        
            SetColor(WHITE);
            printf("│");
        }
        

        // TODO: We can have up to 8 spells here, there's just not that many yet

        printf("\n\t\t\t└────────────────────────────────────────────────────────────────────────────────┘\n");
        restoreConsoleText();
        moveCursorUpBy(14);
        
        while(true)
        {
            if(character[0].learnedSpells > 0) // Only move the cursor of there's any spell to select
            {
                if(GetAsyncKeyState (VK_W) != 0)
                {
                    if(spellsel > 3 && character[0].learnedSpells > 4) 
                    {
                        playSFX("CombatCursorMove");
                        spellsel -= MAGIC_SPELLS_PER_LINE; 
                        limitFPS(150);
                        break;
                    }
                }

                if(GetAsyncKeyState (VK_S) != 0)
                {
                    if(spellsel < 4 && character[0].learnedSpells > 4) 
                    {
                        playSFX("CombatCursorMove");
                        spellsel += MAGIC_SPELLS_PER_LINE;
                        limitFPS(150);
                        break;
                    }
                }

                if(GetAsyncKeyState (VK_A) != 0)
                {
                    if(spellsel > 0) 
                    { 
                        playSFX("CombatCursorMove");
                        spellsel -= 1; 
                        limitFPS(150);
                        break;
                    }
                }

                if(GetAsyncKeyState (VK_D) != 0)
                {
                    if(spellsel < (character[0].learnedSpells-1)) 
                    {
                        playSFX("CombatCursorMove");
                        spellsel += 1; 
                        limitFPS(150);
                        break;
                    }
                }
            }
            

            if(GetAsyncKeyState (VK_ENTER) != 0)
            {
                // Only select spells if there are any available, and it doesn't require more MP than available
                if(character[0].learnedSpells == 0 && character[0].current_MP < findSkillMPUsage(character[0].magtree, availableSpells[character[0].spellIndices[spellsel]])) 
                {
                    playSFX("ReturnFromMenu");
                    break; 
                }
                limitFPS(150);
                playSFX("CombatCursorSelect");
                enemyIndex = selectEnemy();
                if(enemyIndex == -1) { limitFPS(150); break; }

                strcpy(character[0].action,"MAG");            
                
                playerUseSpell(availableSpells[character[0].spellIndices[spellsel]], enemyIndex);
                return enemyIndex;
            }

            if(GetAsyncKeyState (VK_BACKSPACE) != 0)
            {
                playSFX("ReturnFromMenu");
                return -1;
            }

        }
    }

}

unsigned char playerAttackEnemy(unsigned char enemyIndex)
{
    short int damage = (character[0].atk - Enemy[enemyIndex].def);
    char combatText[COMBAT_TEXT_MAXLEN];
    bool gotCriticalHit = calculateCriticalHitChance(character[0].luck);

    if(gotCriticalHit) 
    { 
        damage *= 1.5;
        playSFX("CriticalHit");
    }
    else { playSFX("HitConfirm"); }

    if(damage > 0)
    {
        Enemy[enemyIndex].current_HP -= damage;
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s attacks... %s causes %d damage to '%s'.", character[0].name, (gotCriticalHit ? "CRITICAL HIT!!!" : "and"), damage, Enemy[enemyIndex].name);
        renderMainPartyStats(COMBAT_ACTIONS, combatText);
        moveCursorUpBy(10);
        limitFPS(1000);
    }
}

bool calculateCriticalHitChance(unsigned short int luck) 
{
    float luckStat = (float)(luck - 100) / (999 - 100);
    float criticalHitChance = 0.025f + (luckStat * (0.325f - 0.025f));

    //printf("crit:%f", criticalHitChance);

    if (criticalHitChance < 0) { criticalHitChance = 0; }
    if (criticalHitChance > 0.3f) { criticalHitChance = 0.3f; }

    float scoredCriticalHit = (float)rand() / RAND_MAX;

    return scoredCriticalHit < criticalHitChance;
}

// TODO: These should also be commonized. Tons of duplicated code...
bool playerUseSpell(char *spell, unsigned char enemyIndex)
{
    short int damage = (character[0].atk - Enemy[enemyIndex].def);
    char combatText[COMBAT_TEXT_MAXLEN];

    damage *= (character[0].inte/100);

    if(strcmp(Enemy[enemyIndex].weakness, spell) == 0) damage *= 2;
    else if (strcmp(Enemy[enemyIndex].resists, spell) == 0) damage *= 0.7;

    if(damage > 0)
    {
        playSFX(spell);
        Enemy[enemyIndex].current_HP -= damage;
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s used %s... and caused %d damage to '%s'.", character[0].name, spell, damage, Enemy[enemyIndex].name);
        renderMainPartyStats(COMBAT_ACTIONS, combatText);
        moveCursorUpBy(10);
        limitFPS(1000);
    }

    character[0].current_MP -= findSkillMPUsage(character[0].magtree, spell);

    return true;
}

bool tryEscape(int charIndex)
{
    int value = rand() % 500;
    int success = (character[charIndex].luck + character[charIndex].spd) -
    (enemiesInEncounter * 50);
    char combatText[COMBAT_TEXT_MAXLEN];

    if(value < success)
    {
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "The party escaped!!!");
        playSFX("PartyEscaped");
    }
    else
    {
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "Escape failed...");
        playSFX("PlayerHit");
    }

    renderMainPartyStats(COMBAT_ACTIONS, combatText);
    moveCursorUpBy(10);
    limitFPS(1000);

    return (value < success);
}

// TODO: Attacking party characters, though we need more than a party member for that
void enemyAttackPlayer(unsigned char enemyIndex, unsigned char charIndex)
{
    short int damage = (Enemy[enemyIndex].atk - character[charIndex].def);
    char combatText[COMBAT_TEXT_MAXLEN];

    playSFX("PlayerHit");
    if(damage > 0)
    {
        character[charIndex].current_HP -= damage;
        snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s attacks... it caused %d damage to '%s'.", Enemy[enemyIndex].name, damage, character[charIndex].name);
        renderMainPartyStats(COMBAT_ACTIONS, combatText);
        moveCursorUpBy(10);
        limitFPS(1000);
    }
}

void enemyDozesOff(unsigned char enemyIndex)
{
    char combatText[COMBAT_TEXT_MAXLEN];
    snprintf(combatText, COMBAT_TEXT_MAXLEN, "%s enemy dozed off...", Enemy[enemyIndex].name);
    renderMainPartyStats(COMBAT_ACTIONS, combatText);
    moveCursorUpBy(10);
    limitFPS(1000);
}

void enemyAction()
{
    for(char enemyIndex = 0; enemyIndex < enemiesInEncounter; enemyIndex++) 
    {
        if(Enemy[enemyIndex].current_HP > 0) 
        {
            unsigned char randaction = rand() % 100;
            if(randaction <= 75) { enemyAttackPlayer(enemyIndex, 0); }
            else { enemyDozesOff(enemyIndex); }
        }
    }
}
