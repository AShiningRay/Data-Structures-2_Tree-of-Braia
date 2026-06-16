#define NUM_ENEMIES 6 // Current amount of normal enemies
#define NUM_BOSSES 3 // Current amount of bosses

char (*enemySprites[NUM_ENEMIES+NUM_BOSSES])[127];
int enemySpriteRows[NUM_ENEMIES+NUM_BOSSES];

int enemyWidth[] = {32, 32, 64, 64, 64, 127, 127, 127};

char enemyPosition[] = {24, 64, 104};

char combat_yellowBlob[30][127] =
{
"              ........          ",
"           ...KKKKKKKK..        ",
"         ..KKKKKKKKKKKKK.       ",
"   ..   .KKKKKK000KKKKLKK.      ",
"  .KK. .KKKKK0.....0KKK000.     ",
"   .. .KK@@KK@0.MM.0KK0.M.0.    ",
"      .@@@@KKKK0000KKKK000.  .  ",
"    ..@@@@@@@KKKKKKK@K@@@.  .@. ",
"   .@@@@@@@@@@KKKK@KKKKKK. .K.  ",
"  .@@@@@@@@0@@KKK@@@KK@@KK. .   ",
" .K@00@@@@000@@KK@@@@K@@KKK.    ",
" .KK@@@@@@@KK@@@@@@@@@@@KKKK.   ",
"  .KKK@@@@@@@00@@@00@@@@0@K@.   ",
"  ...KKKK@@@@K0@@@@@@@@@....    ",
" .....KKKKKKKKK@@@KKKKK.....    ",
"  .........................     ",
};

char combat_redBlob[30][127] =
{
"              ........          ",
"           ...RRRRRRRR..        ",
"         ..RRRRRRRRRMMMR.       ",
"   ..   .RRRRRR000RRRMRRR.      ",
"  .MM. .RRRRR0.....0RRR000.     ",
"   .. .MRLLRRL0.MM.0RR0.M.0.    ",
"      .LLLLRRRR0000RRRR000.  .  ",
"    ..LLL0L0LRMMRRRRLRL0L.  .L. ",
"   .LLLLLLL0LLRMMRLRRRRRR. .M.  ",
"  .LLLLLLL000LRRRLLLRRLLMM. .   ",
" .ML000LLL000LLRRLLLLRLLMMM.    ",
" .MRLLLL0LLRR0LLLL0LLLLLRMMM.   ",
"  .MMRLL00000000LL000LLL00ML.   ",
"  ...MMRRL00LR00LLLL0LLL....    ",
" .....MMMMMMRRRLLLRRRRR.....    ",
"  .........................     ",
};

