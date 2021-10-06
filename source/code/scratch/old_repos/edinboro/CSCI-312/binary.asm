# Trevor Hickey
# Prof. Bennett
# CSCI 312 Spring 2012
# 03/21/2012 
# Code was written in MARS 4.2

################################################################################
# Program Description:                                                         #
# This program outputs a 32-bit integer in binary representation               #
# The program does this using left shifts and the bitwise AND operator.        #
################################################################################

###############################################   ##############################
#              C CODE ALGORITHM               #   #    REGISTER DESCRIPTION    #
###############################################   ##############################
#                                             #   #                            #
#   1. input = GetInput();	                  #   #  t0 = index (stars at 31)  #
#   2. for (int i = 31; i >= 0; --i) {        #   #  t1 = 1 (used in shifts)   #
#   3. 	if (input & (1 << i))                 #   #  t2 = index << 1           #
#   4.		Ouput: "1"                        #   #  t3 = (num & t2)           #
#   5. 	else                                  #   #  t4 = num (user input)     #
#   6. 		Output: "0"                       #   #                            #
#      }                                      #   ##############################
#   7. Exit Program                           #
#                                             #
###############################################

###############################################
.data                                         #
dialog: .asciiz "Please enter an integer."    #
###############################################
                     .text                    #
.globl main   ####################            #
   main:      # Algorithm Number #            #
 #####################    #####################
 #   ASSEMBLY CODE   #    #     SUDO CODE     #
 #####################    #####################
 la $a0, dialog      #    #                   #
 li  $v0, 51         # 01 #   Get User Input  #
 syscall             #    #                   #
 #####################    #####################
 li $t0, 31          #    #  Store Variables  #
 li $t1, 1           #    #   Into Registers  #
 move $t4, $a0       #    #####################
 FOR_LOOP:           #    #                   #
 sllv $t2, $t1, $t0  # 02 # Loop Through Each #
 and $t3, $t4, $t2   #    #  Bit Of The Num   #
 beq $t3, $zero ELSE #    #                   #
 #####################    #####################
 #     print '1'     #    #                   #
 li $a0 1            #    # If Bit Operation  #
 li  $v0, 1          # 04 # Results True {    #
 syscall             #    #     Print: 1      #
 j ENDIF             #    # }                 #
 #####################    #####################
 #     print '0'     #    #                   #
 ELSE:               #    # If Bit Operation  #
 li $a0 0            # 06 # Results False {   #
 li  $v0, 1          #    #     Print: 0      #
 syscall             #    # }                 #
 #####################    #####################
 ENDIF:              #    #                   #
                     #    # Continue Loop if  #
 subi $t0, $t0, 1    #    #  Not At Last Bit  #
 bgez  $t0, FOR_LOOP #    #                   #
 #####################    #####################
  li $v0, 10         # 07 #     Exit          #
  syscall            #    #        Safely     #
 ##############################################
 

