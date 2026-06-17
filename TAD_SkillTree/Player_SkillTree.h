#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../Game/Console_Colors/Colors.h"

#define NUM_SPELLS 9
#define NUM_SKILLS 9

char availableSpells[NUM_SPELLS][15] = 
{
    "AQUA STORM",
    "BLIZZARD",
    "WIND GUST",
    "EARTH SMASH",
    "SCORCH FLAME",
    "NULL",
    "NULL",
    "NULL",
    "NULL" // This one shall always be null
};

/* char availableSkills[][15] = 
{
    TODO
}; */

struct Node
{
    char skillName[20];
    bool isLearned;
    unsigned short int MPused;
    struct Node *left, *right;
};

typedef struct Node* BinTree;

BinTree* generate_BinTree();
void insertMagSkills(BinTree* tree);
void insertPhysSkills(BinTree* tree);
int insert_Node(BinTree* root, char skillname[], unsigned short int MPused);
void free_BinTree(BinTree *root);
int insert_BinTree(BinTree* root, char skillname[]);
void learnSkill(BinTree *root, char* skilltolearn);
bool findSkill(BinTree *root, char* skilltofind);
unsigned short int findSkillMPUsage(BinTree *root, char* skilltofind);
void print_skillTree(BinTree* root, int spacing);

BinTree* generate_BinTree()
{
    BinTree* root = (BinTree*) malloc(sizeof(BinTree));
    if(root != NULL)
        *root = NULL;

    return root;
}

int returnSpellIndex(char *spellName) 
{
    for(int i = 0; i < NUM_SPELLS-1; i++) 
    {
        if(strcmp(availableSpells[i], spellName) == 0) { return i; }
    }
    return -1; // Shouldn't happen
}

void insertMagSkills(BinTree* tree)
{
    insert_Node(tree, "MAGICAL", 0);

    insert_Node(tree, "SCORCH FLAME", 70);
    insert_Node(tree, "BLIZZARD", 60);
    insert_Node(tree, "INT BOOST", 0);
    insert_Node(tree, "WIND GUST", 50);
    insert_Node(tree, "EARTH SMASH", 80);
    insert_Node(tree, "AQUA STORM", 30);
}

void insertPhysSkills(BinTree* tree)
{
    insert_Node(tree, "PHYSICAL", 0);

    insert_Node(tree, "DEF BOOST", 0);
    insert_Node(tree, "STR BOOST", 0);
}

int insert_Node(BinTree* root, char skillname[20], unsigned short int MPused)
{
    if(root == NULL)
        return 0;

    struct Node* newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL)
        return 0;
    strcpy(newNode->skillName, skillname);
    newNode->isLearned = false;
    newNode->MPused = MPused;
    newNode->right = NULL;
    newNode->left = NULL;

    if(*root == NULL)
        {
            newNode->isLearned = true;
            *root = newNode;
        }

    else{
        struct Node* currentNode = *root;
        struct Node* previousNode = NULL;
        while(currentNode != NULL){
            previousNode = currentNode;
            if(skillname[0] == currentNode->skillName[0]) // If the Element already exists, free it.
                {
                free(newNode);
                return 0;
                }
            if(skillname[0] > currentNode->skillName[0])
                currentNode = currentNode->right;
            else
                currentNode = currentNode->left;
        }
        if(skillname[0] > previousNode->skillName[0])
            previousNode->right = newNode;
        else
            previousNode->left = newNode;
    }
    return 1;
}

void freeNode(struct Node* node)
{
    if(node == NULL)
        return;
    freeNode(node->left);
    freeNode(node->right);
    free(node);
    node = NULL;
}

void free_BinTree(BinTree* root)
{
    if(root == NULL) {return;} 
    freeNode(*root); // Frees each of the Tree's nodes.
    free(root); // Frees the root itself (generates a "incompatible pointer" warning)
    printf("\nThe tree has been freed\n");
}

void learnSkill(BinTree *root, char* skilltolearn)
{
    if(*root != NULL)
    {
        if(strcmp(skilltolearn, (*root)->skillName) == 0) { (*root)->isLearned = true; }

        if(&((*root)->left) != NULL) { learnSkill(&((*root)->left), skilltolearn); }
        if(&((*root)->right) != NULL) { learnSkill(&((*root)->right), skilltolearn); }
    }
}

bool findSkill(BinTree *root, char* skilltofind)
{
    if (*root == NULL) {
        return false;
    }

    if (strcmp(skilltofind, (*root)->skillName) == 0 && (*root)->isLearned) { return true; }

    return findSkill(&((*root)->left), skilltofind) || findSkill(&((*root)->right), skilltofind);
}

unsigned short int findSkillMPUsage(BinTree *root, char* skilltofind)
{
    if (*root == NULL) {
        return 65535;
    }

    if (strcmp(skilltofind, (*root)->skillName) == 0) {
        return (*root)->MPused;
    }

    unsigned short int leftUsage = findSkillMPUsage(&((*root)->left), skilltofind);
    if (leftUsage != 65535) {
        return leftUsage;
    }

    return findSkillMPUsage(&((*root)->right), skilltofind);
}

void print_skillTree(BinTree* root, int spacing)
{
    if (*root == NULL) { return; }
    // Increase distance between levels
    spacing += 7;

    // Process right child first
    print_skillTree(&(*root)->right, spacing);
    // Print current node after space
    // count
    if((*root)->isLearned == true) textcolor(LIGHTGREEN);

    for (int i = 7; i < spacing; i++)
        {
            if(i < spacing - (7-3))printf(" ");
            else printf("-");
        }
    printf("(%s)\n\n", (*root)->skillName);
    textcolor(WHITE);

    // Process left child
    print_skillTree(&(*root)->left, spacing);
}

