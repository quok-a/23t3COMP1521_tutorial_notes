	.text

change:

prologue:
	begin
	push	$ra
	push	$s0
	push	$s1
# void change (int nrows, int ncols, int M[nrows][ncols], int factor)
	li	$s0, 0
change_row:
	bge	$s0, $a0, change_row_end	#     for (int row = 0; row < nrows; row++) {

	li	$s1, 0
change_col:
	bge	$s1, $a1, change_col_end	#         for (int col = 0; col < ncols; col++) {
						#             M[row][col] = factor * M[row][col];
	mul	$t0, $s0, $a0			# get &M[row][col]
	add	$t0, $t0, $s1
	li 	$t4, 4
	mul	$t0, $t0, $t4
	add 	$t0, $t0, $a2

	lw	$t1, ($t0)
	mul	$t1, $t1, $a3

	addi	$s1, 1
	b 	change_col
change_col_end:

	addi 	$s0, 1
	b	change_row
change_row_end:

epiloge:
	pop	$s1
	pop	$s0
	pop	$ra
	end

	jr 	$ra
#     }
# }