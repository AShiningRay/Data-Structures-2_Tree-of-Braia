#define HUBTOWN_NAVAREAS 10 // TBF
#define AREA1_NAVAREAS 10 // TBF
#define AREA1INT_NAVAREAS 0 // TODO
#define AREA2_NAVAREAS 0 // TODO

#define NAVAREA_YSIZE 42
#define NAVAREA_XSIZE 101

// ######################################### Ending and Title Screen (maybe some cutscenes later)


char Title_BG[48][128] =
{
"................................................#.&....#.#..##&##..#..##..#####................................................",
".......................................&.....&.###........&...#&.K#K##KKKK#.####&...#..##K.....................................",
".................................#...&..&...&##K##.#.....###K....###KK####K#KKKKK#####...KK#..#....#...........................",
".................................................##.KKK####KK#K#K.&.....&.KK#K#########KKK&...&K&..&...........................",
"..........................#K##.......#.......#KKKK...###K####K#&#...#........#KK#&&#&###....K#K#.##............................",
".....................&&&###K...&.#&&#K##KK#######K&KK#####K####K####&.&&##&&...#####&####.#####&#.&.&..........................",
"......................K###K....#KK####K##########&KK#K################K##KKKKK&#KKK#####K#&#####K#K&.....##....................",
"...................#K##KK.K....#KK#K###KK####&K##KK#K####K&K###K###&###K###K.KKK#K#####&K#&#K####KK#####.##K#K.................",
".................&K#&K..K#K&KK.#.KK#.#.KK..K###########.########&##.#####KKK##KKKKK######KK#K#KK##KK##K#K#K###&##&.&..&........",
"............&&&...#####KK####K##K#######..&K###.##K#.#...KKK..KK..K####K##&#K&KK##&.K####K##K######K&#K&####KKK.##K#KK.&&......",
"...........&&####&#KK###K#KK.&##...############...#K#.&.....&..KK##...&########KK#K#&#&#K####K##KKK##K#K#...K#####KKK#.........",
".........#####.K#.##K&..&.#..####.#.####.###&....KKK#K&K.###..&K#.....&.&#&K#########KKK###KKK#K###KK##KK###..K#######&#.&&....",
"........&###.#.KKKK#.##&######.&.#.######&#K.KK#######.##...&&#K&&&......K##&#.#.####&#&#&&##########K###&###K#K#K#K&##KK......",
".........##...K##.#.#...#.&.##...&KK.K.K###..KKKK#K#KK#.K..&..###..&..&..#&&#@@..K##&@@@@#K&#K##K#KK#######K##.K#K.##K.###.....",
"............##K&&&......&.K#KK##K####K##K##.##K###K#.K..K....&&.##....&...KK#..######K##&#..K.##&##KK###K########K##.##........",
"......&&&##K&KK##&...&&#K##KK###KKK##&#KK#K#KK#&##KK.&K#K..#...&&#...&.&..K&##&&#&##&#&#..K.K#.&..###.K#&#&#K######KK#.#.......",
"......#.######K###KKK######K#KKK###@@@@@K@@@@@@@@@@@&K&.K.&....@@##K&&...&&&@.@#..#.K@.K&&&.K..@@@@..#&@@#@@@@@KK@KKKKK#.#.....",
"....#&..##K@@&@K##K###K###K##KKK@K#####K@&@@@&&&@@@&KK.......####K.###.K@#@#K..@..###&@.#.KK@@@&@@&&&&@..##@##@@##@@&KK#KKK##.#",
"..K&..###@@#@@#&@####K#KK###&@#K@K#@@@KKK##K@@&##@@@@.&.....&..&#KK###K##K#...&...@#K@@K&&.@@@@@@...#.&..#&&&@@@&&&@KK@@#K#KK@#",
"..#.##K##K#K#K@@K#@@KK@K@KK@KK&#.##&K#@K@####&...@@@K@.&..........########&........@@@@@@@@@@KK##.#&@.@#@@###&K##K@#######@@.@K",
"##.K#KKK#K##@#K@&&&K&@@@@@@@@@@..#.@..&#@@...@@@@@@@&@.&.......#@..@K@@@K...&&.#K#K##K&@@.#.##..#.&&##..@###KK#@@..@..@#@@K&#KK",
"##K#@K#@@##@K#@#@@@@@@@@@@@@@@@@@@@@@@@@@@&&&&@#@@@@@@@.........KK@@@@@K.&.K#..###@#K####..&&.&.@@@@@.K#.#&#@K@@..&#...###KK##@",
"&&K#K@@KK@#KKK@@@@@@#K#...K#.##@@@@@@@@@@@@@@@@@@@@@@@&&@..@...&&K@@@@@@@&..&.&KK@K@#K##K##.#.#K@####KKK.####....&...&...&..#K&",
"K#K@K@&.&#KK#@@@@&&@#K..#.##.##&&@@@@@@@#@.@@@@@@@@@@@@@@@&##....&@@@@@#.....#@@@@@@@@@#&#&#@@@#@&&@K#KKK#KK.K.K........#&.....",
"@@.KK..@##K#@@@@#@#########&.@@@@K#K#K.&.K&........K@@@@@@@@....K@@@@@@...&@@@@@@@###.#&&@@#@@@@@&#@&K&##@KK##.K#..............",
".......#@#K@@@#.......####@@####.###&#.KKK@&@@&@@@&@KK@@@@@@@@.@@@@@@@@..@@@@@@@.##@K@@@@@@@@@#@....&#@@#@@@KK###KKK&&.K@......",
"......@@#@@@&###K#K##K#K@&.&##KK#..&...&K@@&#.....@&@@@@@@@@@@@@@@@@@@@K@@@@@@....K@@@@&.K#K####K.&....&&@@.@@@@KKKK#K#KK@.....",
"......K#K#K#KK#.########..#K#K###&@@@@@@@K.....&......@@@@@@@@@@@@@@@@@@@@@@@....#@@@@@#@#@@K######.....#....@@##@#KK@K#K#.&...",
"......K##K#&K....###KK#KKKKK&@@&@@@&..&.&&K.@#..........@@@@@@@@@@@@@@@@@@@@@....&@@@@@@@@@@&@#@#&@......&....K&##@@@@#K@@##...",
".......@.&.#....#KKK#K@@@@@@@##.#.###@.&.@&K##....K##.#K##@@@@@@@@@@@@@@@@@@&@@@@@@@@@@@@@@@@@@@@K#..K.....&...#&#K#@##K@##K#..",
"............#&KKK#KKK#@#@@@@#&##...&K...K@@@#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@###&@@##@#@@@@######.&#&.##.#K&##K&KKKK#&.",
"............&KK#K#K@K..@@........&..@#@K##.K.&.#K.&#..@@@@@@@@@@@@@@@@@@@@@@@@@@@@&#..K#..&@.@##&&@@@@@@KK&#@.K#...............",
"..........&&##.KKKKKKK.@#.....&..@&.#...@#..&&..@###.#.@@@@@@@@@@@@@@@@@@@@@@@@@@####......&.#@##.#####@&##@##&.#&.............",
"..............#@###.@##.@#...#.#@&@..@......&..#&@@.....@@@@@@@@@@@@@@@@@@@@@..#....@......&@@#.&.....&K@@######...............",
"..............#@.&#................&..&..................@@@@@@@@@@@@@@@@@@@.....&#.&.&........@&......&#@#K#KK................",
"..........................................................@@@@@@@@@@@@@@@@@@.....&.................#&#&&#K#KK@K&...............",
".........................................................@@@@@@@@@@.@@@@@@@@.............................#.KK.K@...............",
".........................................................@.@@@.@@@...@@@@@@@..................................K................",
".........................................................@@@@@@@@.....@@@@@@...................................................",
"........................................................@.@@@@@@@@....@@@@@@@..................................................",
"........................................................@.@@@@@@@.....@@@@@@@@.................................................",
".......................................................@@@@@@@@.........@@@@@@@@...............................................",
".....................................................@@@@@@@@....@@..@...@@@@@@@@@@............................................",
"...................................................@@@@@@@..@@@@@@@@@@@@@@@@@@@@@@@@@@.........................................",
".............................................@.@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.......................................",
"..........................@@@@.@.@.@@@@@@@@@.@@@@@@@@@@..@@@@@@@@..@@@@@@@@@@@@@@@@@@@@@@@@@.@@@..@.......@.@..................",
"...@..@@@.@@@@@...@@@@@@@@@@@@@@@@.@.@@.@..@.@....@.@@@.@@...@@..@@@@@..@.@@@@@@@@.@@.@@@.@@@@@@@@@@.@@@@@..@@@@@@@.@...@@.....",
"........@.@@..@@.@@.@@@@@@@.@@@@@..@@@@@@@@@@@@@@@@@@@@@@@.@@@@@@@@@@...@@@@@@@@.@.@.@@...@@@@@@@@@@@@@@@@@@@...@@@@.@.@@.@....",
};

