#Laboratory Exercise 4, Home Assignment 2
.data
message: .asciiz "TRUE"
.text
	li $s1, 100
	li $s2, 100
	slt $t0, $s2, $s1
	beq $t0, $zero, L
	j EXIT
L:
	li $v0, 4
	la $a0, message
	syscall
EXIT:
