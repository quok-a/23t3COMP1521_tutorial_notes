	.text
	.file	"q8.c"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	leaq	-14(%rbp), %rsi
	movl	$0, -4(%rbp)
	movq	.L__const.main.str, %rax
	movq	%rax, -14(%rbp)
	movw	.L__const.main.str+8, %cx
	movw	%cx, -6(%rbp)
	movabsq	$.L.str, %rdi
	movb	$0, %al
	callq	printf
	xorl	%edx, %edx
	movl	%eax, -20(%rbp)                 # 4-byte Spill
	movl	%edx, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.type	.L__const.main.str,@object      # @__const.main.str
	.section	.rodata,"a",@progbits
.L__const.main.str:
	.byte	72                              # 0x48
	.byte	105                             # 0x69
	.zero	8
	.size	.L__const.main.str, 10

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"%s\n"
	.size	.L.str, 4

	.ident	"Debian clang version 11.0.1-2"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym printf