// Yes, this looks weird, it's because the backslash has to be escaped (basically \ becomes \\)
char Title[29][128] = 
{
". /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    /\\\\\\\\\\\\\\\\\\      /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  .                                                    ",
". \\///////\\\\\\/////   /\\\\\\///////\\\\\\   \\/\\\\\\///////////  \\/\\\\\\///////////  .                                                    ",
" .       \\/\\\\\\       \\/\\\\\\     \\/\\\\\\   \\/\\\\\\             \\/\\\\\\           .                                                     ",
"   .      \\/\\\\\\       \\/\\\\\\\\\\\\\\\\\\\\\\/    \\/\\\\\\\\\\\\\\\\\\\\\\     \\/\\\\\\\\\\\\\\\\\\\\\\   .                                                    ",
"     .     \\/\\\\\\       \\/\\\\\\//////\\\\\\    \\/\\\\\\///////      \\/\\\\\\///////      .                                                 ",
"       .    \\/\\\\\\       \\/\\\\\\    \\//\\\\\\   \\/\\\\\\             \\/\\\\\\           .                                                  ",
"        .    \\/\\\\\\       \\/\\\\\\     \\//\\\\\\  \\/\\\\\\             \\/\\\\\\            .                                                ",
"         .    \\/\\\\\\       \\/\\\\\\      \\//\\\\\\ \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ .                                              ",
"                                  .   /\\\\\\\\\\       /\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ ///////////  .                                             ",
"                                 .   /\\\\\\///\\\\\\    \\/\\\\\\///////////            .                                               ",
"                                .   /\\\\\\/  \\///\\\\\\  \\/\\\\\\             .                                                        ",
"                                .   /\\\\\\      \\//\\\\\\ \\/\\\\\\\\\\\\\\\\\\\\\\  .                                                          ",
"                                .   \\/\\\\\\       \\/\\\\\\ \\/\\\\\\///////  .                                                          ",
"                                 .   \\//\\\\\\      /\\\\\\  \\/\\\\\\       .                                                           ",
"                                  .    \\///\\\\\\  /\\\\\\    \\/\\\\\\    .                                                             ",
"                               .         \\\\///\\\\\\\\\\/     \\/\\\\\\     .                                                           ",
"                             .   /\\\\\\\\\\\\\\\\\\\\\\\\\\      /\\\\\\\\\\\\\\\\\\         /\\\\\\\\\\\\\\\\\\     /\\\\\\\\\\\\\\\\\\\\\\     /\\\\\\\\\\\\\\\\\\   .         ",
"                              .  \\/\\\\\\/////////\\\\\\  /\\\\\\///////\\\\\\     /\\\\\\\\\\\\\\\\\\\\\\\\\\  \\/////\\\\\\///    /\\\\\\\\\\\\\\\\\\\\\\\\\\  .       ",
"                               .  \\/\\\\\\       \\/\\\\\\ \\/\\\\\\     \\/\\\\\\    /\\\\\\/////////\\\\\\     \\/\\\\\\      /\\\\\\/////////\\\\\\  .     ",
"                                .  \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\  \\/\\\\\\\\\\\\\\\\\\\\\\/    \\/\\\\\\       \\/\\\\\\     \\/\\\\\\     \\/\\\\\\       \\/\\\\\\  .    ",
"                                 .  \\/\\\\\\/////////\\\\\\ \\/\\\\\\//////\\\\\\    \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\     \\/\\\\\\     \\/\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  .   ",
"                                  .  \\/\\\\\\       \\/\\\\\\ \\/\\\\\\    \\//\\\\\\   \\/\\\\\\/////////\\\\\\     \\/\\\\\\     \\/\\\\\\/////////\\\\\\  .  ",
"                                   .  \\/\\\\\\       \\/\\\\\\ \\/\\\\\\     \\//\\\\\\  \\/\\\\\\       \\/\\\\\\     \\/\\\\\\     \\/\\\\\\       \\/\\\\\\  . ",
"                                    .  \\/\\\\\\\\\\\\\\\\\\\\\\\\\\/  \\/\\\\\\      \\//\\\\\\ \\/\\\\\\       \\/\\\\\\  /\\\\\\\\\\\\\\\\\\\\\\ \\/\\\\\\       \\/\\\\\\  .",
"                                     .  \\/////////////    \\///        \\///  \\///        \\///  \\///////////  \\///        \\///  .",
"                                                                                         . ___  ______  ______   __ ______  .  ",
"                                                                                        . / _ \\/ __/  |/  / _ | / //_/ __/ .   ",
"                                                                                       . / , _/ _// /|_/ / __ |/ ,< / _/  .    ",
"                                                                                      . /_/|_/___/_/  /_/_/ |_/_/|_/___/ .     ",
};

// How it should look like:
/*char Title[30][128] = 
{
". /\\\\\\\\\\\\\\\    /\\\\\\\\\      /\\\\\\\\\\\\\\\  /\\\\\\\\\\\\\\\  |                                                    ",
". \///////\\\/////   /\\\///////\\\   \/\\\///////////  \/\\\///////////  |                                                    ",
" .       \/\\\       \/\\\     \/\\\   \/\\\             \/\\\           |                                                     ",
"   .      \/\\\       \/\\\\\\\\\\\/    \/\\\\\\\\\\\     \/\\\\\\\\\\\   |                                                    ",
"     .     \/\\\       \/\\\//////\\\    \/\\\///////      \/\\\///////      |                                                 ",
"       .    \/\\\       \/\\\    \//\\\   \/\\\             \/\\\           |                                                  ",
"        .    \/\\\       \/\\\     \//\\\  \/\\\             \/\\\            |                                                ",
"         .    \/\\\       \/\\\      \//\\\ \/\\\\\\\\\\\\\\\ \/\\\\\\\\\\\\\\\ |                                              ",
"            .                         /\\\\\       /\\\\\\\\\\\\\\\ ///////////  |                                             ",
"                                 .   /\\\///\\\    \/\\\///////////            |                                               ",
"                                .   /\\\/  \///\\\  \/\\\             |                                                        ",
"                                .   /\\\      \//\\\ \/\\\\\\\\\\\  |                                                          ",
"                                .   \/\\\       \/\\\ \/\\\///////  |                                                          ",
"                                 .   \//\\\      /\\\  \/\\\       |                                                           ",
"                                  .    \///\\\  /\\\    \/\\\    |                                                             ",
"                              .          \\///\\\\\/     \/\\\                                                      |          ",
"                             .   /\\\\\\\\\\\\\      /\\\\\\\\\         /\\\\\\\\\     /\\\\\\\\\\\     /\\\\\\\\\   |         ",
"                              .  \/\\\/////////\\\  /\\\///////\\\     /\\\\\\\\\\\\\  \/////\\\///    /\\\\\\\\\\\\\  |       ",
"                               .  \/\\\       \/\\\ \/\\\     \/\\\    /\\\/////////\\\     \/\\\      /\\\/////////\\\  |     ",
"                                .  \/\\\\\\\\\\\\\\  \/\\\\\\\\\\\/    \/\\\       \/\\\     \/\\\     \/\\\       \/\\\  |    ",
"                                 .  \/\\\/////////\\\ \/\\\//////\\\    \/\\\\\\\\\\\\\\\     \/\\\     \/\\\\\\\\\\\\\\\  |   ",
"                                  .  \/\\\       \/\\\ \/\\\    \//\\\   \/\\\/////////\\\     \/\\\     \/\\\/////////\\\  |  ",
"                                   .  \/\\\       \/\\\ \/\\\     \//\\\  \/\\\       \/\\\     \/\\\     \/\\\       \/\\\  | ",
"                                    .  \/\\\\\\\\\\\\\/  \/\\\      \//\\\ \/\\\       \/\\\  /\\\\\\\\\\\ \/\\\       \/\\\  |",
"                                     .  \/////////////    \///        \///  \///        \///  \///////////  \///        \///  |",
"                                                                                         . ___  ______  ______   __ ______  |  ",
"                                                                                        . / _ \/ __/  |/  / _ | / //_/ __/ |   ",
"                                                                                       . / , _/ _// /|_/ / __ |/ ,< / _/  |    ",
"                                                                                      . /_/|_/___/_/  /_/_/ |_/_/|_/___/ |     ",
};*/


