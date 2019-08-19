	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 14	sdk_version 10, 14
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	callq	_getpid
	leaq	L_.str(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -24(%rbp)         ## 4-byte Spill
	callq	_fork
	movl	%eax, -20(%rbp)
	cmpl	$0, -20(%rbp)
	jge	LBB0_2
## %bb.1:
	movq	___stderrp@GOTPCREL(%rip), %rax
	movq	(%rax), %rdi
	leaq	L_.str.1(%rip), %rsi
	movb	$0, %al
	callq	_fprintf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
	jmp	LBB0_6
LBB0_2:
	cmpl	$0, -20(%rbp)
	jne	LBB0_4
## %bb.3:
	callq	_getpid
	leaq	L_.str.2(%rip), %rdi
	movl	%eax, %esi
	movb	$0, %al
	callq	_printf
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jmp	LBB0_5
LBB0_4:
	movl	-20(%rbp), %esi
	movl	%esi, -36(%rbp)         ## 4-byte Spill
	callq	_getpid
	leaq	L_.str.3(%rip), %rdi
	movl	-36(%rbp), %esi         ## 4-byte Reload
	movl	%eax, %edx
	movb	$0, %al
	callq	_printf
	movl	%eax, -40(%rbp)         ## 4-byte Spill
LBB0_5:
	jmp	LBB0_6
LBB0_6:
	xorl	%eax, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"hello world (pid:%d)\n"

L_.str.1:                               ## @.str.1
	.asciz	"fork failed\n"

L_.str.2:                               ## @.str.2
	.asciz	"hello,I am child (pid:%d)"

L_.str.3:                               ## @.str.3
	.asciz	"hello,I am parent of %d (pid:%d)\n"


.subsections_via_symbols
