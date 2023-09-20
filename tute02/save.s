	.text
main:
	la	$t0, information
	li	$t1, '1'
	sw 	$t1, ($t0)

info:
	.space 4

	.data
information:
	.space 4