char pressCtrl[5][128] = 
{
"                      ____  ____  ________________    _  _______   __________________ _    __     ",
"                     / __ \\/ __ \\/ ____/ ___/ ___/   ( )/ ____/ | / /_  __/ ____/ __ ( )  / /     ",
"                    / /_/ / /_/ / __/  \\__ \\\\__ \\    |// __/ /  |/ / / / / __/ / /_/ //  / /       ",
"                   / ____/ _, _/ /___ ___/ /__/ /     / /___/ /|  / / / / /___/ _, _/   /_/         ",
"                  /_/   /_/ |_/_____//____/____/     /_____/_/ |_/ /_/ /_____/_/ |_|   (_)           ",
};

char Credits[80][60] =
{
"",
"",
"",
"",
"               DEVELOPED BY BRAIA SOFTWORKS",
"",
"",
"",
"                      LEAD DEVELOPERS",
"",
"             Paulo Sousa      Game Designer                ",
"           Matheus Rondon      Game Designer               ",
"                                                           ",
"                           WRITING                         ",
"",
"            Kaio Nascimento    Main Writer                 ",
"            Paulo Sousa        Secondary Writer            ", ///////
"            Matheus Rondon     Secondary Writer            ",
"",
"                           ART",
"",
"           Matheus Rondon      Lead Artist                 ",
"            Paulo Sousa       Secondary Artist             ",
"           Wisley Kilder      Secondary Artist             ",
"                                                           ",
"                       PROGRAMMING",
"",
"            Paulo Sousa       Lead Programmer              ",
"            Matheus Rondon   Secondary Programmer          ",
"",
"                         TESTING",
"                                   ",
"             Tulio Estrela      Main playthrough tester    ",
"             Wisley Kilder      Main gameplay tester       ",
"             Kaio Nascimento    Secondary gameplay tester  ",
"",
"                    SOUND ENGINEERING",
"                                   ",
"             Paulo Sousa    Main Sound Developer     ",
"             Matheus Rondon    Secondary Sound Developer   ",
"             Matheus Rondon    Audio Engineer",
"",
"                    TAD DEVELOPMENT",
"                                   ",
"             Paulo Sousa    Main TAD Developer     ",
"             Matheus Rondon    Secondary TAD Developer    ",
"             Tulio Estrela   Main TAD Tester",
"             Kaio Nascimento Secondary TAD Tester",
};

// ######################################### Actual Game Areas

char (*navAreas[HUBTOWN_NAVAREAS + AREA1_NAVAREAS + AREA1INT_NAVAREAS + AREA2_NAVAREAS])[101];

unsigned char numNavAreas[NUM_AREAS];

char HubTown_Nav1[][101] = 
{
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBVBBBBBBBWWWWW0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVBBBBVBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBVWWWWWWWWWWWWW$BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVVVVBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BVBBBVVVVVBBVVVWWWWWWWWWWWW0WWWVVVVVVVVBVVVVBVVBVBBVVVVBVVVBBVVV$WWWWWWWVVVVVBBBVBBVVVVBVVVVVVBBBBVVV",
"VVVVVVVVVVVVVVWWWWWWWWWWWWWWWWWWWWWVVVVVVVVVVVVVVVV00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVW0W0WWWW0WWWWWWWWWWWWWVVVVVVVVVVV0WWWWWWWWVVVVVVVVVVVVVVVVVVVVV0WWWW0VVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVWWWW0WWWWWWWWWWWWW00W0WWW0VVVVVVVVVV00WWWWWWWW0VVVVVVVVVVVVVVVVVVWWWWWWWWWWWVVVVVVVVVVVVVV",
"VVVVVVWWWWWWWWWWWWWWWW0000WWWWWWWWWWWWWWWVVV00WWWWWW00WW0VVWWVVVVVVVV0WWWWWWWW0W0WWW0WWW0WWWWWVVVVVVV",
"0VVWWW00V00W00V0W0WW0VVVVV0WWWWW00WWVV0WW0VV000WWWWWWWWWWWWWWWW00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWW0WWWWWWWWWWWWWWWVVVVVVVVVVVVVVVVWVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVV0WWWWVVVVVVVVWWWWWWWWWWWW00WWWWWWWWWW0WWW0WW00VVVVVV0WWWWWWW00WWVVVVVVVVVVV",
"WWWWWVVVVVVVVVVVWWWWW0VVV00WWWWWWWVV0VW0VVVVVVVVVVVV00WWWWW0VWWVVVVVVVVVVVVV0WWWWWWWWWWWWWWWWWWVVWVVV",
"0000000VVVVV0WW0WWWWWWW000WWWWWWWWWVVVVVVVVVVV0WWV000WWWWWWWWWW0VVVVVVVVVWWWWWWW0WWWWW0W0V00WW0WW00VV",
"WVVVV0VVVVWW0WWWWWWWWWWW00WWWWWWWWWWWWWVVVVV00V0VVVV00WWWWWW0WWWWVVVVVVVVVVV0WWW0WWW0W00VVV00VWW0VVVV",
"WWV0VCCV@C$#WV000WWWWWWWWWV0W0WWWWWWWW0W0WVWWWWWWWW0V0VVV00WWWWW0WWWWW0W0000V$V0W0VV00VVWV$WW0WW$C$00",
"WV$$$C##C#CVVC$V00VVVVVWV0W0V0V0000000WW00WWWWWWWW0WVVVVV0WW0W0000W000WWW00#CVVVVVVVVWWW0VCV0WVVCVCVV",
"##CC#CCCCV#VVV#VWVVCCV00VVW0WV#VWVV0WWWWWWW000VVVVV0WWWWW0WWWW0VVVVV000V00C##C#WVVV#CCVWVC##VVVVC#CCV",
"##VCC#CCCC##CCC#VVVC@C##V##CVCCCVVVWCVV00W000V0VVVVV0VVVVVVVVVW0VVCCVVV#VV#CCCC#VVVCC##CC#C##VCCCCCC#",
"#V#$#CC#C#$CC$#$$#$#CC##CC$##CC#$CC#CVVVWVVWVVVVVWVVVVW0VVWVCCVCCV#C#VC#V$$#CCCC$#CCC##$#CCC$$CC$#CCC",
"##C#$CC#C#C$$CC$#$#CCC#CCC##$##CCCCCCC####$##$######$#$C$######C$$$C###C$CCCCC#C$###C##CC#CCCC#C#CCCC",
"#CCC$#C##C####$#$CC#CC#CCCC#C#CC#C#C#CCC#C#C###CC###CCCC###CCC#CCCCC#CCC#CCCCCC##C#CCC$#CCCC##CCC$CCC",
"CC#CC#$###CC$#CC##CCCCCCC#C#C##CC#CCCC#C#C#C####CC#C#C#C#####C##C$##CCCCC#$$#CC#CCCCCCCCCCC#CCC#C#C#C",
"##CC###C$$C####CCC##CC##CCC#$#C##C&&&KKK&##CCCCCCCCC##CC#CC#C#C####CCC#CC##CC#CCC#CCC#CCC#$$##CCCC#CC",
"CCCCC##C#CC$##CC$$$#CC&C&&&&&&K&&&&&&&&&&&&&&&&&&&&K&&&&K&KKK&&KKKKKK&KKKK&&&CCCCCCC###$$$####$CC#C#C",
"####CCC##C#CC#$$C&&&&&&&&&&&&KK&&KKKKKKKKKKK&&&&&&&&&&KKK&&&K&&&&&&&&&&&&&K&&&&&&&&&&&&&CC$$$$$$$CC$$",
"C##CCCCCC###C####$#CCC&&&&&&&&&&&&&&&&&&0&&&KKKKKKKKKK&&W&&&&&&&&&&&&&K&&&&&&W&&&&&&&&&&CCC$$##$#$###",
"#$$$$$$##$###C###CCCCCC&CC&&&&&&&&&K&&&&&&&&&&&&&&&&&K&&KKKKK&K&&&&&&&&K&&&&&KKKKKK&K&&&&&&&&&&&&&C&C",
"########$$#####CKKCCC&&&&&CC##CCCC&&&&&&&K&&K&&&&&&&000&&&&&&&KKKKKKKKK&KK&K&&&&KKKK&&&&&&&&&&&&&&&&C",
"$$$$##C##C###CCCCC&&&KKKK.&&&&&&CCC&&&C&&&&&&&&&&&&&&&&&KKKKKKK&&&&&&&CC&#$C&&&&&&&&&&&&&&&&&&&&&&&&C",
"$$$$$$$$$$########$##$$$$$$#####CC&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&KKKC&CC#CCCCCC",
"#####$$$$$$$#####$##CCC#$$$$$$$$$#C&&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&K&&&&&&&&&&&&&KKCK#$$$CC#CCC#C#",
"########$$$$$#$#$$#$C#CC$C$######CCCCC#$#$CC&&&&+0+&&&&&&&&&&&&&&&&&&&&&&&&&&&&CCC#CC#$$#CCCC$$$#&CC#",
"##CC#C#C########$$$$###############CC#CCCCCCCC&K000C&C&&&&&&&&&&&&&&&&&00&&&CCCCC#C####$$$$#CC#CC&C##",
"#C#C#####C####$####$$#$++++++$$##$####CCC#CCCCCC00CCC&&C&&C&&&&&&&&&&C&&CCCCCCC#CC++++++CCCCCCCC####$",
"#C#########C#C######$+++0000++$###########C##C##CCCCCCCCCCC#####C####CCCCCC&CC&&&0000000&&KC#########",
"C#C###C######C######+000000000$$$$#$#$#$###&C$##C$#C#CCCC&C&&CCC###CK&CCCCCC&C#C000000&&&&$$C########",
"CCC#C######C###C#C#.00000000000$$$$$$$$$##CCC##C##C#C#CC##CC#CCCC##CCCCCCCC&CCC#CCCCCCC++++CCC#$$###$",
"##C#############CC....&&C&C$#$###$#$$$#$$$$$##CCC#####CCCCC&C###$#C######C&#C$#CCCCCC#++000CCCC######",
"C##C###C#C#CC####$#$$$$$$CC$$$#########$$$$$$$####$##CCC##CC#C##CC#############$####$+00000.$$$#C###$",
"CCCC###C##C#C##########$$$$$##$#C##$$#$$$$$$$$$##########CCCCCC##CCC#######C##CC##C#++00000..##$$#$$$",
"CCCCCC#C+#####C#CCCC++++C#CC@CC#######$$$$$$$$$$$#CCCCC##CCC############CC######$$$$$#$$$$#$$###$$##$",
"0CC0CCC00C0#CCCCCCC@@@@@@CC###C####C########$$$$$$$$$$$$$$$$##$$$$$$$$$$$#$#$$$###$###$###C#C####C$CC",
};

