# Prints the square of a number

main:
	la 	$a0, prompt # printf("Enter a number: ")'
	li 	$v0, 4 # syscall 4, print
	syscall

	li 	$v0, 5 # scanf("%d", x);
	syscall
	move 	$t0, $v0

	mul 	$t1, $t0, $t0 # y = x * x

	move 	$a0, $t1 # print y
	li 	$v0, 1
	syscall

	li 	$a0, ' ' # li $a0, '/n'
	li	$v0, 11
	syscall

	move 	$a0, $t0 # print x
	li 	$v0, 1
	syscall

	li 	$a0, '\n' # li $a0, '/n'
	li	$v0, 11
	syscall

	jr $ra 		#return


	.data
prompt:
	.asciiz "Enter a number: "