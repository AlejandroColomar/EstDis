	.file	"start.c"
	.text
	.globl	start_switch
	.type	start_switch, @function
start_switch:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	flag_s(%rip), %rax
	cmpq	$9, %rax
	ja	.L14
	leaq	0(,%rax,4), %rdx
	leaq	.L4(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L4(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L15-.L4
	.long	.L12-.L4
	.long	.L11-.L4
	.long	.L10-.L4
	.long	.L9-.L4
	.long	.L8-.L4
	.long	.L15-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.text
.L12:
	call	desc_1var@PLT
	jmp	.L2
.L11:
	call	desc_2var@PLT
	jmp	.L2
.L10:
	call	dist_binomial@PLT
	jmp	.L2
.L9:
	call	dist_poisson@PLT
	jmp	.L2
.L8:
	call	dist_geometric@PLT
	jmp	.L2
.L6:
	call	dist_uniform@PLT
	jmp	.L2
.L5:
	call	dist_exponential@PLT
	jmp	.L2
.L3:
	call	dist_normal@PLT
	jmp	.L2
.L15:
	nop
.L2:
.L14:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	start_switch, .-start_switch
	.globl	help_switch
	.type	help_switch, @function
help_switch:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	flag_s(%rip), %rax
	cmpq	$9, %rax
	ja	.L29
	leaq	0(,%rax,4), %rdx
	leaq	.L19(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L19(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L19:
	.long	.L30-.L19
	.long	.L30-.L19
	.long	.L30-.L19
	.long	.L25-.L19
	.long	.L24-.L19
	.long	.L23-.L19
	.long	.L22-.L19
	.long	.L21-.L19
	.long	.L20-.L19
	.long	.L30-.L19
	.text
.L25:
	movl	$5, %edi
	call	print_share_file@PLT
	jmp	.L17
.L24:
	movl	$6, %edi
	call	print_share_file@PLT
	jmp	.L17
.L23:
	movl	$7, %edi
	call	print_share_file@PLT
	jmp	.L17
.L22:
	movl	$8, %edi
	call	print_share_file@PLT
	jmp	.L17
.L21:
	movl	$9, %edi
	call	print_share_file@PLT
	jmp	.L17
.L20:
	movl	$10, %edi
	call	print_share_file@PLT
	jmp	.L17
.L30:
	nop
.L17:
.L29:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	help_switch, .-help_switch
	.ident	"GCC: (Debian 8.2.0-8) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