char combat_cursArmor[30][127] =
{
"                                          		 WWWWWWWG",
"                                                       WWWGLGWWWWG",
"                                                       WWGRWRGWWWG",
"                                                       WWGRWRGWWWG",
"                                                       WWGRWRGWWG",
"                                                       WWGRRRGWW",
"",
"                                               WWWWWWWWWWWWWWWWWWWGGWGWWWG",
"                                          W  DWWWWWWWWWWWWWWWWWWWWWWWWWWWD   GG",
"                                        DWWWDD   WWWWWWWWWWWWWWWWWWWWWW D  D WRGG",
"                                      GWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWRWDDWWWWWWRGG",
"                                    DWWWWWWWWW WWWWWWWWWWWWWWWWWWWWWWWWWG  DWWWWWWRGG",
"                                   WWWWWWWWW    WWWWWWWWWWWWWWWWWWWWWWG      DWWWWWWRGG",
"                                 WWWWWWWWW         WWWWWWWWWWWWWWWWWG          DWWWWWWWWWWGG",
"                                DWWWWWWWD          WWWWWWWWWWWWWWWWWG            DWWWWWD LWW",
"                             WWWWWGWWWD  WG        DWWWWWWWWWWWWWWWWG              GWWWWG",
"                            WWW  WWWWWW W          RDWWWWWWWWWWWWWWWG              GWG  WW",
"                               GWWG WWWWWWWW BBBBB WWWWWWWWWWWWWWWWGG BBBBBBBBBBBB    WWW",
"                              BBBBBB  W WWWWRRRL    LLRRRRRRRRRRGGG  BBBBBBBBBBBBBBBBB",
"                           BBBBBBBBBB D      LRRRRRL      L  R   R                  BBBBBBBB",
"                         BBBBBB                    LRRRRL      L                          BBBBBB",
"                        BBB                            LRRRL    R                             BB",
"                        BB                                                                    BB",
"                        BBBBB                                                             BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_CGuy[30][127] =
{
"  	                                            WWWWWWWWWWWWWWW",
"                                             WW###WWWWWWWWW###WW",
"                                            W######WWWWWWW######WW",
"                                           W########WWWWW########WW",
"                                          WW########WWW###########WW",
"                                         #####   *###WW####*  #####W",
"                                         ######_  ###WWW##   _#####W",
"                                         W##########WWWWW##########WW",
"                                         WW########WWWWWWW########WWW",
"                                          WWWW#####WWWWWWWWW#####WWWW",
"                                          WWWWWWWWWWWWWWWWWWWWWWWWWWW",
"                                          WWWWW=##############=WWWWW",
"                                            WWW#################WWW",
"                                             WW###***********###WW",
"                               BBBBBBBBBBBBBB  W*WWWWWWWWWWWWWWW*WBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBB            WWWWWWWWWWWWWWW           BBBBBBBBBBBB",
"                        BBBBB                      WWWWWWWWWWW                     BBBBBBB",
"                        BBBBB                        WWWWWW                             BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_BChicken[30][127] =
{
"                                           #WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#",
"                                          #WWWWWW_##_WWWWWWWWWWWWW_##_WWWWW#",
"                             ####         #WWWWWW*##*WWWWWWWWWWWWW*##*WWWWWW#       ####",
"                          ###   ###      ##WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW#       ###  ###",
"                        ###       ###     ##WWWWWWWW#####***#####WWWWWWW##      ###      ###",
"                      ###          ###     ##WWWWWW##WWWWWWWWWWW##WWWWWW#     ###           ###",
"                                     ###     ##WWWWWWWWWWWWWWWWWWWWWWW##    ###",
"                                       ####### *#######################*######",
"                                               @@@@@@@@@@@@@@@@@@@@@@@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                                               @@@@                 @@@@",
"                               BBBBBBBBBBBBBBBB@@@@BBBBBBBBBBBBBBBBB@@@@*BBBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBB   @@@@                 @@@@         BBBBBBBBBBBBBBB",
"                        BBBBB              @@@@    @@@@         @@@@    @@@@                BBBBBBB",
"                        BBBBB                  @@@@                 @@@@                     BBBBBB",
"                         BBBBBBBBBBB                                                  BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_Cyclops[30][127] =
{
"                                                     #############",
"                                                   ##################",
"                                                 ######################",
"                                                #######################",
"                                                ########.......########",
"                                                #######...(%)...########",
"                                                #######.........#######",
"                                                 #######.......#######",
"                                                &&&&&&&&&&&&&&&&&&&&&&&&&&",
"                                                 &&&&&&&&&     &&&&&&&&&",
"                                                &&&&&&&&&&&&&&&&&&&&&&&&&&",
"                                                       WWWWWWWWWWWW",
"                                                      WWWWWWWWWWWWWW",
"                                                    WWWWWWWWWWWWWWWWWW",
"                                                    WWWW          WWWW",
"                                                    WWWW          WWWW",
"                                                    WWWWWWWWWWWWWWWWWW",
"                                                    WWWWWWWWWWWWWWWWWW",
"                               BBBBBBBBBBBBBBBBBBBBBWWWWBBBBBBBBBWWWWWBBBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBBBB     WWWW         WWWW      BBBBBBBBBBBBBBBBB",
"                        BBBBB                       WWWW         WWWW                   BBBBBBB",
"                        BBBBB                       WWWW          WWWW                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_Noname[30][127] =
{
"                                                     WWWWWNNNWWWWWWW",
"                                                   WWWWOOOOOOOOOOOWWWW",
"                                                 WWWWOOOOOOOOOOOOOOOOWWWW",
"                                               WWWWOOOOOOOOOOOOOOOOOOOWWWW",
"                                              WWWWOOOOOOOOOOOOOOOOOOOOOOWWWW",
"                                             WWWWOOOOOOOOOOOOOOOOOOOOOOOOWWWW",
"                                             WWWWOOOOOOOOOOOOOOOOOOOOOOOOWWWW",
"                                              WWWWWWOOOOOOOOOOOOOOOOOOOWWWWW",
"                                                WWWW  ################ WWWW",
"                                              WWWWWWWW   WWWWWWWW  WWWWWWWWWW",
"                                             WWWW000000000000000000000000NNWWW",
"                                            WWWWW0000000:........:000000WWWWWWW",
"                                            WWWWNNNNNNN::________::NNNNNNNWWWWW",
"                                         WWWW*******************************WWWW",
"                                          WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"                               BBBBBBBBBBBBBBBBBBBBBWWWWBBBBBBBBBWWWWBBBBBBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBBB      WWWW         WWWW        BBBBBBBBBBBBBBB",
"                        BBBBB                       WWWW         WWWW                   BBBBBBB",
"                        BBBBB                       WWWW          WWWW                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_AlienV[30][127] =
{
"                 ##########                                                                ##########",
"                   ##########                         ##########                        ##########",
"                      ##########                   ####################              ##########",
"                         ##########           ##########          ##########       ##########",
"                           ##########      ##########                ##########  ##########",
"                              ##########   ##########  LLLLLLLLLLL  ########## ##########",
"                                 ##########             LLLLLLLLL            ##########",
"                                   ##########            LLLLLL           ##########",
"                                     ##########            LL           ##########",
"                                       ##########                     ##########",
"                                          ##########                ##########",
"                               BBBBBBBBBBBB##########BBBBBBBBBBBBB##########BBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBB #########        ##########       BBBBBBBBBBBBBBB",
"                        BBBBB                   #######################                   BBBBBBB",
"                        BBBBB                     ####################                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

char combat_BigO[30][127] =
{
"                                     ||                   ######                  ||",
"                                      ||            ##############               ||",
"                                       ||         ######################        ||",
"                                        ||    ##########          #########    ||",
"                                         ##########                ############",
"                                       #########                      ##########",
"                                       #########                       ##########",
"                                                &&&&&&&&&&&&&&&&&&&&&&&",
"                                      ##########                       ##########",
"                                       ##########                     ##########",
"                                         ##########                ##########",
"                               BBBBBBBBBBBB##########BBBBBBBBBBBBB##########BBBBBBBBBBBBBB",
"                          BBBBBBBBBBBBBBBBBBB #########        ##########       BBBBBBBBBBBBBBB",
"                        BBBBB                   #######################                   BBBBBBB",
"                        BBBBB                     ####################                     BBBBBB",
"                         BBBBBBBBBBB                                               BBBBBBBBBBBB",
"                            BBBBBBBBBBBBBBBBBBBBB                BBBBBBBBBBBBBBBBBBBBBBBB",
"                                 BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"                                          BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};

void initEnemies() 
{
    enemySprites[0] = combat_yellowBlob;   enemySpriteRows[0] = (int) (sizeof(combat_yellowBlob) / sizeof(combat_yellowBlob[0]));
    enemySprites[1] = combat_redBlob;      enemySpriteRows[1] = (int) (sizeof(combat_redBlob) / sizeof(combat_redBlob[0]));
    enemySprites[2] = combat_CGuy;         enemySpriteRows[2] = (int) (sizeof(combat_CGuy) / sizeof(combat_CGuy[0]));
    enemySprites[3] = combat_BChicken;     enemySpriteRows[3] = (int) (sizeof(combat_BChicken) / sizeof(combat_BChicken[0]));
    enemySprites[4] = combat_AlienV;       enemySpriteRows[4] = (int) (sizeof(combat_AlienV) / sizeof(combat_AlienV[0]));
    enemySprites[5] = combat_BigO;         enemySpriteRows[5] = (int) (sizeof(combat_BigO) / sizeof(combat_BigO[0]));

    // Bosses are at the end
    enemySprites[6] = combat_cursArmor;    enemySpriteRows[6] = (int) (sizeof(combat_cursArmor) / sizeof(combat_cursArmor[0]));
    enemySprites[7] = combat_Cyclops;      enemySpriteRows[7] = (int) (sizeof(combat_Cyclops) / sizeof(combat_Cyclops[0]));
    enemySprites[8] = combat_Noname;       enemySpriteRows[8] = (int) (sizeof(combat_Noname) / sizeof(combat_Noname[0]));
}