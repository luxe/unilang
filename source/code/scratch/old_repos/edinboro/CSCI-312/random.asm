# Trevor Hickey
# Prof. Bennett
# CSCI 312 Spring 2012
# 03/02/2012 
# Code was written in MARS 4.2

# Program Description:
# This program gets a random number between 0 and 100


.data
message: .asciiz "Requesting Random Number From The Matrix...\n"
message2: .asciiz "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYour Random Number Is: "
newline: .asciiz "\n"
spaces: .asciiz "              "

.text

.globl main
main:

	#Print Message
	la $a0, message
	li $v0, 4
	syscall
	
	#Wait
	li $a0, 2000
	li $v0, 32
	syscall
	
	#Be Annoying
	li $a0, 80
	li $a1, 2000
	li $a2, 50
	li $a3, 127
	li $v0, 31
	syscall


add $t0, $zero, $zero
LOOP1: 
	add $t1, $zero, $zero
	LOOP2: 
		add $t2, $zero, $zero
		LOOP3:
		
			#Get Random Number Between 0 - 100
			li $a1, 9 #Upper bound
			li $v0, 42
			syscall
			#Print Random Number To The Screen
			li $v0, 1
			syscall
			
		#Restart Loop
		addi $t2, $t2, 1
		slti $t7, $t2, 5
		bne $t7, $zero, LOOP3
		
		#Add Spaces
		la $a0, spaces
		li $v0, 4
		syscall
		
	#Restart Loop
	addi $t1, $t1, 1
	slti $t7, $t1, 5
	bne $t7, $zero, LOOP2
	
	#Add Newline
	la $a0, newline
	li $v0, 4
	syscall
	
	#Wait
	li $a0, 10
	li $v0, 32
	syscall
		
#Restart Loop
addi $t0, $t0, 1
slti $t7, $t0, 200
bne $t7, $zero, LOOP1


	#Print Message
	la $a0, message2
	li $v0, 4
	syscall
	
	#Get Random Number Between 0 - 100
	li $a1, 100 #Upper bound                          
	li $v0, 42
	syscall
	
	#Print Random Number To The Screen
	li $v0, 1
	syscall 
	
	#Print Newline
	la $a0, newline
	li $v0, 4
	syscall

#Exit Safely
li $v0, 10
syscall
