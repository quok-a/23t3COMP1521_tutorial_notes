	.text
FLAG_ROWS = 6
FLAG_COLS = 12

main:
# int main(void) {
	li 	$t0, 0 			# int row = 0;
loop1:
					#     //for (int row = 0; row < FLAG_ROWS; row++) {
	bge 	$t0, FLAG_ROWS, exit 	# if (row >= FLAG_ROWS) goto exit;
	li 	$t1, 0			#     int col = 0;
loop2:
	bge 	$t1, FLAG_COLS, end_loop2 # if (col >= FLAG_COLS) goto end_loop2;
					#     //for (int col = 0; col < FLAG_COLS; col++) {
	mul 	$t2, $t0, FLAG_COLS		# calulate flag[row][col]
	add	$t3, $t1, $t2
	# mul  sizeof(type)

	la 	$t4, flag
	add 	$t4, $t4, $t3

	li	$v0, 11			#     printf("%c", flag[row][col]);
	lb	$a0, ($t4)
	syscall

	addi	$t1, 1			#     col++;
	b	loop2
end_loop2:

	li	$a0, '\n'
	li	$v0, 11			#     printf("\n");
	syscall
	addi 	$t0, 1			#     row++;
	b	loop1

exit:
	li 	$v0, 0			#     return 0;
	jr	$ra

	.data
flag:
	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    	.byte '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'
    	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'
    	.byte '#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'