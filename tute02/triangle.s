	.text
main:
	li 	$t0, 1	# int i = 1;
loop_i:

	bgt 	$t0, 10, end_loop_i	# if (i > 10) goto end_loop_i;

	li 	$t1, 0	# int j = 0;
loop_j:

	bge	$t1, $t0, end_loop_j	# if (j >= i) goto end_loop_j; 
	
	li 	$a0, '*' # printf("*");    
	li 	$v0, 11
	syscall

	addi 	$t1, 1	# j++;

	j	loop_j	#     goto loop_j;

end_loop_j:
	li 	$a0, '\n' # printf("\n");    
	li 	$v0, 11
	syscall

	addi 	$t0, 1	#     i++;

	j	loop_i	#     goto loop_i;
    
end_loop_i:

	jr	$ra	#     return 0;