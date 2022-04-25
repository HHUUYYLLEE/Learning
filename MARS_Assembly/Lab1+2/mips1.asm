.data# Vùng du lieu, chua cac khai bao bien
message:  .asciiz  "Hello World"
.text               # Vung lenh, chua cac lenh hop ngu
	la	$a0, message      #Dua dia chi bien message vao thanh ghi a0
	li	$v0, 4           #Gan thanh ghi$v0 = 4
	syscall                #Goi ham so v0, ham so 1, la ham printinteger
	addi 	$t1,$zero,2       #Thanh ghi$t1= 2
	addi 	$t2,$zero,3       #Thanh ghi$t2= 3
	add  	$t0, $t1, $t2     #Thanh ghi t-=$t1+$t2
