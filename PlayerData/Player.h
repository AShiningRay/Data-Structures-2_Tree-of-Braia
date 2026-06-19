#include "../TAD_SkillTree/Player_SkillTree.h"

#define MAX_PARTY_SIZE 4
#define MAX_NAME_SIZE 15

unsigned char partySize = 0;

typedef struct items
{
    unsigned char HPpotion;
    unsigned char MPpotion;
    unsigned char HPinc;
    unsigned char MPinc;
}items;

struct playerChar
{
    char name[MAX_NAME_SIZE];
    unsigned char Level; // Level will max out at 100.
    unsigned short int gold;
    short int max_HP;
    short int current_HP;
    short int max_MP;
    short int current_MP;
    unsigned short int atk;
    unsigned short int def;
    unsigned short int inte;
    unsigned short int luck;
    unsigned short int spd;
    bool key;
    unsigned short int current_XP;
    unsigned short int next_XP;
    BinTree* magtree;
    BinTree* phystree;
    items it;
    unsigned char learnedSpells; // It'll be impossible for a character to know more than 8 magic spells, or class skills
    unsigned char spellIndices[NUM_SPELLS-1];
    unsigned char learnedSkills;
    unsigned char skillIndices[NUM_SKILLS-1];

    // Combat-specific fields
    char action[4];
}character[4];

void createPlayer(unsigned char charIndex, char charName[MAX_NAME_SIZE]);

void insertCharName(unsigned char charIndex, struct winsize *ws)
{
    char ch;
    char name[MAX_NAME_SIZE];
    unsigned char index = 0;
    clearConsoleScreen();
    useBoldConsoleText();
    useItalicConsoleText();
    
    if(ws->ws_row > 6)
        moveCursorDownBy(ws->ws_row / 2 - 3);

    int indent = (ws->ws_col > 34) ? (ws->ws_col / 2 - 17) : 0;
    
    printCenteredScreen(indent, "┌───────────────────────────────┐\n");
    if (charIndex == 0)
        printCenteredScreen(indent, "│ WHAT'S YOUR CHARACTER'S NAME? │\n");
    else
        printCenteredScreen(indent, "│ WHAT'S THAT CHARACTER'S NAME? │\n");
    printCenteredScreen(indent, "├───────────────────────────────┤\n");
    printCenteredScreen(indent, "└────────┬─────────────┬────────┘\n");
    printCenteredScreen(indent+9, "│             │\n");
    printCenteredScreen(indent+9, "└─────────────┘");
    moveCursorUpBy(1);
    moveCursorLeftBy(14);

    // Read input character by character
    while (true)
    {
        ch = getchar();
    
        // If it's an invalid character, skip it
        if(ch < 0)
        {
            continue;
        }

        // Check if we read a newline or EOF, and finish reading the name.
        if (ch == '\n' || ch == EOF)
        {
            break;
        }

        // Backspace? Clear last char
        if((ch == '\b' || ch == 127) && index > 0)
        {
            moveCursorLeftBy(1);
            name[--index] = ' ';
            printf(" ");
            moveCursorLeftBy(1);
        }
        // Store the character in the buffer if it's not a backspace, and we
        // aren't at the end of the buffer.
        else if (ch > 31 && ch < 127 && index < sizeof(name) - 2)
        {
            printf("%c", ch);
            name[index++] = ch;
        }
    }

    textcolor(WHITE);
    textbackground(BLACK);
    restoreConsoleText();

    name[index] = '\0'; // Null-terminate the string
    createPlayer(charIndex, name);
}

void createPlayer(unsigned char charIndex, char charName[MAX_NAME_SIZE])
{
    character[charIndex].magtree = generate_BinTree();
    character[charIndex].phystree = generate_BinTree();
    insertMagSkills(character[charIndex].magtree);
    insertPhysSkills(character[charIndex].phystree);
    strcpy(character[charIndex].name, charName);

    character[charIndex].Level = 1;
    character[charIndex].gold = 0;
    character[charIndex].max_HP = 1050; // Base 1050
    character[charIndex].current_HP = 1050; // Base 1050
    character[charIndex].max_MP = 110; // Base 110
    character[charIndex].current_MP = 110; // Base 110
    character[charIndex].atk = 112; // Base 112
    character[charIndex].def = 122; // Base 122
    character[charIndex].inte = 102; // Base 102
    character[charIndex].luck = 67; // Base 115
    character[charIndex].spd = 75; // Base 75
    character[charIndex].current_XP = 0;
    character[charIndex].next_XP = 100;
    character[charIndex].key = false;
    character[charIndex].it.HPpotion = 0;
    character[charIndex].it.HPinc = 0;
    character[charIndex].it.MPpotion = 0;
    character[charIndex].it.MPinc = 0;

    character[charIndex].learnedSpells = 0;
    for(unsigned char i = 0; i < NUM_SPELLS-1; i++) 
    {
        character[charIndex].spellIndices[i] = NUM_SPELLS-1;
    }
    
    character[charIndex].learnedSkills = 0;
    for(unsigned char i = 0; i < NUM_SKILLS; i++) 
    {
        character[charIndex].skillIndices[i] = NUM_SKILLS-1;
    }

    strcpy(character[charIndex].action,"");

    if(partySize < MAX_PARTY_SIZE) { partySize++; } // Party will be a max of 4 characters, for UI tracking
}