char HubTown_Nav2[][101] = 
{
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBVBBBBBBBWWWWW0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVBBBBVBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBVWWWWWWWWWWWWW$BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVVVVBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BVBBBVVVVVBBVVVWWWWWWWWWWWW0WWWVVVVVVVVBVVVVBVVBVBBVVVVBVVVBBVVV$WWWWWWWVVVVVBBBVBBVVVVBVVVVVVBBBBVVV",
"VVVVVVVVVVVVVVWWWWWWWWWWWWWWWWWWWWWVVVVVVVVVVVVVVVV00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVW0W0WWWW0WWWWWWWWWWWWWVVVVVVVVVVV0WWWWWWWWVVVVVVVVVVVVVVVVVVVVV0WWWW0VVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVWWWW0WWWWWWWWWWWWW00W0WWW0VVVVVVVVVV00WWWWWWWW0VVVVVVVVVVVVVVVVVVWWWWWWWWWWWVVVVVVVVVVVVVV",
"VVVVVVWWWWWWWWWWWWWWWW0000WWWWWWWWWWWWWWWVVV00WWWWWW00WW0VVWWVVVVVVVV0WWWWWWWW0W0WWW0WWW0WWWWWVVVVVVV",
"0VVWWW00V00W00V0W0WW0VVVVV0WWWWW00WWVV0WW0VV000WWWWWWWWWWWWWWWW00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWW0WWWWWWWWWWWWWWWVVVVVVVVVVVVVVVVWVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVV0WWWWVVVVVVVVWWWWWWWWWWWW00WWWWWWWWWW0WWW0WW00VVVVVV0WWWWWWW00WWVVVVVVVVVVV",
"WWWWWVVVVVVVVVVVWWWWW0VVV00WWWWWWWVV0VW0VVVVVVVVVVVV00WWWWW0VWWVVVVVVVVVVVVV0WWWWWWWWWWWWWWWWWWVVWVVV",
"0000000VVVVV0WW0WWWWWWW000WWWWWWWWWVVVVVVVVVVV0WWV000WWWWWWWWWW0VVVVVVVVVWWWWWWW0WWWWW0W0V00WW0WW00VV",
"WVVVV0VVVVWW0WWWWWWWWWWW00WWWWWWWWWWWWWVVVVV00V0VVVV00WWWWWW0WWWWVVVVVVVVVVV0WWW0WWW0W00VVV00VWW0VVVV",
"WWV0VCCV@C$#WV000WWWWWWWWWV0W0WWWWWWWW0W0WVWWWWWWWW0V0VVV00WWWWW0WWWWW0W0000V$V0W0VV00VVWV$WW0WW$C$00",
"WV$$$C##C#CVVC$V00VVVVVWV0W0V0V0000000WW00WWWWWWWW0WVVVVV0WW0W0000W000WWW00#CVVVVVVVVWWW0VCV0WVVCVCVV",
"##CC#CCCCV#VVV#VWVVCCV00VVW0WV#VWVV0WWWWWWW000VVVVV0WWWWW0WWWW0VVVVV000V00C##C#WVVV#CCVWVC##VVVVC#CCV",
"##VCC#CCCC##CCC#VVVC@C##V##CVCCCVVVWCVV00W000V0VVVVV0VVVVVVVVVW0VVCCVVV#VV#CCCC#VVVCC##CC#C##VCCCCCC#",
"#V#$#CC#C#$CC$#$$#$#CC##CC$##CC#$CC#CVVVWVVWVVVVVWVVVVW0VVWVCCVCCV#C#VC#V$$#CCCC$#CCC##$#CCC$$CC$#CCC",
"##C#$CC#C#C$$CC$#$#CCC#CCC##$##CCCCCCC####$##$######$#$C$######C$$$C###C$CCCCC#C$###C##CC#CCCC#C#CCCC",
"#CCC$#C##C####$#$CC#CC#CCCC#C#CC#C#C#CCC#C#C###CC###CCCC###CCC#CCCCC#CCC#CCCCCC##C#CCC$#CCCC##CCC$CCC",
"CC#CC#$###CC$#CC##CCCCCCC#C#C##CC#CCCC#C#C#C####CC#C#C#C#####C##C$##CCCCC#$$#CC#CCCCCCCCCCC#CCC#C#C#C",
"##CC###C$$C####CCC##CC##CCC#$#C##C&&&KKK&##CCCCCCCCC##CC#CC#C#C####CCC#CC##CC#CCC#CCC#CCC#$$##CCCC#CC",
"CCCCC##C#CC$##CC$$$#CC&C&&&&&&K&&&&&&&&&&&&&&&&&&&&K&&&&K&KKK&&KKKKKK&KKKK&&&CCCCCCC###$$$####$CC#C#C",
"####CCC##C#CC#$$C&&&&&&&&&&&&KK&&KKKKKKKKKKK&&&&&&&&&&KKK&&&K&&&&&&&&&&&&&K&&&&&&&&&&&&&CC$$$$$$$CC$$",
"C##CCCCCC###C####$#CCC&&&&&&&&&&&&&&&&&&0&&&KKKKKKKKKK&&W&&&&&&&&&&&&&K&&&&&&W&&&&&&&&&&CCC$$##$#$###",
"#$$$$$$##$###C###CCCCCC&CC&&&&&&&&&K&&&&&&&&&&&&&&&&&K&&KKKKK&K&&&&&&&&K&&&&&KKKKKK&K&&&&&&&&&&&&&C&C",
"########$$#####CKKCCC&&&&&CC##CCCC&&&&&&&K&&K&&&&&&&000&&&&&&&KKKKKKKKK&KK&K&&&&KKKK&&&&&&&&&&&&&&&&C",
"$$$$##C##C###CCCCC&&&KKKK.&&&&&&CCC&&&C&&&&&&&&&&&&&&&&&KKKKKKK&&&&&&&CC&#$C&&&&&&&&&&&&&&&&&&&&&&&&C",
"$$$$$$$$$$########$##$$$$$$#####CC&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&KKKC&CC#CCCCCC",
"#####$$$$$$$#####$##CCC#$$$$$$$$$#C&&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&K&&&&&&&&&&&&&KKCK#$$$CC#CCC#C#",
"########$$$$$#$#$$#$C#CC$C$######CCCCC#$#$CC&&&&+0+&&&&&&&&&&&&&&&&&&&&&&&&&&&&CCC#CC#$$#CCCC$$$#&CC#",
"##CC#C#C########$$$$###############CC#CCCCCCCC&K000C&C&&&&&&&&&&&&&&&&&00&&&CCCCC#C####$$$$#CC#CC&C##",
"#C#C#####C####$####$$#$++++++$$##$####CCC#CCCCCC00CCC&&C&&C&&&&&&&&&&C&&CCCCCCC#CC++++++CCCCCCCC####$",
"#C#########C#C######$+++0000++$###########C##C##CCCCCCCCCCC#####C####CCCCCC&CC&&&0000000&&KC#########",
"C#C###C######C######+000000000$$$$#$#$#$###&C$##C$#C#CCCC&C&&CCC###CK&CCCCCC&C#C000000&&&&$$C########",
"CCC#C######C###C#C#.00000000000$$$$$$$$$##CCC##C##C#C#CC##CC#CCCC##CCCCCCCC&CCC#CCCCCCC++++CCC#$$###$",
"##C#############CC....&&C&C$#$###$#$$$#$$$$$##CCC#####CCCCC&C###$#C######C&#C$#CCCCCC#++000CCCC######",
"C##C###C#C#CC####$#$$$$$$CC$$$#########$$$$$$$####$##CCC##CC#C##CC#############$####$+00000.$$$#C###$",
"CCCC###C##C#C##########$$$$$##$#C##$$#$$$$$$$$$##########CCCCCC##CCC#######C##CC##C#++00000..##$$#$$$",
"CCCCCC#C+#####C#CCCC++++C#CC@CC#######$$$$$$$$$$$#CCCCC##CCC############CC######$$$$$#$$$$#$$###$$##$",
"0CC0CCC00C0#CCCCCCC@@@@@@CC###C####C########$$$$$$$$$$$$$$$$##$$$$$$$$$$$#$#$$$###$###$###C#C####C$CC",
};

char HubTown_Nav3[][101] = 
{
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBVBBBBBBBWWWWW0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVBBBBVBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBVWWWWWWWWWWWWW$BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVVVVBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BVBBBVVVVVBBVVVWWWWWWWWWWWW0WWWVVVVVVVVBVVVVBVVBVBBVVVVBVVVBBVVV$WWWWWWWVVVVVBBBVBBVVVVBVVVVVVBBBBVVV",
"VVVVVVVVVVVVVVWWWWWWWWWWWWWWWWWWWWWVVVVVVVVVVVVVVVV00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVW0W0WWWW0WWWWWWWWWWWWWVVVVVVVVVVV0WWWWWWWWVVVVVVVVVVVVVVVVVVVVV0WWWW0VVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVWWWW0WWWWWWWWWWWWW00W0WWW0VVVVVVVVVV00WWWWWWWW0VVVVVVVVVVVVVVVVVVWWWWWWWWWWWVVVVVVVVVVVVVV",
"VVVVVVWWWWWWWWWWWWWWWW0000WWWWWWWWWWWWWWWVVV00WWWWWW00WW0VVWWVVVVVVVV0WWWWWWWW0W0WWW0WWW0WWWWWVVVVVVV",
"0VVWWW00V00W00V0W0WW0VVVVV0WWWWW00WWVV0WW0VV000WWWWWWWWWWWWWWWW00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWW0WWWWWWWWWWWWWWWVVVVVVVVVVVVVVVVWVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVV0WWWWVVVVVVVVWWWWWWWWWWWW00WWWWWWWWWW0WWW0WW00VVVVVV0WWWWWWW00WWVVVVVVVVVVV",
"WWWWWVVVVVVVVVVVWWWWW0VVV00WWWWWWWVV0VW0VVVVVVVVVVVV00WWWWW0VWWVVVVVVVVVVVVV0WWWWWWWWWWWWWWWWWWVVWVVV",
"0000000VVVVV0WW0WWWWWWW000WWWWWWWWWVVVVVVVVVVV0WWV000WWWWWWWWWW0VVVVVVVVVWWWWWWW0WWWWW0W0V00WW0WW00VV",
"WVVVV0VVVVWW0WWWWWWWWWWW00WWWWWWWWWWWWWVVVVV00V0VVVV00WWWWWW0WWWWVVVVVVVVVVV0WWW0WWW0W00VVV00VWW0VVVV",
"WWV0VCCV@C$#WV000WWWWWWWWWV0W0WWWWWWWW0W0WVWWWWWWWW0V0VVV00WWWWW0WWWWW0W0000V$V0W0VV00VVWV$WW0WW$C$00",
"WV$$$C##C#CVVC$V00VVVVVWV0W0V0V0000000WW00WWWWWWWW0WVVVVV0WW0W0000W000WWW00#CVVVVVVVVWWW0VCV0WVVCVCVV",
"##CC#CCCCV#VVV#VWVVCCV00VVW0WV#VWVV0WWWWWWW000VVVVV0WWWWW0WWWW0VVVVV000V00C##C#WVVV#CCVWVC##VVVVC#CCV",
"##VCC#CCCC##CCC#VVVC@C##V##CVCCCVVVWCVV00W000V0VVVVV0VVVVVVVVVW0VVCCVVV#VV#CCCC#VVVCC##CC#C##VCCCCCC#",
"#V#$#CC#C#$CC$#$$#$#CC##CC$##CC#$CC#CVVVWVVWVVVVVWVVVVW0VVWVCCVCCV#C#VC#V$$#CCCC$#CCC##$#CCC$$CC$#CCC",
"##C#$CC#C#C$$CC$#$#CCC#CCC##$##CCCCCCC####$##$######$#$C$######C$$$C###C$CCCCC#C$###C##CC#CCCC#C#CCCC",
"#CCC$#C##C####$#$CC#CC#CCCC#C#CC#C#C#CCC#C#C###CC###CCCC###CCC#CCCCC#CCC#CCCCCC##C#CCC$#CCCC##CCC$CCC",
"CC#CC#$###CC$#CC##CCCCCCC#C#C##CC#CCCC#C#C#C####CC#C#C#C#####C##C$##CCCCC#$$#CC#CCCCCCCCCCC#CCC#C#C#C",
"##CC###C$$C####CCC##CC##CCC#$#C##C&&&KKK&##CCCCCCCCC##CC#CC#C#C####CCC#CC##CC#CCC#CCC#CCC#$$##CCCC#CC",
"CCCCC##C#CC$##CC$$$#CC&C&&&&&&K&&&&&&&&&&&&&&&&&&&&K&&&&K&KKK&&KKKKKK&KKKK&&&CCCCCCC###$$$####$CC#C#C",
"####CCC##C#CC#$$C&&&&&&&&&&&&KK&&KKKKKKKKKKK&&&&&&&&&&KKK&&&K&&&&&&&&&&&&&K&&&&&&&&&&&&&CC$$$$$$$CC$$",
"C##CCCCCC###C####$#CCC&&&&&&&&&&&&&&&&&&0&&&KKKKKKKKKK&&W&&&&&&&&&&&&&K&&&&&&W&&&&&&&&&&CCC$$##$#$###",
"#$$$$$$##$###C###CCCCCC&CC&&&&&&&&&K&&&&&&&&&&&&&&&&&K&&KKKKK&K&&&&&&&&K&&&&&KKKKKK&K&&&&&&&&&&&&&C&C",
"########$$#####CKKCCC&&&&&CC##CCCC&&&&&&&K&&K&&&&&&&000&&&&&&&KKKKKKKKK&KK&K&&&&KKKK&&&&&&&&&&&&&&&&C",
"$$$$##C##C###CCCCC&&&KKKK.&&&&&&CCC&&&C&&&&&&&&&&&&&&&&&KKKKKKK&&&&&&&CC&#$C&&&&&&&&&&&&&&&&&&&&&&&&C",
"$$$$$$$$$$########$##$$$$$$#####CC&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&KKKC&CC#CCCCCC",
"#####$$$$$$$#####$##CCC#$$$$$$$$$#C&&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&K&&&&&&&&&&&&&KKCK#$$$CC#CCC#C#",
"########$$$$$#$#$$#$C#CC$C$######CCCCC#$#$CC&&&&+0+&&&&&&&&&&&&&&&&&&&&&&&&&&&&CCC#CC#$$#CCCC$$$#&CC#",
"##CC#C#C########$$$$###############CC#CCCCCCCC&K000C&C&&&&&&&&&&&&&&&&&00&&&CCCCC#C####$$$$#CC#CC&C##",
"#C#C#####C####$####$$#$++++++$$##$####CCC#CCCCCC00CCC&&C&&C&&&&&&&&&&C&&CCCCCCC#CC++++++CCCCCCCC####$",
"#C#########C#C######$+++0000++$###########C##C##CCCCCCCCCCC#####C####CCCCCC&CC&&&0000000&&KC#########",
"C#C###C######C######+000000000$$$$#$#$#$###&C$##C$#C#CCCC&C&&CCC###CK&CCCCCC&C#C000000&&&&$$C########",
"CCC#C######C###C#C#.00000000000$$$$$$$$$##CCC##C##C#C#CC##CC#CCCC##CCCCCCCC&CCC#CCCCCCC++++CCC#$$###$",
"##C#############CC....&&C&C$#$###$#$$$#$$$$$##CCC#####CCCCC&C###$#C######C&#C$#CCCCCC#++000CCCC######",
"C##C###C#C#CC####$#$$$$$$CC$$$#########$$$$$$$####$##CCC##CC#C##CC#############$####$+00000.$$$#C###$",
"CCCC###C##C#C##########$$$$$##$#C##$$#$$$$$$$$$##########CCCCCC##CCC#######C##CC##C#++00000..##$$#$$$",
"CCCCCC#C+#####C#CCCC++++C#CC@CC#######$$$$$$$$$$$#CCCCC##CCC############CC######$$$$$#$$$$#$$###$$##$",
"0CC0CCC00C0#CCCCCCC@@@@@@CC###C####C########$$$$$$$$$$$$$$$$##$$$$$$$$$$$#$#$$$###$###$###C#C####C$CC",
};

char HubTown_NavNPC[][101] =
{
    // TODO
};

char HubTown_NavNPC2[][101] =
{
    // TODO
};

char HubTown_NavNPC3[][101] =
{
    // TODO
};

char HubTown_NavMerchant[][101] =
{
    // TODO
};

char HubTown_NavHousesFar[][101] =
{
    // TODO
};

char HubTown_NavHousesClose[][101] =
{
    // TODO
};

char HubTown_NavExit[][101] =
{
    // TODO
};






















char Area1_Nav1[][101] = 
{
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBVBBBBBBBWWWWW0BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVBBBBVBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBVWWWWWWWWWWWWW$BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVVVVBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BVBBBVVVVVBBVVVWWWWWWWWWWWW0WWWVVVVVVVVBVVVVBVVBVBBVVVVBVVVBBVVV$WWWWWWWVVVVVBBBVBBVVVVBVVVVVVBBBBVVV",
"VVVVVVVVVVVVVVWWWWWWWWWWWWWWWWWWWWWVVVVVVVVVVVVVVVV00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVW0W0WWWW0WWWWWWWWWWWWWVVVVVVVVVVV0WWWWWWWWVVVVVVVVVVVVVVVVVVVVV0WWWW0VVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVWWWW0WWWWWWWWWWWWW00W0WWW0VVVVVVVVVV00WWWWWWWW0VVVVVVVVVVVVVVVVVVWWWWWWWWWWWVVVVVVVVVVVVVV",
"VVVVVVWWWWWWWWWWWWWWWW0000WWWWWWWWWWWWWWWVVV00WWWWWW00WW0VVWWVVVVVVVV0WWWWWWWW0W0WWW0WWW0WWWWWVVVVVVV",
"0VVWWW00V00W00V0W0WW0VVVVV0WWWWW00WWVV0WW0VV000WWWWWWWWWWWWWWWW00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWW0WWWWWWWWWWWWWWWVVVVVVVVVVVVVVVVWVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVV0WWWWVVVVVVVVWWWWWWWWWWWW00WWWWWWWWWW0WWW0WW00VVVVVV0WWWWWWW00WWVVVVVVVVVVV",
"WWWWWVVVVVVVVVVVWWWWW0VVV00WWWWWWWVV0VW0VVVVVVVVVVVV00WWWWW0VWWVVVVVVVVVVVVV0WWWWWWWWWWWWWWWWWWVVWVVV",
"0000000VVVVV0WW0WWWWWWW000WWWWWWWWWVVVVVVVVVVV0WWV000WWWWWWWWWW0VVVVVVVVVWWWWWWW0WWWWW0W0V00WW0WW00VV",
"WVVVV0VVVVWW0WWWWWWWWWWW00WWWWWWWWWWWWWVVVVV00V0VVVV00WWWWWW0WWWWVVVVVVVVVVV0WWW0WWW0W00VVV00VWW0VVVV",
"WWV0VCCV@C$#WV000WWWWWWWWWV0W0WWWWWWWW0W0WVWWWWWWWW0V0VVV00WWWWW0WWWWW0W0000V$V0W0VV00VVWV$WW0WW$C$00",
"WV$$$C##C#CVVC$V00VVVVVWV0W0V0V0000000WW00WWWWWWWW0WVVVVV0WW0W0000W000WWW00#CVVVVVVVVWWW0VCV0WVVCVCVV",
"##CC#CCCCV#VVV#VWVVCCV00VVW0WV#VWVV0WWWWWWW000VVVVV0WWWWW0WWWW0VVVVV000V00C##C#WVVV#CCVWVC##VVVVC#CCV",
"##VCC#CCCC##CCC#VVVC@C##V##CVCCCVVVWCVV00W000V0VVVVV0VVVVVVVVVW0VVCCVVV#VV#CCCC#VVVCC##CC#C##VCCCCCC#",
"#V#$#CC#C#$CC$#$$#$#CC##CC$##CC#$CC#CVVVWVVWVVVVVWVVVVW0VVWVCCVCCV#C#VC#V$$#CCCC$#CCC##$#CCC$$CC$#CCC",
"##C#$CC#C#C$$CC$#$#CCC#CCC##$##CCCCCCC####$##$######$#$C$######C$$$C###C$CCCCC#C$###C##CC#CCCC#C#CCCC",
"#CCC$#C##C####$#$CC#CC#CCCC#C#CC#C#C#CCC#C#C###CC###CCCC###CCC#CCCCC#CCC#CCCCCC##C#CCC$#CCCC##CCC$CCC",
"CC#CC#$###CC$#CC##CCCCCCC#C#C##CC#CCCC#C#C#C####CC#C#C#C#####C##C$##CCCCC#$$#CC#CCCCCCCCCCC#CCC#C#C#C",
"##CC###C$$C####CCC##CC##CCC#$#C##C&&&KKK&##CCCCCCCCC##CC#CC#C#C####CCC#CC##CC#CCC#CCC#CCC#$$##CCCC#CC",
"CCCCC##C#CC$##CC$$$#CC&C&&&&&&K&&&&&&&&&&&&&&&&&&&&K&&&&K&KKK&&KKKKKK&KKKK&&&CCCCCCC###$$$####$CC#C#C",
"####CCC##C#CC#$$C&&&&&&&&&&&&KK&&KKKKKKKKKKK&&&&&&&&&&KKK&&&K&&&&&&&&&&&&&K&&&&&&&&&&&&&CC$$$$$$$CC$$",
"C##CCCCCC###C####$#CCC&&&&&&&&&&&&&&&&&&0&&&KKKKKKKKKK&&W&&&&&&&&&&&&&K&&&&&&W&&&&&&&&&&CCC$$##$#$###",
"#$$$$$$##$###C###CCCCCC&CC&&&&&&&&&K&&&&&&&&&&&&&&&&&K&&KKKKK&K&&&&&&&&K&&&&&KKKKKK&K&&&&&&&&&&&&&C&C",
"########$$#####CKKCCC&&&&&CC##CCCC&&&&&&&K&&K&&&&&&&000&&&&&&&KKKKKKKKK&KK&K&&&&KKKK&&&&&&&&&&&&&&&&C",
"$$$$##C##C###CCCCC&&&KKKK.&&&&&&CCC&&&C&&&&&&&&&&&&&&&&&KKKKKKK&&&&&&&CC&#$C&&&&&&&&&&&&&&&&&&&&&&&&C",
"$$$$$$$$$$########$##$$$$$$#####CC&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&KKKC&CC#CCCCCC",
"#####$$$$$$$#####$##CCC#$$$$$$$$$#C&&&&K&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&K&&&&&&&&&&&&&KKCK#$$$CC#CCC#C#",
"########$$$$$#$#$$#$C#CC$C$######CCCCC#$#$CC&&&&+0+&&&&&&&&&&&&&&&&&&&&&&&&&&&&CCC#CC#$$#CCCC$$$#&CC#",
"##CC#C#C########$$$$###############CC#CCCCCCCC&K000C&C&&&&&&&&&&&&&&&&&00&&&CCCCC#C####$$$$#CC#CC&C##",
"#C#C#####C####$####$$#$++++++$$##$####CCC#CCCCCC00CCC&&C&&C&&&&&&&&&&C&&CCCCCCC#CC++++++CCCCCCCC####$",
"#C#########C#C######$+++0000++$###########C##C##CCCCCCCCCCC#####C####CCCCCC&CC&&&0000000&&KC#########",
"C#C###C######C######+000000000$$$$#$#$#$###&C$##C$#C#CCCC&C&&CCC###CK&CCCCCC&C#C000000&&&&$$C########",
"CCC#C######C###C#C#.00000000000$$$$$$$$$##CCC##C##C#C#CC##CC#CCCC##CCCCCCCC&CCC#CCCCCCC++++CCC#$$###$",
"##C#############CC....&&C&C$#$###$#$$$#$$$$$##CCC#####CCCCC&C###$#C######C&#C$#CCCCCC#++000CCCC######",
"C##C###C#C#CC####$#$$$$$$CC$$$#########$$$$$$$####$##CCC##CC#C##CC#############$####$+00000.$$$#C###$",
"CCCC###C##C#C##########$$$$$##$#C##$$#$$$$$$$$$##########CCCCCC##CCC#######C##CC##C#++00000..##$$#$$$",
"CCCCCC#C+#####C#CCCC++++C#CC@CC#######$$$$$$$$$$$#CCCCC##CCC############CC######$$$$$#$$$$#$$###$$##$",
"0CC0CCC00C0#CCCCCCC@@@@@@CC###C####C########$$$$$$$$$$$$$$$$##$$$$$$$$$$$#$#$$$###$###$###C#C####C$CC",
};

