	.text
	
max:	# int max(int array[], int length) { // int array = $a0, int length = $a1
max__prologue:
	begin
	push 	$ra
	push	$s0 			# preserve value of register after fn call

max__body:
	lw	$s0, ($a0) 		# int first_element = array[0];

	bne 	$a1, 1, else_case	# if (length != 1) goto else_case;
	# // Handle the base-case of the recursion, at the end of the array.
	move 	$v0, $s0		# return first_element;
	b 	max__epilogue

else_case: 
# // Recurse on the rest of the array.
# // Finds the largest element after first_element in the array.
	addi	$a0, 4			# int max_so_far = max(&array[1], length - 1);
	addi 	$a1, -1
	jal	max
	move	$t0, $v0
# // Compare this element with the largest element after it in the array.
	
	ble	$s0, $t0, else_case2	# if (first_element <= max_so_far) goto else_case2
	move	$t0, $s0		# max_so_far = first_element;

else_case2:
	move 	$v0, $t0		# return max_so_far;

max__epilogue:
	pop	$s0
	pop	$ra
	end

	jr 	$ra

main:
main__prologue:
	begin
	push	$ra

main__body:
	la	$a0, array
	li	$a1, 10
	jal	max			# result = max(array, 10)

	move	$a0, $v0
	li	$v0, 1			# syscall 1: print_int
	syscall				# printf("%d", result)

	li	$a0, '\n'
	li	$v0, 11			# syscall 11: print_char
	syscall				# printf("%c", '\n');

	li	$v0, 0

main__epilogue:
	pop	$ra
	end
	jr	$ra			# return 0;


.data
array:
	.word 1, 2, 3, 4, 5, 6, 4, 3, 2, 1