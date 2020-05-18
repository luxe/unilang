# Trevor Hickey
# Code was written in MARS 4.2
#-----------------------------------------------------------------------------------------------------+
# Program Description:                                                                                |
# This program uses the Heap Permutation algorithm to generate all 362,880 posibilities for           |
# a 3x3 grid of single valued integers.                                                               |
# Each index of the 3x3 grid is a unique value between or including 1 to 9                            |
# Each posibility will be analyzed to see if it is a magic square.                                    |
#+--------------------------------------------------------------+ +-----------------------------------+
#|         These are the 8 perfect squares generated:           | |  All rows, columns and diagonals  |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |            sum to 15              |
#| | 2 | 9 | 4 |   | 2 | 7 | 6 |   | 4 | 3 | 8 |   | 4 | 9 | 2 || |                                   |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |                                   |
#| | 7 | 5 | 3 |   | 9 | 5 | 1 |   | 9 | 5 | 1 |   | 3 | 5 | 7 || |                                   |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |           15  15  15  15          |
#| | 6 | 1 | 8 |   | 4 | 3 | 8 |   | 2 | 7 | 6 |   | 8 | 1 | 6 || |        \  |   |   |  /            |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |         +---+---+---+             |
#|                                                              | |         | # | # | # |--15         |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |         +---+---+---+             |
#| | 6 | 7 | 2 |   | 6 | 1 | 8 |   | 8 | 3 | 4 |   | 8 | 1 | 6 || |         | # | 5 | # |--15         |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |         +---+---+---+             |
#| | 1 | 5 | 9 |   | 7 | 5 | 3 |   | 1 | 5 | 9 |   | 3 | 5 | 7 || |         | # | # | # |--15         |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |         +---+---+---+             |
#| | 8 | 3 | 4 |   | 2 | 9 | 4 |   | 6 | 7 | 2 |   | 4 | 9 | 2 || |        /  |   |   |  \            |
#| +---+---+---+   +---+---+---+   +---+---+---+   +---+---+---+| |                       15          |
#+--------------------------------------------------------------+ +-----------------------------------+
#+----------------------------------------------------------------------------------------------------+
#|00|                                     C++ Code Implementation                                     |
#|01| #include <iostream>                                                                             |
#|02| #include <cstdlib>                                                                              |
#|03|                                                                                                 |
#|04| void HeapPermute(int len, int l[]);                                                             |
#|05| void PrintIfMagic(int len, int square[]);                                                       |
#|06| void Print(int len, int square[]);                                                              |
#|07|                                                                                                 |
#|08| int main(){                                                                                     |
#|09|                                                                                                 |
#|10|     int square[9] = {1,2,3,4,5,6,7,8,9};                                                        |
#|11|                                                                                                 |
#|12|     HeapPermute(9,square);                                                                      |
#|13|                                                                                                 |
#|14|     return EXIT_SUCCESS;                                                                        |
#|15| }                                                                                               |
#|16|                                                                                                 |
#|17| void HeapPermute(int len, int l[]){                                                             |
#|18|     if (len == 0){                                                                              |
#|19|         PrintIfPerfect(9,l);                                                                    |
#|20|     }                                                                                           |
#|21|     else{                                                                                       |
#|22|         for (int i = 0; i < len; ++i) {                                                         |
#|23|             HeapPermute(len-1, l);                                                              |
#|24|                                                                                                 |
#|25|             if (len %2 ==1){                                                                    |
#|26|                 std::swap(l[0],l[len-1]); ///even                                               |
#|27|             }                                                                                   |
#|28|             else{                                                                               |
#|29|                 std::swap(l[i],l[len-1]); ///odd                                                |
#|30|             }                                                                                   |
#|31|         }                                                                                       |
#|32|     }                                                                                           |
#|33|     return;                                                                                     |
#|34| }                                                                                               |
#|35| void PrintIfMagic(int len, int square[]){                                                       |
#|36|                                                                                                 |
#|37|     int value = square[0] + square[3] + square[6];                                              |
#|38|                                                                                                 |
#|39|     if (square[1] + square[4] + square[7] == value &&                                           |
#|40|         square[2] + square[5] + square[8] == value &&                                           |
#|41|         square[0] + square[1] + square[2] == value &&                                           |
#|42|         square[3] + square[4] + square[5] == value &&                                           |
#|43|         square[6] + square[7] + square[8] == value &&                                           |
#|44|         square[0] + square[4] + square[8] == value &&                                           |
#|45|         square[2] + square[4] + square[6] == value){                                            |
#|46|             Print(9,square);                                                                    |
#|47|         }                                                                                       |
#|48|                                                                                                 |
#|49|     return;                                                                                     |
#|50| }                                                                                               |
#|51| void Print(int len, int square[]){                                                              |
#|52|                                                                                                 |
#|53|     using std::cout;                                                                            |
#|54|                                                                                                 |
#|55|     cout << square[0]; cout << square[1]; cout << square[2]<<'\n';                              |
#|56|     cout << square[3]; cout << square[4]; cout << square[5]<<'\n';                              |
#|57|     cout << square[6]; cout << square[7]; cout << square[8]<<'\n'<<'\n';                        |
#|58|                                                                                                 |
#|59|     return;                                                                                     |
#|60| }                                                                                               |
#+----------------------------------------------------------------------------------------------------+

 .data
 square:    .word    1,2,3,4,5,6,7,8,9 # a 1-dimensional array representing a 3X3 square
 length:    .word    9                 # the length of the array
 pipe:      .asciiz "|"
 endPipe:   .asciiz "|\n"
 message:   .asciiz "| Magic Happened!\n"
 endSquare: .asciiz "|\n\n"

                    .text
.globl main  ####################
   main:     # Algorithm Number #
#####################    ###############################################
#   ASSEMBLY CODE   #    #                  SUDO CODE                  #
#####################    ############################################### +-----------------------------------+
##Call HeapPermute  #    #                                             # |--------Registers/Variables--------|
 lw $a0, length     #    #  Load in the array and it's length before   # |                                   |
 la $a1, square     #    # calling: void HeapPermute(int len, int l[]) # | a0 = number of elements in array  |
 jal HEAP_PERMUTE   # 12 #                                             # | a1 = memory address of the array  |
#####################    ############################################### |                                   |
##Exit Safely       #    #                                             # |                                   |
 li $v0, 10         # 14 #                  return 0;                  # |                                   |
 syscall            #    #                                             # |                                   |
######################################################################## +-----------------------------------+
#----------------------------------------------------------------------#
HEAP_PERMUTE:#---------------------void HeapPermute(int len, int l[])--#
###########################    #########################################
#      ASSEMBLY CODE      #    #               SUDO CODE               #
###########################    ######################################### +-----------------------------------+
#Setup Activation Record  #    #     Manage Stack On Function Call     # |--------Registers/Variables--------|
 sw $fp,-4($sp)           #    # - save fp                             # |                                   |
 subiu $fp,$sp,4          #    # - point fp at the top of frame        # | t0 = number of elements in array  |
 sw $ra,-4($fp)           #    # - save ra in the frame                # | t1 = memory address of the array  |
 subiu $sp,$fp,4          #    # - set the sp for the new frame        # | t3 = index of the for loop        |
###########################    #                                       # |                                   |
 move $t0,$a0             #    #           Store Arguments             # | a0 = length of array - 1          |
 move $t1,$a1             #    #                                       # | a1 = memory address of the array  |
###########################    ######################################### |                                   |
 bne $t0, 1, ELSE         #    #                                       # |                                   |
     subiu $sp, $sp, 8    #    #      Check and see if the square      # |                                   |
     sw $t0, 0($sp)       #    #     is a magic square.  If it is,     # |                                   |
     sw $t1, 4($sp)       #    #            print the square           # |                                   |
     move $a0, $t1        #    #                                       # |                                   |
     jal PRINT_IF_MAGIC   # 19 #      if (len == 0){                   # |                                   |
     lw $t0, 0($sp)       #    #          PrintIfMagic(9,l);           # |                                   |
     lw $t1, 4($sp)        #    #     }                                # |                                   |
     addiu $sp, $sp, 8      #    #                                     # +-----------------------------------+
     j END_PERMUTE           #    #                                    #
###############################    #####################################
ELSE:                          #    #                                  #
    move $t3, $zero #index      #    #                                 #
    FOR_LOOP:                    # 22 #  for (int i=0; i<len; ++i) {   #
        bge $t3, $t0, END_PERMUTE #    #                               #
        subiu $sp, $sp, 16        #    #                               #
        sw $t0, 0($sp)            #    #                               #
        sw $t1, 4($sp)            #    #                               #
        sw $t2, 8($sp)            #    #           Manage Stack        #
        sw $t3, 12($sp)           #    #        On Recursive Call      #
        addi $a0, $t0, -1         #    #                               #
        move $a1, $t1             #    #                               #
        jal HEAP_PERMUTE          # 23 #      HeapPermute(len-1, l);   #
        lw $t0, 0($sp)            #    #                               #
        lw $t1, 4($sp)            #    #          Manage Stack         #
        lw $t2, 8($sp)            #    #      After Recursive Call     #
        lw $t3, 12($sp)           #    #                               #
        addiu $sp, $sp, 16        #    #                               #
        andi $t4, $t0, 1          #    #                               #
        SWAP_IF:                  #    #                               #
            bne $t4, 1, SWAP_ODD  # 25 #     if (len %2 ==1){          #
            move $t5, $ra         #    #                               #
            move $a0, $t1         #    #                               #
            sll $t6, $t0, 2       #    #                               #
            addi $t6, $t6, -4     #    #                               #
            add $a1, $t1, $t6     #    #                               #
            jal SWAP              # 26 #       swap(l[0],l[len-1]);    #
            move $ra, $t5         # 27 #     }                         #
            j END_SWAP            #    #                               #
        SWAP_ODD:                 # 28 #      else{                    #
            move $t5, $ra         #    #                               #
            sll $t7, $t3, 2       #    #                               #
            add $a0, $t1, $t7     #    #                               #
            sll    $t6, $t0, 2    #    #                               #
            addi $t6, $t6, -4     #    #                               #
            add $a1, $t1, $t6     #    #                               #
            jal SWAP              # 29 #      swap(l[i],l[len-1]);     #
            move $ra, $t5         # 30 #     }                         #
        END_SWAP:                 #    #                               #
        addi $t3, $t3, 1          # 31 #   }                           #
        j        FOR_LOOP         #    #                               #
    END_FOR_LOOP:                 # 32 # }                             #
 END_PERMUTE:                     #    #                               #
 lw $ra, -4($fp)                  #    #                               #
 addiu $sp, $fp, 4                #    #                               #
 lw $fp, 0($fp)                   #    #                               #
 jr $ra                           #    #                               #
#----------------------------------------------------------------------#
SWAP:#--------------------------------------void swap(value1, value2)--#
 lw $t9, ($a0)                                                         #
 lw $t8, ($a1)                                                         #
 sw $t9, ($a1)                                                         #
 sw $t8, ($a0)                                                         #
 jr $ra                                                                #
########################################################################
#----------------------------------------------------------------------#
PRINT_IF_MAGIC:#-------------void PrintIfMagic(int len, int square[])--#
###########################    #########################################
#      ASSEMBLY CODE      #    #               SUDO CODE               #
###########################    ######################################### +-----------------------------------+
#Setup Activation Record  #    #     Manage Stack On Function Call     # |--------Registers/Variables--------|
 sw $fp,-4($sp)           #    # - save fp                             # |                                   |
 subiu $fp,$sp,4          #    # - point fp at the top of frame        # | t1 = array row value              |
 sw $ra,-4($fp)           #    # - save ra in the frame                # | t2 = individual array value       |
 subiu $sp,$fp,4          #    # - set the sp for the new frame        # | t0 = memory address of the array  |
