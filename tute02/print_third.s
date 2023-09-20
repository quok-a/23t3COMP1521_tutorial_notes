# // Print every third number from 24 to 42.
	.text
main:
	li 	$t0, 24		# int x = 24;
count_loop:
	bge	$t0, 42, exit	# if (x >= 42) goto exit; 
	move 	$a0, $t0 	#printf("%d), y
	li 	$v0, 1
	syscall

	li 	$a0, '\n' 	#printf("\n")
	li 	$v0, 11
	syscall

	addi	$t0, 3		# x += 3;

	j 	count_loop	# goto count_loop

exit:
	jr	$ra		# return 0;