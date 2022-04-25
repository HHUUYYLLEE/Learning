#Laboratory 3, Home Assigment 2 
.data
	i:	.word	-1 
	n:	.word	4
	step:	.word	1 
	sum:	.word	0 
	A:	.word	27, 27, 6, 9
.text
	la $t2, i # $s1 = i
	lw $s1, 0($t2) 
	la $t2, n 
	lw $s3, 0($t2) # $s3 = n
	la $t2, step 
	lw $s4, 0($t2) # $s4 = step
	la $t2, sum 
	lw $s5, 0($t2)# $s5 = sum
	la $s2, A # $s2 = A
loop: add $s1,$s1,$s4 #i=i+step 
      add $t1,$s1,$s1 #t1=2*s1 
      add $t1,$t1,$t1 #t1=4*s1 
      add $t1,$t1,$s2 #t1 store the address of A[i] 
      lw $t0,0($t1)   #load value of A[i] in $t0 
      add $s5,$s5,$t0 #sum-sum+A[i] 
      bne $s1,$s3,loop #if i := n, goto loop 