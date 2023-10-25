
N_SIZE = 10
	.text

main:
	# $t0 = int i (loop counter)
	# $t1 = bytes to offset
	# $t2 = address of array (starting address/ base)
	# $t3 = address of numbers[i]
	# $t4 = numbers[i]

	li	$t0, 0		# int i = 0
loop:
	bge 	$t0, N_SIZE, loop_end #while (i < n_size)

				# calc &numbers[i]
				# address = base + offset*sizeof(element)
	mul	$t1, $t0, 4	# bytes to offset
	la	$t2, numbers	# load base address
	add 	$t3, $t1, $t2
	lw	$t4, ($t3)

	bgez	$t4, num_pos

	addi 	$t4, $t4, 42	# number[i] += 42;
	sw	$t4, ($t3)

num_pos:
	addi 	$t0, $t0, 1
	b	loop
loop_end:

	jr 	$ra
	.data
numbers:
	.word 0, 1, 2, -3, 4, -5, 6, -7, 8, 9	# int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};
