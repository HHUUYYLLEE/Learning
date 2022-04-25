#Laboratory Exercise 3, Home Assignment 1
# $s1 = i
# $s2 = j
# $t1 = x
# $t2 = y
# $t3 = z
# $t4 = sumi+j
initialize: 
	li $s1, 6 # i = 6
	li $s2, 5 # j = 5
	li $t1, 10 # x = 10
	li $t2, 20 # y = 20
	li $t3, 30 # z = 30
	add $t4, $s1, $s2
start: 
	slt 	$t0,$zero,$t4 # i+j>0
	bne 	$t0,$zero,else # branch to else if i<j
	addi 	$t1,$t1,1 	# then part: x=x+1
	addi 	$t3,$zero,1 	# z=1 
	j endif 		# skip "else" part 
else:  
	addi 	$t2,$t2,-1 	# begin else part: y=y-1 
	add 	$t3,$t3,$t3 	# z=2*z
endif:
