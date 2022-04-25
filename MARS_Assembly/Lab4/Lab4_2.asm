#Laboratory Exercise 4, Home Assignment 2
.text
	li $s0, 0x0563 	 #load test value for these function
	andi $t0, $s0, 0xff 	 #Extract the LSB of $s0
	andi $t1, $s0, 0x0400 #Extract bit 10 of $s0
	addi $s1, $zero, 24	#1
loop:  srlv $t2, $s0, $s1	#2
	addi $s1, $s1, -1	#3
	blt  $t2, 0x80,loop  #Extract MSB of $s0 (#1-#4 loop)
	andi $t3, $s0, 0xff00 #Clear LSB of $s0
	ori $t4, $s0, 0x00ff  #Set LSB of $s0 (bits 7 to 0 are set to 1)
	andi $t5, $s0, 0x00	 #Clear $s0 (s0=0, must use logical instructions)