char Area1_Nav2[][101] = 
{
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0WWWWWW0BBBBB",
"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB00000BBWWWWWBBBB",
"BVBBBBBBBBVVBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVVVV00W00VVVVVV00000000",
"BBVV00BBBBBBBBVBVBBVBVBVBVBVBVBVBVBVBVBVBVBVBVBVBVBVBVBVBBVBVBVBVBVBVBVBVBBBBBBVBBBVVBVVVVVVVVVBBVBBB",
"BV0WWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"W0W00WWWWWWW0VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWW",
"VV000WWWWWWWWW00VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV0VVV0W00VVVVVVVVVVVVVVBVBVVV0WWWW",
"VVVV000WWW0WWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV00000WW00WWW0VVVVVVVVV0W0WWW0WW00W0",
"0VVVVVVVV00WWWWWWWWWWWW0VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV0WWW00W0000VVV",
"VVVVVVVVVVVVVV0WW00W0WW0WWWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV000WW00WW00W00VVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWVVVVVVVVVVVVVVVVVVVVVVVV0VV00VV00VVVVV0VVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVV00VVV0WWWWVVVVVVVVVVVVWWWWWWWW0VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVWWW0WWW0VVVVVVVVV0VVVVVVVV0VVVVVVVVWWVVVVV0WWWWWWWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV",
"VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV00WWWWWWWWWW0VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVBBBVVV",
"VBC#$BVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV00VVV0WWW00WWWWWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV0VV$$CCV00",
"VC#CCC$0WW0VVV0000000VV00000V00VVVVVVVW00VVVVVVV0WWWWWWWW00W0WWW0VWVVVVVVVVVVVVVVVVVVVWV#VWWBC#C@CCCC",
"V$C@CCCV00C0VVVVVVVVVVVVVVVVVVVVVVVV000VVVVVVVV000W0WWWWWWWWWWWWWWWWWWVVVVVVVVVVVCVVWWCVCCWWVC$CC$$C$",
"C@@CCC$#$C##$00VVVVVV0WWW0VVVVVV0W00VVVVVVV0000WWW0WWWWW0000000W0W0W00W0000VWWWWC$#0WV$$@C$VCCCCCCC$C",
"CCC@CC#VCCC$V0W0W0W0WWWWWWW0VV00W000VVVVVV0WWWWWWWWWWW000VVVV0V000VVV0WW0WWV$CW0V$CVV##C@CCC#C#@CCC#C",
"CCCCCC###CCC$CV0VV000W00WWWWW0W00VVVVVVV0BW0WWWWWWWWW0W0WB00W00W0WWWVCWWVBBCCCWVCCC#C#CC@@CCC#CCC#@CC",
"C##C@C$$CC@CCC0BCCBBCCB0W0WWWWWWW00B000WWWWWWWWWW00W0W00WWWWCW0$B0$#$#CC####C#CCC@#CC@@CCC@@@@C@@CCCC",
"C@@@C$#CCCCCC$#CCC$VC#0VCV00WW00W0WWWWWWWWWWWWWWWWWWCWB0WBBCCCV#CCC#CCC#C##C@@CCCCCCCC@@CCCCC@C@@C#CC",
"@CCC@@C#CCCCCCCCCC#CCCC$CCCCCC0000W00W0W00W0CWC0WCW0#0C#0$$##$$#####CCC#CCCC@CCCC@#@CCCCC@@@@CCC@@CCC",
"@C@CCCCCCC@@CC#$CCCCCC$###CC$C$CC$$CCCC$0$C$$CC$C$$$$##$####CCCCCCCCCC@@@CCCC@CCC@CCC@C@C@@@C@C@CCCC@",
"@@@@C@CC#@C@C$#C@CC#CCC##C##$$$$$$$$$$$$$$$$##$$#C##########C#CC$###CCCCCCCCCCCC@@@@@C@@@CCCC@@@@@@CC",
"CCC@CCCCCCC@@C#@@@C$$C#C$C###&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&######CCC$$###CC####CC#$CCCCCC#@@C",
"###C$$####&&&&&&####&&&&&&&&&&&&&&&&&&&&&&&&&&&0&&&&&#&#&&##&##&&&#&&&##&##########C$$$#####C#CCCC#CC",
"#############&##&&#&&&&&&&&&&&#&&#&&&&&&&&&&&&&&&&&&&&&##&###&&&&#&&#&#&##&#&##&#######CCCC$$$$$$$#C#",
"C##&###&##&###&&##############&#####&#&###&&&&&&&##&#&&#&##&######&###&#&#&###&###&&#&#&#########CC#$",
"#################$#&####&#&#####&######&&#####&&##############&#&##&&&#&&&&&00&&&&&&&&&&##&##&#&#####",
"CCC####C##++CCC####CC############&###&#####&#&###&#####&&&&#&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&########&&#",
"C#CCC#CC.000########################################&#&###&&#&#&####&#&&###&#&###&#&#&#&&#&##&#&#####",
"$CCCC$$C#.&&&&0&&&&######C###C##C##CCC##C###&###########&#######&00&###&###&#######&################C",
"$CCCCCC$$C&0##############C###C############&#########&###&##########&##&##&###++##CCCCCCCCC$CC$CC$CC$",
"$$#C+++++C######C$C$#########&&#&##&&&&&&############&######################+000.CCCCCCCC$CCCCC$$C$$$",
"#C#000000$C$$$####$$$$##CC######&&####&###&&&###&#######################&##0000.CC###C#CC#CCCCCCC$$$$",
"#.00000000##$$$#C$$$$$$$CCCCCCCC##########################C#CCC###########C$C#&########CCCCCCCC$$$$$C",
"#..000000#$#$#$$#$$$$$#$#$$$$$$$C$C$$$C$CC$CCCCCCCCCCCCCCCCC##############################C#CCCCCC$$$",
"##...#CC######$#$####C##$#########$#$$#$$$$$$$$$$$CCCC$CCCCCCCCCCCCCCC$CC$C$$CCCCCC$CC$$CC#$$##C$####",
"##CC##C##C#C#######C##C##CC################C################################################C#####C##",
};

