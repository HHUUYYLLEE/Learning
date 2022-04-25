
	addi $s1, $0, 2147483647 
	addi $s2, $0, 10
	li $t0,0
	addu $s3,$s1,$s2
	xor $t1,$s1,$s2
	bltz $t1,EXIT
	xor $t2, $s3, $s1 
	bltz $t2, OVERFLOW 
	j EXIT 
OVERFLOW: 
	li $t0,1
EXIT: