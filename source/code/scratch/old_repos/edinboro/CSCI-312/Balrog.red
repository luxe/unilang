;name Balrog
;author Trevor Hickey
;
; Deep in the Mines of Memory lies a daemon of the First Computing Age.
; It was once an object of great software but an out-of-scope pointer sent it tumbling into darkness.
; Programs now speak of a nameless fear that lurkes the shadows of heap memory- destorying all that allocate dynamically.
; Often called Programmers' Bane, or if you dare utter the words of ancient tongue:
; 01010100011010000110010100100000010000100110000101101100011100100110111101100111
; The Balrog!
; A shadowy being wreathed in flame and shadow
;
;               /|                                           |\
;              /||             ^               ^             ||\
;             / \\__          //               \\          __// \
;            /  |_  \         | \   /     \   / |         /  _|  \
;           /  /  \  \         \  \/ \---/ \/  /         /  /     \
;          /  /    |  \         \  \/\   /\/  /         /  |       \
;         /  /     \   \__       \ ( 0\ /0 ) /       __/   /        \
;        /  /       \     \___    \ \_/|\_/ /    ___/     /\         \
;       /  /         \_)      \___ \/-\|/-\/ ___/      (_/\ \      `  \
;      /  /           /\__)       \/  oVo  \/       (__/   ` \      `  \
;     /  /           /,   \__)    (_/\ _ /\_)    (__/         `      \  \
;    /  '           //       \__)  (__V_V__)  (__/                    \  \
;   /  '  '        /'           \   |{___}|   /         .              \  \
;  /  '  /        /              \/ |{___}| \/\          `              \  \
; /     /        '       .        \/{_____}\/  \          \    `         \  \
;      /                ,         /{_______}\   \          \    \         \
;                      /         /{___/_\___}\   `          \    `
; 
;
; The Balrog's spreads fire!  It creates a lot of threads while
; jumping and bombing the core. This ensures that it stays alive while moving everywhere
; on the board.  Stalemates are not an option.  The balrog kills.
;
;each dore war instruction:
;[OPCODE][A-FIELD][B-FIELD]
;         source    dest.
;
;    *  # -- immediate
;    * $ -- direct (the $ may be omitted)
;    * * -- A-field indirect
;    * @ -- B-field indirect
;    * { -- A-field indirect with predecrement
;    * < -- B-field indirect with predecrement
;    * } -- A-field indirect with postincrement
;    * > -- B-field indirect with postincrement


spl.ab     #     451     ,}     2;   (split the process to an immediate of something random)
mov.i      <     7       ,{     2;   (move the entire instruction to somewhere random)
mov.i      <     604     ,{    -3;   (move the entire instruction to somewhere random)
djn.x      $     527     ,<     153; (jump somewhere random and flip the fields)