char Area1_Nav3[][101] = 
{
"BBWWWWWWWWWWWWWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWBBB",
"BWBBWWWWWWWWWWWWWWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWW",
"BWBBBWWWWWWWWWWWWWWWWWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWW",
"BBWWBBWBBWWWWWWWWWWWWWWWWWWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWW",
"BBBWBWBWBWBBBBBBBBBBBWBBBWBWWWWWWWWWWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWBBB",
"WBWBBBWBWBWBBBBWBWWBWBBBWBBBBBWBBWBBBBBWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWBWWWWWWWWWWWWWWWWWWWBBBWWB",
"BBBBBBBBBBBWWWWWBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBWWWWWWWWWWWWWWWWWWWWVVVVWWVVWWVVW",
"VVVVVWVVVVWWWWWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWVWWWWWWWWWWWWWWWWWWVWVWVWVVWVVWVVWVVVWVWV",
"VWWWWWWWWWVWWWWWWWWWWWVWVVVVWWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVWVVVVVVVVVWVWVWVVWVVVVVVVVVVWVVVVVVVVVVVVV",
"WVVWWWWWWWWVWVVWWWVWWWWWWWVWWWWWWWWWWWVWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWVVVVVWWWWWV",
"WVWVWVWWWWWWWWWWWWWWWWWWWWVWWWWWWWWWWWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWWWWWWWWWVWWWWVVWW",
"VWVVWVWWVVVVVVWVWVVVVVVVWWWVWVVWWWVVWVVWWVWVWVVVVVVVVVVVVVVVVVVVWWWWWWWWWWWWWWWWWWWWVWWVWVWVVVWVWVVVV",
"VVVVVVVVVVVVVVV#VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWWWWWWWWWVWWVVWVVVVWVVVVVVVVVVVVVVVVV",
"VWWWWWWWWVVVVV$###VVVVVVVVVVVVVVVVVVVVVVVVVVVWWWWWWVVVVVVVVVVVVVVVVVVVVVVVVVVVV$##VVVVVVVVWVVVVWWWWVV",
"WVWWWWWWWWWV#CC##CVVWWWWWVVVVVVVVVVVVVVVVWWWWWWWWWWWWWWWVVVVVVVVVVVVVVVVVVVVVVVCCVVVVVWWWWWWWWWWWWWWW",
"VWVVWWWVWWWWV#C##CVWWWWVWWVVVVVVVVVVVVVVVWWWWWWWWWWWWWWVWVVVVVVVVVVVVVVVVWWWV#C#C#VWVWWWWWWVVWWWWWWWV",
"VVWVWWV#VWVC#CC0C##VWW#C$VWWWW#WWVVVWWWWWWWWWWWWWWWWWWWWVWWVVVVVVVWWVVWCCVWV#W##CC$#$VWW$VW###WWVWVVW",
"WVVVWV###WWVVC0$C##VVCCC#WWW#CC#WWVWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWV$#WVV#C#C###CCCVV$VC####VVVVWV",
"VVVVV#C0C#CC#C0CCCC##CCC#C#WVVC$VWWWWWWWWWWVWVWVWVWWWWVWWWWWWWWWWWVWWWVCCC#C#CC#CCCC##C####C##CVVCVVV",
"VVV###CCC##CC0C0CC##$#CC$C$V####$VWWWWWWWWWWVWWWWWWWWWWWWVVVWWWWWC#CW#CCC#CC$$C##C0#$#CCC##$CC#C#C#V#",
"#$VVCCC##$####00CC#C#CCCCCC##CCCCCVVVV##WVV#VWWWVWWVVWVWVWWVCVWV#CCC$CCC#C0CCC#0##CCC#CCCCCC0CC###C$#",
"###C#CCC#$$#C000CCC##$CC#C#$#0#CCC##$##$VVV#CVVVCVVV$#VW#VV$##$C#CCC$#CC#$#CCCCCCC#C##CC#CCCCC#$##$CC",
"CCC$CC0C#CC#0CC#CC##C#C0CC$CCC#C##C#CCC##$VCCC$####CCC$C$$#C######C0C##0C$$00C00C#CCCC$##C00000##$CC#",
"CC##CCCCC##C000C#$##$CCCCCCCCCCCC#CCC#CC$$##C#$$###C##$C#CC#C$#$#BBBBBB###$CC##CCCCCC#CCC$CC00CC#CCCC",
"#CCCC##CCCCCCC0CC0CCCCCCCC#C$##&&&&&&&#&&##CC#C#C###$&#&#&&&&&&&&&&&&&&#&####$$CC##CC0CCCCC000CC#0CC#",
"#CCC0###00CCC00CC$#CCCC$###########&&##&&&&&&&&&&&&&&&&&&&&&&&&#&&################C#C0#$##C000CCC#CCC",
"#######CC0CCCC00CCC$###&&&&&#&&&&&&##&###################&###########&###############$CC##C000CCCC00C",
"#CC#C00C000###C$$#######################&&###&&###########&##########&&$#C###############CCCC#CC###C#",
"#CCCCCCCC$############&########&##&&############################################################$$$CC",
"$$$$##############$&&&&########&&&#######&&##&&##########&&&&########################################",
"$#################CC&##CC###########&&&####&##############&#&&######&################################",
"####################################################&################################################",
"################################&#&&&###############################################################$",
"$$$#######################&&&&####################################################################$$$",
"$$$#$$$#################C#$&&&&&&##############################C$#################$$$$$$#$$$$CC$$#CCC",
"$####$$$$$$$##$$$$$$$##C#&$&&$####$####$############$$$$#####$$$$$$$$$$$$####$$$$$CCCCC#CCC$$$$CC#$C#",
"#$$$$$$$$$$$$$$$$$$$CC###&&&&&#&CCCC$##########$#$$$#$$$$$$$##$$$$$$$$$$$$$##$$CCCCC$CC#CCCCCC#######",
"#CCCC##C#CCC$$$$$$$CCC$####$$###CCC$$$$$$$$$$#$$##$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$CC$CCCC###C#CC###C0CC",
"##C####CCC#C$$C###CCCCCC$C$C##CC$#CC$$$$CCC#CC$$$##$$$$$$$#$$##$$#$C##C$$$$$$$CCCCCCC#C#####C###CC#CC",
"C#CCCC#$CCCCCC#CCC##CC####C#C####CC$$$$$CC#$$$CCC$CC$$$$$#$$$$CCC$C$CCCCCCCCCCC#########C#C##C#CCCCCC",
"C##$###$#CC#$C$###CCC#####$CC#CCCCCCCCCC##CC#####CCCCC####CCCCC##CC########CC#$CCC#CC#C#CCCCC$$##$0##",
"#CC##CC####C##C##C##C#CC##C#C####CCC##C#C##C###CC####C####C#CC##C#C###########C#####CC##CCC##C#C#C##C",
};

char Area1_NavSP1[][101] =
{
    // TODO
};

char Area1_NavSP2[][101] =
{
    // TODO
};

char Area1_NavClosed[][101] =
{
    // TODO
};

char Area1_NavBigTreeVeryFar[][101] =
{
    // TODO
};

char Area1_NavBigTreeFar[][101] =
{
    // TODO
};

char Area1_NavBigTreeClose[][101] =
{
    // TODO
};

char Area1_NavExitToHub[][101] =
{
    // TODO
};


void initNavAreas() 
{
    // Hub Town
    navAreas[0] = HubTown_Nav1;
    navAreas[1] = HubTown_Nav2;
    navAreas[2] = HubTown_Nav3;
    navAreas[3] = HubTown_NavNPC;
    navAreas[4] = HubTown_NavNPC2;
    navAreas[5] = HubTown_NavNPC3;
    navAreas[6] = HubTown_NavMerchant;
    navAreas[7] = HubTown_NavHousesFar;
    navAreas[8] = HubTown_NavHousesClose;
    navAreas[9] = HubTown_NavExit;

    numNavAreas[0] = HUBTOWN_NAVAREAS;
    // Area1
    navAreas[10] = Area1_Nav1;
    navAreas[11] = Area1_Nav2;
    navAreas[12] = Area1_Nav3;
    navAreas[13] = Area1_NavSP1;
    navAreas[14] = Area1_NavSP2;
    navAreas[15] = Area1_NavClosed;
    navAreas[16] = Area1_NavBigTreeVeryFar;
    navAreas[17] = Area1_NavBigTreeFar;
    navAreas[18] = Area1_NavBigTreeClose;
    navAreas[19] = Area1_NavExitToHub;

    numNavAreas[1] = AREA1_NAVAREAS;
    // Area1_Interior (Big Tree)


    numNavAreas[2] = AREA1INT_NAVAREAS;
    // Area2
    

    numNavAreas[3] = AREA2_NAVAREAS;
    // ...
}
