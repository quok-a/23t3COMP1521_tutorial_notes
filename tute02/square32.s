# // Squares a number, unless its square is too big for a 32-bit integer.
# // If it is too big, prints an error message instead.

	.text
SQUARE_MAX = 46340 			#define SQUARE_MAX 46340

main:					# int main(void) {
					# int x, y in $t0, $t1

	la	$a0, prompt 		# printf("Enter a number: ");
	li 	$v0, 4
	syscall

	li 	$v0, 5			# scanf("%d", &x);
	syscall
	move 	$t0, $v0 


	bgt	$t0, SQUARE_MAX, x_gt_square_max	# if (x > SQUARE_MAX) goto x_gt_square_max;

	mul	$t1, $t0, $t0		# y = x * x;

	li 	$v0, 1
	syscall

	j	exit

x_gt_square_max:
	la	$a0, square_too_big 	# printf("square too big for 32 bits\n");
	li 	$v0, 4
	syscall
	
    
exit:
	jr	$ra 			#     return 0;

	.data
prompt:
	.asciiz "Enter a number: "

square_too_big:
	.asciiz "square too big for 32 bits\n"
