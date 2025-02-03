// TODO: These need to be reworked

char HUB[30][100] =
{
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"===========~~~~~~~~~~~~=============~~~===~~===================~~~~~~~~~~~~~~~~~~=========~~~~~",
"~=        ==============           ===== ====                 ==================== ;   ; ===~~~",
"~~=                                                                ;  ;  #####       ;  ; =~~~~",
"~~~=         ++++++++  |;; ;; ;; ;; ;;; ; ;;|               -------- ;  ####*##   ; ;  ; =~~~~~",
"~~~~=        |vvvvvv|  | ;; ;; ;; ;; ;; ;; ;|    :::        |wwwwww|;  ##*###*##;    ;  =~~~~~~",
"~~~~~=       |      |  |; ;; ;; ;; ;; ;; ;; |   :   :       |      | ;  ##|||##   ;    =~~~~~~~",
"~~~~=        | 1    |   ====================   :  R  :      |  2   |   ;  |||  ;   ;  =~~~~~~~~",
"~~~=         |----  |                           :   :       |----  | ; ;  |||    ;   =~~~~~~~~~",
"~~=  ========        ============================   ========        ==================~~~~~~~~~",
"=====                                                                                =~~~~~~~~~",
"P                                                                                     =~~~~~~~~",
"=====                     3                                                            =~~~~~~~",
"~~~~~=                                                                                  =~~~~~~",
"~~~~~~=                                                  5                               =~~~~~",
"~~~~~~~=                                                                                =~~~~~~",
"~~~~~~~~=            #####                                                               ======",
"~~~~~~~=            ####*##            4                                                      F",
"~~~~~~=  ^^^^^^    ##*####*#     ------------                 +++            6           ======",
"~~~~~~~==++++++=== ####*#### ===/~~~~~~~~~~~~/=======        +++++                 ======~~~~~~",
"~~~~~~=  xxxxxx   = # ||| # =   /~~~~~~~~~~~~/ ;    =  +++++++xxx+++++++++++++++  = ;    =~~~~~",
"~~~~~=   xxxxxx    = ;||| ;=    /~~~~~~~~~~~~/    ;  = ++++++xxxxx++++++++++++++ =       =~~~~~",
"~~~~=    |    |    =; |||; =     ------------ ;       =xxxxxxxxxxxxxxxxxxxxxxxxx=    ;  =~~~~~~",
"~~~=               = ; ;  ;=                    ;      xxxxxxxxxxxxxxxxxxxxxxxxx   ;   =~~~~~~~",
"~~=                 = ; ; =                  ;     ;   xxxxxx     xxxxxxxxxxxxxx      =~~~~~~~~",
"~~=             ;    =====       ;             ;                   ;      ;          ; =~~~~~~~",
"~~=                        ;                         ;     ;   ;       ;     ;   ;      =~~~~~~",
"~~~======================================================================================~~~~~~"
};

char MAP_1[28][100] =
{
"========",
"=      ?==~~~~~~~~~~~~~~~~       ~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"=         =~~~~~~~~~~~~~~~~~   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"=          =~~~===========~~~  ~~~=====================~~~~~~",
"=           ===           =~~~~~~=                     =~~~~~~",
"=                          =~~~~=                       =~~~~~",
"=                           ===                         =~~~",
"=                                                        =~~~",
"=                                        ====             =~~~~~~",
"=                                       =~~~~=             ====~~~~",
"=                                      =~~~~~~=                =~~~~~",
"=                                       =~~~~=                =====",
"=                                        ====                    F=",
"=                        ##############                       =====",
"=                      ####################                  =~~~~~~~~",
"=                    #########################                =~~~",
"=                   ###########################                =~~~~~~",
"=                  #############################                =~",
"=                 ##############################                =~~~",
"=                 #######     ||||   ##########              ===~~",
"=                             ||||                          =~~~",
"=                             ||||                         =~~~~",
"=                             ||||                        =~~~~~",
"=                            ;|EE|;                ======~~~~~~",
"=                                            ======~~~~~~~",
"=           __                              =~~~~~~~",
"= P        ;  :                            =~~~~~~",
"===========================================~~~~"
};

