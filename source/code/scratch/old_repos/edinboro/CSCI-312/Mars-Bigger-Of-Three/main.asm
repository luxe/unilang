# Trevor Hickey
# Code was written in MARS 4.2

# Program Description:
# This program will ask for 3 integers from the user.
# Once it has validated all of the user data, it will return the
# number with the largest value.

# Algorithm
# 1. Prompt User
# 2. Get User Value
# 3. While (userInput is invalid){
#        Get User Value
#    }
# 4. Store value as largest number
# 5. Get 2nd User Value
# 6. While (userInput is invalid){
#        Get 2nd User Value
#    }
# 7. If (2nd User Value > Current User Value){
#        Store 2nd value as largest number
#    }
# 8. Get 3rd User Value
# 9. While (userInput is invalid){
#        Get 3nd User Value
#    }
# 10. If (3nd User Value > Current User Value){
#        Store 3nd value as largest number
#    }
# 11. Output The Largest Number To The User
# 12. Exit Program

.data
###################################################################################
purpose:  .asciiz "Enter 3 integers, and I will tell you which is the largest"    #
prompt1:  .asciiz "Please enter an integer value for number 1"                    #
prompt2:  .asciiz "Please enter an integer value for number 2"                    #
prompt3:  .asciiz "Please enter an integer value for number 3"                    #
prompt4:  .asciiz "The largest number you entered was "                           #
###################################################################################

                                                          .text
.globl main                                        ####################
main:                                              # Algorithm Number #
###########################################################    ###########################################################
#                      ASSEMBLY CODE                      #    #                        SUDO CODE                        #
###########################################################    #                                                         #
##Inform the user the purpose of the program              #    #                                                         #
 la $a0, purpose                                          #    #         PRINT:"Enter 3 integers, and I will tell        #
 li $a1, 1                                                # 01 #                 you which is the largest"               #
 li $v0, 55                                               #    #                                                         #
 syscall                                                  #    #                                                         #
##########################################################################################################################
##Get Value 1                                             #    #                                                         #
 PROMT_USER_FOR_VALUE_1: la $a0, prompt1                  #    #         Get User Value                                  #
    li $v0, 51                                            # 02 #         While (userInput is invalid){                   #
    syscall                                               # 03 #             Get User Value                              #
 bnez $a1, PROMT_USER_FOR_VALUE_1                         #    #         }                                               #
 la $t0, ($a0)                                            # 04 #         Store userInput as largest value                #
##########################################################################################################################
##Get Value 2                                             #    #         Get 2nd User Value                              #
 PROMT_USER_FOR_VALUE_2: la $a0, prompt2                  #    #         While (userInput is invalid){                   #
    li $v0, 51                                            # 05 #             Get 2nd User Value                          #
    syscall                                               # 06 #         }                                               #
 bnez $a1, PROMT_USER_FOR_VALUE_2                         #    #         If (2nd User Value > Current User Value){       #
 bgt $t0, $a0, SKIP                                       #    #             Store 2nd value as largest number           #
    la $t0, ($a0)                                         # 07 #         }                                               #
 SKIP:                                                    #    #                                                         #
##########################################################################################################################
##Get Value 3                                             #    #         Get 3rd User Value                              #
 PROMT_USER_FOR_VALUE_3: la $a0, prompt3                  #    #         While (userInput is invalid){                   #
    li $v0, 51                                            #    #             Get 3rd User Value                          #
    syscall                                               # 09 #         }                                               #
 bnez $a1, PROMT_USER_FOR_VALUE_3                         #    #         If (3rd User Value > Current User Value){       #
 bgt $t0, $a0, SKIP2                                      #    #             Store 3rd value as largest number           #
    la $t0, ($a0)                                         # 10 #         }                                               #
 SKIP2:                                                   #    #                                                         #
##########################################################################################################################
##Show User The Largest Number                            #    #                                                         #
 la $a0 prompt4                                           #    #                                                         #
 la $a1, ($t0)                                            # 11 #        PRINT:"The largest number you entered was        #
 li $v0, 56                                               #    #                      'largestNumber'                    #
 syscall                                                  #    #                                                         #
##########################################################################################################################
##Exit Safely                                             #    #                                                         #
 li $v0, 10                                               # 12 #                       return 0;                         #
 syscall                                                  #    #                                                         #
##########################################################################################################################
