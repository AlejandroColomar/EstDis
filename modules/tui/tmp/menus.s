	.file	"menus.c"
	.text
	.section	.rodata
.LC0:
	.string	"[0]\tExit program"
.LC1:
	.string	"[1]\tContinue"
.LC2:
	.string	"[2]\tDisclaimer of warranty"
.LC3:
	.string	"[3]\tTerms & conditions"
.LC4:
	.string	"MENU:"
	.text
	.globl	menu_main
	.type	menu_main, @function
menu_main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	$23, -8(%rbp)
	movl	$80, -12(%rbp)
	movl	$4, -16(%rbp)
	movl	$8, -96(%rbp)
	movl	$4, -92(%rbp)
	leaq	.LC0(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$2, -80(%rbp)
	movl	$4, -76(%rbp)
	leaq	.LC1(%rip), %rax
	movq	%rax, -72(%rbp)
	movl	$4, -64(%rbp)
	movl	$4, -60(%rbp)
	leaq	.LC2(%rip), %rax
	movq	%rax, -56(%rbp)
	movl	$5, -48(%rbp)
	movl	$4, -44(%rbp)
	leaq	.LC3(%rip), %rax
	movq	%rax, -40(%rbp)
	movb	$1, -1(%rbp)
	jmp	.L2
.L8:
	leaq	-96(%rbp), %rcx
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %esi
	movl	-8(%rbp), %eax
	leaq	.LC4(%rip), %r8
	movl	%eax, %edi
	call	alx_menu@PLT
	movl	%eax, -20(%rbp)
	cmpl	$1, -20(%rbp)
	je	.L3
	cmpl	$1, -20(%rbp)
	jg	.L4
	cmpl	$0, -20(%rbp)
	je	.L5
	jmp	.L2
.L4:
	cmpl	$2, -20(%rbp)
	je	.L6
	cmpl	$3, -20(%rbp)
	je	.L7
	jmp	.L2
.L5:
	movb	$0, -1(%rbp)
	jmp	.L2
.L3:
	call	menu_continue
	jmp	.L2
.L6:
	call	alx_pause_curses@PLT
	movl	$1, %edi
	call	print_share_file@PLT
	call	getchar@PLT
	call	alx_resume_curses@PLT
	jmp	.L2
.L7:
	call	alx_pause_curses@PLT
	movl	$3, %edi
	call	print_share_file@PLT
	call	getchar@PLT
	call	alx_resume_curses@PLT
	nop
.L2:
	cmpb	$0, -1(%rbp)
	jne	.L8
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	menu_main, .-menu_main
	.section	.rodata
.LC5:
	.string	"[0]\tBack"
.LC6:
	.string	"[1]\tRun"
.LC7:
	.string	"[2]\tHelp"
.LC8:
	.string	"[3]\tSelect problem type"
.LC9:
	.string	"[4]\tChange verbose"
.LC10:
	.string	"CONTINUE:"
	.text
	.type	menu_continue, @function
menu_continue:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movl	$23, -8(%rbp)
	movl	$80, -12(%rbp)
	movl	$5, -16(%rbp)
	movl	$7, -112(%rbp)
	movl	$4, -108(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, -104(%rbp)
	movl	$2, -96(%rbp)
	movl	$4, -92(%rbp)
	leaq	.LC6(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$3, -80(%rbp)
	movl	$4, -76(%rbp)
	leaq	.LC7(%rip), %rax
	movq	%rax, -72(%rbp)
	movl	$4, -64(%rbp)
	movl	$4, -60(%rbp)
	leaq	.LC8(%rip), %rax
	movq	%rax, -56(%rbp)
	movl	$5, -48(%rbp)
	movl	$4, -44(%rbp)
	leaq	.LC9(%rip), %rax
	movq	%rax, -40(%rbp)
	movb	$1, -1(%rbp)
	jmp	.L10
.L17:
	leaq	-112(%rbp), %rcx
	movl	-16(%rbp), %edx
	movl	-12(%rbp), %esi
	movl	-8(%rbp), %eax
	leaq	.LC10(%rip), %r8
	movl	%eax, %edi
	call	alx_menu@PLT
	movl	%eax, -20(%rbp)
	cmpl	$4, -20(%rbp)
	ja	.L10
	movl	-20(%rbp), %eax
	leaq	0(,%rax,4), %rdx
	leaq	.L12(%rip), %rax
	movl	(%rdx,%rax), %eax
	cltq
	leaq	.L12(%rip), %rdx
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L12:
	.long	.L16-.L12
	.long	.L15-.L12
	.long	.L14-.L12
	.long	.L13-.L12
	.long	.L11-.L12
	.text
.L16:
	movb	$0, -1(%rbp)
	jmp	.L10
.L15:
	call	alx_pause_curses@PLT
	call	start_switch@PLT
	call	alx_resume_curses@PLT
	jmp	.L10
.L14:
	call	alx_pause_curses@PLT
	call	help_switch@PLT
	call	alx_resume_curses@PLT
	jmp	.L10
.L13:
	call	menu_select
	jmp	.L10
.L11:
	call	menu_verbose
	nop
.L10:
	cmpb	$0, -1(%rbp)
	jne	.L17
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	menu_continue, .-menu_continue
	.section	.rodata
.LC11:
	.string	"[1]\t1 Variable"
.LC12:
	.string	"[2]\t2 Variables"
.LC13:
	.string	"[3]\tBinomial"
.LC14:
	.string	"[4]\tPoisson"
.LC15:
	.string	"[5]\tGeometrica"
.LC16:
	.string	"[6]\tHipergeometrica"
.LC17:
	.string	"[7]\tUniforme"
.LC18:
	.string	"[8]\tExponencial"
.LC19:
	.string	"[9]\tGauss(Normal)"
.LC20:
	.string	"SELECT:"
	.text
	.type	menu_select, @function
menu_select:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$176, %rsp
	movl	$23, -4(%rbp)
	movl	$80, -8(%rbp)
	movl	$10, -12(%rbp)
	movl	$13, -176(%rbp)
	movl	$4, -172(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, -168(%rbp)
	movl	$2, -160(%rbp)
	movl	$4, -156(%rbp)
	leaq	.LC11(%rip), %rax
	movq	%rax, -152(%rbp)
	movl	$3, -144(%rbp)
	movl	$4, -140(%rbp)
	leaq	.LC12(%rip), %rax
	movq	%rax, -136(%rbp)
	movl	$5, -128(%rbp)
	movl	$4, -124(%rbp)
	leaq	.LC13(%rip), %rax
	movq	%rax, -120(%rbp)
	movl	$6, -112(%rbp)
	movl	$4, -108(%rbp)
	leaq	.LC14(%rip), %rax
	movq	%rax, -104(%rbp)
	movl	$7, -96(%rbp)
	movl	$4, -92(%rbp)
	leaq	.LC15(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$8, -80(%rbp)
	movl	$4, -76(%rbp)
	leaq	.LC16(%rip), %rax
	movq	%rax, -72(%rbp)
	movl	$9, -64(%rbp)
	movl	$4, -60(%rbp)
	leaq	.LC17(%rip), %rax
	movq	%rax, -56(%rbp)
	movl	$10, -48(%rbp)
	movl	$4, -44(%rbp)
	leaq	.LC18(%rip), %rax
	movq	%rax, -40(%rbp)
	movl	$11, -32(%rbp)
	movl	$4, -28(%rbp)
	leaq	.LC19(%rip), %rax
	movq	%rax, -24(%rbp)
	leaq	-176(%rbp), %rcx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	leaq	.LC20(%rip), %r8
	movl	%eax, %edi
	call	alx_menu@PLT
	movl	%eax, -16(%rbp)
	cmpl	$0, -16(%rbp)
	je	.L20
	movl	-16(%rbp), %eax
	cltq
	movq	%rax, flag_s(%rip)
.L20:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	menu_select, .-menu_select
	.section	.rodata
.LC21:
	.string	"[0]\tShow NOTHING"
.LC22:
	.string	"[1]\tShow only solution"
.LC23:
	.string	"[2]\tShow short help"
.LC24:
	.string	"[3]\tShow help"
.LC25:
	.string	"[4]\tShow everything  (DBG)"
.LC26:
	.string	"VERBOSE:"
	.text
	.type	menu_verbose, @function
menu_verbose:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$96, %rsp
	movl	$23, -4(%rbp)
	movl	$80, -8(%rbp)
	movl	$5, -12(%rbp)
	movl	$7, -96(%rbp)
	movl	$4, -92(%rbp)
	leaq	.LC21(%rip), %rax
	movq	%rax, -88(%rbp)
	movl	$2, -80(%rbp)
	movl	$4, -76(%rbp)
	leaq	.LC22(%rip), %rax
	movq	%rax, -72(%rbp)
	movl	$3, -64(%rbp)
	movl	$4, -60(%rbp)
	leaq	.LC23(%rip), %rax
	movq	%rax, -56(%rbp)
	movl	$4, -48(%rbp)
	movl	$4, -44(%rbp)
	leaq	.LC24(%rip), %rax
	movq	%rax, -40(%rbp)
	movl	$5, -32(%rbp)
	movl	$4, -28(%rbp)
	leaq	.LC25(%rip), %rax
	movq	%rax, -24(%rbp)
	leaq	-96(%rbp), %rcx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	leaq	.LC26(%rip), %r8
	movl	%eax, %edi
	call	alx_menu@PLT
	cltq
	movq	%rax, flag_V(%rip)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	menu_verbose, .-menu_verbose
	.ident	"GCC: (Debian 8.2.0-8) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