######################################################################## +-----------------------------------+
move $t0, $a0
li $t1, 0 #value they should all equal
li $t2, 0 #individual value of rows,colums,diag
################################################################  +---+---+---+
#get the value of top row                                 #    #  | ? + ? + ? = 15?
lw $t3, 0($t0)                                            #    #  +---+---+---+
lw $t4, 4($t0)                                            #    #  | # | # | # |
add $t1, $t3, $t4                                         #    #  +---+---+---+
lw $t3, 8($t0)                                            #    #  | # | # | # |
add $t1, $t1, $t3                                         #    #  +---+---+---+
###########################################################    #
#get the value of the second row                          #    #              +---+---+---+
lw $t3, 12($t0)                                           #    #              | # | # | # |
lw $t4, 16($t0)                                           #    #              +---+---+---+
add $t2, $t3, $t4                                         #    #              | ? + ? + ? = 15?
lw $t3, 20($t0)                                           #    #              +---+---+---+
add $t2, $t2, $t3                                         #    #              | # | # | # |
###########################################################    #              +---+---+---+
bne $t1 $t2 END_PRINT                                     #    #
#get the value of the third row                           #    #  +---+---+---+
lw $t3, 24($t0)                                           #    #  | # | # | # |
lw $t4, 28($t0)                                           #    #  +---+---+---+
add $t2, $t3, $t4                                         #    #  | # | # | # |
lw $t3, 32($t0)                                           #    #  +---+---+---+
add $t2, $t2, $t3                                         #    #  | ? + ? + ? = 15?
###########################################################    #  +---+---+---+
bne $t1 $t2 END_PRINT                                     #    #
#get the value of the first column                        #    #              +---+---+---+
lw $t3, 0($t0)                                            #    #              | ? | # | # |
lw $t4, 12($t0)                                           #    #              +-+-+---+---+
add $t2, $t3, $t4                                         #    #              | ? | # | # |
lw $t3, 24($t0)                                           #    #              +-+-+---+---+
add $t2, $t2, $t3                                         #    #              | ? | # | # |
###########################################################    #              +---+---+---+
bne $t1 $t2 END_PRINT                                     #    #                \\
#get the value of the second column                       #    #  +---+---+---+  15?
lw $t3, 4($t0)                                            #    #  | # | ? | # |
lw $t4, 16($t0)                                           #    #  +---+-+-+---+
add $t2, $t3, $t4                                         #    #  | # | ? | # |
lw $t3, 28($t0)                                           #    #  +---+-+-+---+
add $t2, $t2, $t3                                         #    #  | # | ? | # |
###########################################################    #  +---+---+---+
bne $t1 $t2 END_PRINT                                     #    #        \\
#get the value of the third column                        #    #         15?  +---+---+---+
lw $t3, 8($t0)                                            #    #              | # | # | ? |
lw $t4, 20($t0)                                           #    #              +---+---+-+-+
add $t2, $t3, $t4                                         #    #              | # | # | ? |
lw $t3, 32($t0)                                           #    #              +---+---+-+-+
add $t2, $t2, $t3                                         #    #              | # | # | ? |
###########################################################    #              +---+---+---+
bne $t1 $t2 END_PRINT                                     #    #  +---+---+---+         \\
#get the value of diagonal                                #    #  | ? | # | # |          15?
lw $t3, 0($t0)                                            #    #  +---+---+---+
lw $t4, 16($t0)                                           #    #  | # | ? | # |
add $t2, $t3, $t4                                         #    #  +---+---+---+
lw $t3, 32($t0)                                           #    #  | # | # | ? = 15?
add $t2, $t2, $t3                                         #    #  +---+---+---+
###########################################################    #
bne $t1 $t2 END_PRINT                                     #    #
#get the value of other diagonal                          #    #
lw $t3, 8($t0)                                            #    #
lw $t4, 16($t0)                                           #    #
add $t2, $t3, $t4                                         #    #
lw $t3, 24($t0)                                           #    #
add $t2, $t2, $t3                                         #    #
###########################################################    #
bne $t1 $t2 END_PRINT                                     #    #
la $a0, pipe                                              #    # Printing...  |
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
#print value 1                                            #    #
li $v0, 1                                                 #    #
lw $a0, 0($t0)                                            #    # Printing...  |#|
syscall                                                   #    #
la $a0, pipe                                              #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
#print value 2                                            #    #
li $v0, 1                                                 #    #
lw $a0, 4($t0)                                            #    # Printing...  |#|#|
syscall                                                   #    #
la $a0, pipe                                              #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
#print value 3                                            #    #
li $v0, 1                                                 #    #
lw $a0, 8($t0)                                            #    # Printing...  |#|#|#|
syscall                                                   #    #
la $a0, endPipe                                           #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
la $a0, pipe                                              #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
#print value 4                                            #    #
li $v0, 1                                                 #    # Printing...  |#|#|#|
lw $a0, 12($t0)                                           #    #              |#|
syscall                                                   #    #
la $a0, pipe                                              #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
#print value 5                                            #    #
li $v0, 1                                                 #    # Printing...  |#|#|#|
lw $a0, 16($t0)                                           #    #              |#|#|
syscall                                                   #    #
la $a0, pipe                                              #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
#print value 6                                            #    #
li $v0, 1                                                 #    #
lw $a0, 20($t0)                                           #    # Printing...  |#|#|#|
syscall                                                   #    #              |#|#|#| Magic Happened!
la $a0, message                                           #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
la $a0, pipe                                              #    #
li $v0, 4                                                 #    #
syscall                                                   #    #
#print value 7                                            #    #
li $v0, 1                                                 #    #
lw $a0, 24($t0)                                           #    # Printing...  |#|#|#|
syscall                                                   #    #              |#|#|#| Magic Happened!
la $a0, pipe                                              #    #              |#|
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
#print value 8                                            #    #
li $v0, 1                                                 #    #
lw $a0, 28($t0)                                           #    # Printing...  |#|#|#|
syscall                                                   #    #              |#|#|#| Magic Happened!
la $a0, pipe                                              #    #              |#|#|
li $v0, 4                                                 #    #
syscall                                                   #    #
###########################################################    #
#print value 9                                            #    #
li $v0, 1                                                 #    #
lw $a0, 32($t0)                                           #    # Printing...  |#|#|#|
syscall                                                   #    #              |#|#|#| Magic Happened!
la $a0, endSquare                                         #    #              |#|#|#|
li $v0, 4                                                 #    #
syscall                                                   #    #
j END_PRINT                                               #    #
###########################################################    #
END_PRINT:                                                #    #
 lw $ra,-4($fp)  #restore ra                              #    #
 addiu $sp,$fp,4 #restore $sp                             #    #
 lw $fp, 0($fp)  #restore $fp                             #    #
 jr $ra          #return to HEAP_PERMUTE                  #    #
################################################################
