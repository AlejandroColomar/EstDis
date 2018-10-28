	.file	"about.c"
	.text
	.comm	share_path,4096,32
	.section	.rodata
.LC0:
	.string	"est-dis/"
.LC1:
	.string	"/usr/local/share/"
.LC2:
	.string	"%s/%s/"
	.text
	.globl	about_init
	.type	about_init, @function
about_init:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC0(%rip), %r8
	leaq	.LC1(%rip), %rcx
	leaq	.LC2(%rip), %rdx
	movl	$4096, %esi
	leaq	share_path(%rip), %rdi
	movl	$0, %eax
	call	snprintf@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	about_init, .-about_init
	.section	.rodata
.LC3:
	.string	"COPYRIGHT.txt"
.LC4:
	.string	"%s/%s"
.LC5:
	.string	"DISCLAIMER.txt"
.LC6:
	.string	"HELP.txt"
.LC7:
	.string	"LICENSE.txt"
.LC8:
	.string	"USAGE.txt"
.LC9:
	.string	"dist/binomial.txt"
.LC10:
	.string	"dist/poisson.txt"
.LC11:
	.string	"dist/geometric.txt"
.LC12:
	.string	"dist/hypergeometric.txt"
.LC13:
	.string	"dist/uniform.txt"
.LC14:
	.string	"dist/exponential.txt"
	.text
	.globl	snprint_share_file
	.type	snprint_share_file, @function
snprint_share_file:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4112, %rsp
	movq	%rdi, -4104(%rbp)
	movl	%esi, -4108(%rbp)
	movl	%edx, -4112(%rbp)
	cmpl	$10, -4112(%rbp)
	ja	.L3
	movl	-4112(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L5(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L5(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L5:
	.long	.L15-.L5
	.long	.L14-.L5
	.long	.L13-.L5
	.long	.L12-.L5
	.long	.L11-.L5
	.long	.L10-.L5
	.long	.L9-.L5
	.long	.L8-.L5
	.long	.L7-.L5
	.long	.L6-.L5
	.long	.L4-.L5
	.text
.L15:
	leaq	-4096(%rbp), %rax
	leaq	.LC3(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L14:
	leaq	-4096(%rbp), %rax
	leaq	.LC5(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L13:
	leaq	-4096(%rbp), %rax
	leaq	.LC6(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L12:
	leaq	-4096(%rbp), %rax
	leaq	.LC7(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L11:
	leaq	-4096(%rbp), %rax
	leaq	.LC8(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L10:
	leaq	-4096(%rbp), %rax
	leaq	.LC9(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L9:
	leaq	-4096(%rbp), %rax
	leaq	.LC10(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L8:
	leaq	-4096(%rbp), %rax
	leaq	.LC11(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L7:
	leaq	-4096(%rbp), %rax
	leaq	.LC12(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L6:
	leaq	-4096(%rbp), %rax
	leaq	.LC13(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	jmp	.L3
.L4:
	leaq	-4096(%rbp), %rax
	leaq	.LC14(%rip), %r8
	leaq	share_path(%rip), %rcx
	leaq	.LC4(%rip), %rdx
	movl	$4096, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
	nop
.L3:
	leaq	-4096(%rbp), %rdx
	movl	-4108(%rbp), %ecx
	movq	-4104(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	alx_snprint_file@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	snprint_share_file, .-snprint_share_file
	.section	.rodata
	.align 8
.LC15:
	.string	"\n\342\224\214\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\220"
.LC16:
	.string	"%s"
	.align 8
.LC17:
	.string	"\342\224\224\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\200\342\224\230\n"
	.text
	.globl	print_share_file
	.type	print_share_file, @function
print_share_file:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1048592, %rsp
	movl	%edi, -1048580(%rbp)
	movl	-1048580(%rbp), %edx
	leaq	-1048576(%rbp), %rax
	movl	$1048576, %esi
	movq	%rax, %rdi
	call	snprint_share_file
	leaq	.LC15(%rip), %rdi
	call	puts@PLT
	leaq	-1048576(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC16(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC17(%rip), %rdi
	call	puts@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	print_share_file, .-print_share_file
	.section	.rodata
.LC18:
	.string	"estadistica 3~a3\n"
	.text
	.globl	print_version
	.type	print_version, @function
print_version:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC18(%rip), %rdi
	call	puts@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	print_version, .-print_version
	.ident	"GCC: (Debian 8.2.0-8) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