char MAP_1_int[12][18] =
{
"#################",
"#K       | ######",
"|##  |    #   ?#|",
"|  #####   #  ###",
"|           # |#|",
"|   |           |",
"|  |            |",
"|  |    P       |",
"|  |            |",
"-------EE--------"
};

char MAP_2[28][100] =
{
"        --        -----                ----                  --",
"       |P |      |  .  |              |   ?|                 |F|                |",
"      |   |     |  .    ---          |      |             |-|   -|             -|",
"     |     |---|  .  .  .  |----||--|--      |           -  -  -  |          -| |",
"    |    ?     |    .    .     ..  .   |      |         |          |       -|    |",
"   |            |   .    .    .   .   |        -|      |            |    -|     |",
"  |              |     .    .. . .   |           -|---|              |--|       |",
" |                |    .            |                                            |",
"  |                |---------------|                                              |",
"   |                                                                             |",
"    |                    *  ;:;  *                                                |",
"     |                    **;:;**                 *  ;:;  *                      |",
"    |                       ;:;                    **;:;**                        |",
"     |                      ;:;                      ;:;                           |",
"    |                              ---   ----        ;:;                          |",
"   |                              |~~~---~~~~|                                   |",
"  |                              |~~~~~~~~~~~~|                                   |",
" |                               |~~~~~~~~~~~~|             *  ;:;  *              |",
"  |         *  ;:;  *             |---~~~~---|               **;:;**                |",
"   |         **;:;**    |--------|    ----           |-----|   ;:;                 |",
"    |          ;:;     |~~~~~~~~~~|                 |~~~~~~~|  ;:;                |",
"   |           ;:;     |~~~~~~~~~~|                 |~~~~~~~|          -- --     |",
"  |                     |--------|                   |-----|          |     |    |",
"   |                   --------------                                |       |    |",
"    |                 |  .  .     .  |--        |-- ? |-----|         |     |    |",
"   |       | ---|    |    .     .    .  |-     |   |--       |----|    | K |    |",
"  |       |      |---  .    . .     .  .  |----                    |-----------|",
"   -------"
};

char MAP_3[28][50] =
{
"                                                ",
"",
"",
"",
"",
"",
"",
"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~",
"|~~|______________====________________~~|",
".|~~|            =    =               |~~|",
"|~~|               ==                 ?|~~|",
"~~|________     _==~~==________       |~~|",
"~~|. . .. .=   = . |~~| .   . .|     |~~~~|",
"|~~~~~~~~~~~=   =~~~~~~|________=   =~~~~~~|",
"|~~|_________=   =___~~~~~~~~~~~~=   =~~~~~|",
"~~|               |  |~~| ._______=   =___|",
"|~~|               ||~~|  |. __          |",
"~~|_____      ______|~~|_|. |~~|         |",
"~~| .  .|=   =. . .|~~| | . |~~|          |",
"~~~~~~~~~~=   =~~~~~~~~~~| . __ ?          |",
"~~~~~~~~~~~=   =~~~~~~~~~~~ _______=  =|____|",
"|~~|_______|=   = |~~|  |~~~~~~~~~~~=  =~~~~~|",
".|~~| . .  |   |___|~~|__|~~~~~~~~~~~=  =~~~~~|",
". |~~|.  .  |   | . |~~| .|___________=  =~~~~~|",
" . |~~|   . .|   |   |~~|    .  .  .  |=  =|~~~~|",
". . |~~|.  .  |   | . |~~| .  .   .  |     |~~~~|",
" ___|~~|______| P |___|~~|__________|   F   |~~~~",
"~~~~~~~~~~~~~~|___|~~~~~~~~~~~~~~~~~~_______~~~~~"
};