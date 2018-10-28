	.file	"alx_ncur.c"
	.text
	.globl	alx_start_curses
	.type	alx_start_curses, @function
alx_start_curses:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	initscr@PLT
	call	nonl@PLT
	call	cbreak@PLT
	call	noecho@PLT
	movq	stdscr(%rip), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	keypad@PLT
	call	has_colors@PLT
	testb	%al, %al
	je	.L3
	call	start_color@PLT
	call	use_default_colors@PLT
.L3:
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	alx_start_curses, .-alx_start_curses
	.globl	alx_pause_curses
	.type	alx_pause_curses, @function
alx_pause_curses:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	call	def_prog_mode@PLT
	call	endwin@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	alx_pause_curses, .-alx_pause_curses
	.globl	alx_resume_curses
	.type	alx_resume_curses, @function
alx_resume_curses:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	stdout(%rip), %rax
	movq	%rax, %rdi
	call	fflush@PLT
	call	reset_prog_mode@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	alx_resume_curses, .-alx_resume_curses
	.globl	alx_end_curses
	.type	alx_end_curses, @function
alx_end_curses:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	stdscr(%rip), %rax
	movq	%rax, %rdi
	call	wclear@PLT
	movq	stdscr(%rip), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	call	endwin@PLT
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	alx_end_curses, .-alx_end_curses
	.globl	alx_win_del
	.type	alx_win_del, @function
alx_win_del:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	wclear@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	delwin@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	alx_win_del, .-alx_win_del
	.globl	alx_menu
	.type	alx_menu, @function
alx_menu:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -36(%rbp)
	movl	%esi, -40(%rbp)
	movl	%edx, -44(%rbp)
	movq	%rcx, -56(%rbp)
	movq	%r8, -64(%rbp)
	movl	$1, -4(%rbp)
	movl	$80, %eax
	subl	-40(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -8(%rbp)
	movl	-8(%rbp), %ecx
	movl	-4(%rbp), %edx
	movl	-40(%rbp), %esi
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -16(%rbp)
	movq	-64(%rbp), %rcx
	movq	-56(%rbp), %rdx
	movl	-44(%rbp), %esi
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	alx_menu_2
	movl	%eax, -20(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movl	-20(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	alx_menu, .-alx_menu
	.globl	alx_menu_2
	.type	alx_menu_2, @function
alx_menu_2:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	-24(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	keypad@PLT
	call	noecho@PLT
	movq	-24(%rbp), %rax
	subq	$8, %rsp
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wborder@PLT
	addq	$32, %rsp
	movq	-48(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alx_ncur_prn_title
	movq	-40(%rbp), %rdx
	movl	-28(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	alx_ncur_prn_menu
	movq	-40(%rbp), %rdx
	movl	-28(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	alx_ncur_usr_sel
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	alx_menu_2, .-alx_menu_2
	.section	.rodata
	.align 8
.LC0:
	.string	"Introduce a real number [%lf U %lf] (default %lf)"
.LC1:
	.string	"%s"
	.text
	.globl	alx_w_getdbl
	.type	alx_w_getdbl, @function
alx_w_getdbl:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	%edi, -84(%rbp)
	movl	%esi, -88(%rbp)
	movq	%rdx, -96(%rbp)
	movsd	%xmm0, -104(%rbp)
	movsd	%xmm1, -112(%rbp)
	movsd	%xmm2, -120(%rbp)
	movq	%rcx, -128(%rbp)
	movl	$3, -4(%rbp)
	movl	-84(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-88(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$80, %eax
	subl	-84(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-8(%rbp), %eax
	subl	$4, %eax
	movl	%eax, -24(%rbp)
	movl	-12(%rbp), %eax
	addl	$3, %eax
	movl	%eax, -28(%rbp)
	movl	-16(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -32(%rbp)
	movl	$1, -36(%rbp)
	movl	-8(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -40(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-56(%rbp), %rax
	subq	$8, %rsp
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wborder@PLT
	addq	$32, %rsp
	movq	-96(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alx_ncur_prn_title
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-32(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -64(%rbp)
	cmpq	$0, -128(%rbp)
	jne	.L13
	movsd	-112(%rbp), %xmm2
	movsd	-120(%rbp), %xmm1
	movsd	-104(%rbp), %xmm0
	movq	-64(%rbp), %rax
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	movl	$3, %eax
	call	wprintw@PLT
	jmp	.L14
.L13:
	movq	-128(%rbp), %rdx
	movq	-64(%rbp), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	wprintw@PLT
.L14:
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-48(%rbp), %ecx
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %esi
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movsd	-120(%rbp), %xmm2
	movsd	-112(%rbp), %xmm1
	movsd	-104(%rbp), %xmm0
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	loop_w_getdbl
	movq	%xmm0, %rax
	movq	%rax, -80(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movsd	-80(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	alx_w_getdbl, .-alx_w_getdbl
	.section	.rodata
	.align 8
.LC2:
	.string	"Introduce an integer number [%lf U %lf] (default %li)"
	.text
	.globl	alx_w_getint
	.type	alx_w_getint, @function
alx_w_getint:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movl	%edi, -84(%rbp)
	movl	%esi, -88(%rbp)
	movq	%rdx, -96(%rbp)
	movsd	%xmm0, -104(%rbp)
	movq	%rcx, -112(%rbp)
	movsd	%xmm1, -120(%rbp)
	movq	%r8, -128(%rbp)
	movl	$3, -4(%rbp)
	movl	-84(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-88(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$80, %eax
	subl	-84(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-8(%rbp), %eax
	subl	$4, %eax
	movl	%eax, -24(%rbp)
	movl	-12(%rbp), %eax
	addl	$3, %eax
	movl	%eax, -28(%rbp)
	movl	-16(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -32(%rbp)
	movl	$1, -36(%rbp)
	movl	-8(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -40(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-56(%rbp), %rax
	subq	$8, %rsp
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wborder@PLT
	addq	$32, %rsp
	movq	-96(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alx_ncur_prn_title
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-32(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -64(%rbp)
	cmpq	$0, -128(%rbp)
	jne	.L17
	movq	-112(%rbp), %rdx
	movsd	-120(%rbp), %xmm1
	movsd	-104(%rbp), %xmm0
	movq	-64(%rbp), %rax
	leaq	.LC2(%rip), %rsi
	movq	%rax, %rdi
	movl	$2, %eax
	call	wprintw@PLT
	jmp	.L18
.L17:
	movq	-128(%rbp), %rdx
	movq	-64(%rbp), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	wprintw@PLT
.L18:
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-48(%rbp), %ecx
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %esi
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movsd	-120(%rbp), %xmm1
	movq	-112(%rbp), %rdx
	movsd	-104(%rbp), %xmm0
	movq	-72(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	loop_w_getint
	movl	%eax, -76(%rbp)
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movl	-76(%rbp), %eax
	cltq
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	alx_w_getint, .-alx_w_getint
	.section	.rodata
.LC3:
	.string	"Introduce a string"
	.text
	.globl	alx_w_getstr
	.type	alx_w_getstr, @function
alx_w_getstr:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movq	%rdi, -88(%rbp)
	movl	%esi, -92(%rbp)
	movl	%edx, -96(%rbp)
	movl	%ecx, -100(%rbp)
	movq	%r8, -112(%rbp)
	movq	%r9, -120(%rbp)
	movl	$3, -4(%rbp)
	movl	-96(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-100(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$80, %eax
	subl	-96(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-8(%rbp), %eax
	subl	$4, %eax
	movl	%eax, -24(%rbp)
	movl	-12(%rbp), %eax
	addl	$3, %eax
	movl	%eax, -28(%rbp)
	movl	-16(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -32(%rbp)
	movl	$1, -36(%rbp)
	movl	-8(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -40(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-56(%rbp), %rax
	subq	$8, %rsp
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wborder@PLT
	addq	$32, %rsp
	movq	-112(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alx_ncur_prn_title
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-32(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -64(%rbp)
	cmpq	$0, -120(%rbp)
	jne	.L21
	movq	-64(%rbp), %rax
	movl	$-1, %edx
	leaq	.LC3(%rip), %rsi
	movq	%rax, %rdi
	call	waddnstr@PLT
	jmp	.L22
.L21:
	movq	-120(%rbp), %rdx
	movq	-64(%rbp), %rax
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	wprintw@PLT
.L22:
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-48(%rbp), %ecx
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %esi
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movq	-72(%rbp), %rdx
	movl	-92(%rbp), %ecx
	movq	-88(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	loop_w_getstr
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	alx_w_getstr, .-alx_w_getstr
	.section	.rodata
.LC4:
	.string	"Introduce a file name"
	.text
	.globl	alx_w_getfname
	.type	alx_w_getfname, @function
alx_w_getfname:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	addq	$-128, %rsp
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movl	%edx, %eax
	movl	%ecx, -104(%rbp)
	movl	%r8d, -108(%rbp)
	movq	%r9, -120(%rbp)
	movb	%al, -100(%rbp)
	movl	$3, -4(%rbp)
	movl	-104(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-108(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	$80, %eax
	subl	-104(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -16(%rbp)
	movl	$1, -20(%rbp)
	movl	-8(%rbp), %eax
	subl	$4, %eax
	movl	%eax, -24(%rbp)
	movl	-12(%rbp), %eax
	addl	$3, %eax
	movl	%eax, -28(%rbp)
	movl	-16(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -32(%rbp)
	movl	$1, -36(%rbp)
	movl	-8(%rbp), %eax
	subl	$2, %eax
	movl	%eax, -40(%rbp)
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -44(%rbp)
	movl	-16(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -48(%rbp)
	movl	-16(%rbp), %ecx
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %esi
	movl	-4(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -56(%rbp)
	movq	-56(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-56(%rbp), %rax
	subq	$8, %rsp
	pushq	$0
	pushq	$0
	pushq	$0
	movl	$0, %r9d
	movl	$0, %r8d
	movl	$0, %ecx
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wborder@PLT
	addq	$32, %rsp
	movq	-120(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alx_ncur_prn_title
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-32(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %esi
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -64(%rbp)
	cmpq	$0, 16(%rbp)
	jne	.L24
	movq	-64(%rbp), %rax
	movl	$-1, %edx
	leaq	.LC4(%rip), %rsi
	movq	%rax, %rdi
	call	waddnstr@PLT
	jmp	.L25
.L24:
	movq	-64(%rbp), %rax
	movq	16(%rbp), %rdx
	leaq	.LC1(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	wprintw@PLT
.L25:
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	-48(%rbp), %ecx
	movl	-44(%rbp), %edx
	movl	-40(%rbp), %esi
	movl	-36(%rbp), %eax
	movl	%eax, %edi
	call	newwin@PLT
	movq	%rax, -72(%rbp)
	movq	-72(%rbp), %rax
	movl	$262144, %esi
	movq	%rax, %rdi
	call	wbkgd@PLT
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movzbl	-100(%rbp), %edx
	movq	-72(%rbp), %rcx
	movq	-96(%rbp), %rsi
	movq	-88(%rbp), %rax
	movq	%rax, %rdi
	call	loop_w_getfname
	movq	-72(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	movq	-56(%rbp), %rax
	movq	%rax, %rdi
	call	alx_win_del
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	alx_w_getfname, .-alx_w_getfname
	.section	.rodata
.LC5:
	.string	" %s "
	.text
	.globl	alx_ncur_prn_title
	.type	alx_ncur_prn_title, @function
alx_ncur_prn_title:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L27
	movq	-24(%rbp), %rax
	movzwl	4(%rax), %eax
	cwtl
	addl	$1, %eax
	jmp	.L28
.L27:
	movl	$-1, %eax
.L28:
	movl	%eax, -4(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L29
	movq	-24(%rbp), %rax
	movzwl	6(%rax), %eax
	cwtl
	addl	$1, %eax
	jmp	.L30
.L29:
	movl	$-1, %eax
.L30:
	movl	%eax, -8(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	leal	2(%rax), %edx
	movl	-8(%rbp), %eax
	subl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L32
	movq	936+acs_map(%rip), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	waddch@PLT
.L32:
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	wprintw@PLT
	movq	928+acs_map(%rip), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	waddch@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	alx_ncur_prn_title, .-alx_ncur_prn_title
	.globl	alx_ncur_prn_subtitle
	.type	alx_ncur_prn_subtitle, @function
alx_ncur_prn_subtitle:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L34
	movq	-24(%rbp), %rax
	movzwl	4(%rax), %eax
	cwtl
	addl	$1, %eax
	jmp	.L35
.L34:
	movl	$-1, %eax
.L35:
	movl	%eax, -4(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L36
	movq	-24(%rbp), %rax
	movzwl	6(%rax), %eax
	cwtl
	addl	$1, %eax
	jmp	.L37
.L36:
	movl	$-1, %eax
.L37:
	movl	%eax, -8(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movl	%eax, -12(%rbp)
	movl	-12(%rbp), %eax
	leal	2(%rax), %edx
	movl	-8(%rbp), %eax
	subl	%edx, %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	leal	-1(%rax), %edx
	movl	-4(%rbp), %eax
	leal	-1(%rax), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L39
	movq	936+acs_map(%rip), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	waddch@PLT
.L39:
	movq	-32(%rbp), %rdx
	movq	-24(%rbp), %rax
	leaq	.LC5(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	wprintw@PLT
	movq	928+acs_map(%rip), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	waddch@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	alx_ncur_prn_subtitle, .-alx_ncur_prn_subtitle
	.type	alx_ncur_prn_menu, @function
alx_ncur_prn_menu:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L41
	movq	-24(%rbp), %rax
	movzwl	4(%rax), %eax
	cwtl
	addl	$1, %eax
	jmp	.L42
.L41:
	movl	$-1, %eax
.L42:
	movl	%eax, -8(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L43
	movq	-24(%rbp), %rax
	movzwl	6(%rax), %eax
	cwtl
	addl	$1, %eax
	jmp	.L44
.L43:
	movl	$-1, %eax
.L44:
	movl	%eax, -12(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L45
.L48:
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L47
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movq	8(%rax), %rcx
	movq	-24(%rbp), %rax
	movl	$-1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	waddnstr@PLT
.L47:
	addl	$1, -4(%rbp)
.L45:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L48
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	alx_ncur_prn_menu, .-alx_ncur_prn_menu
	.type	alx_ncur_usr_sel, @function
alx_ncur_usr_sel:
.LFB14:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movq	%rdx, -40(%rbp)
	movl	$1, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %eax
	leal	1(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	movb	$1, -5(%rbp)
	jmp	.L50
.L63:
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	wgetch@PLT
	movl	%eax, -12(%rbp)
	cmpl	$107, -12(%rbp)
	je	.L51
	cmpl	$107, -12(%rbp)
	jg	.L52
	cmpl	$13, -12(%rbp)
	je	.L53
	cmpl	$13, -12(%rbp)
	jg	.L54
	cmpl	$10, -12(%rbp)
	je	.L53
	jmp	.L55
.L54:
	cmpl	$32, -12(%rbp)
	je	.L53
	cmpl	$106, -12(%rbp)
	je	.L56
	jmp	.L55
.L52:
	cmpl	$119, -12(%rbp)
	je	.L51
	cmpl	$119, -12(%rbp)
	jg	.L57
	cmpl	$115, -12(%rbp)
	je	.L56
	jmp	.L55
.L57:
	cmpl	$258, -12(%rbp)
	je	.L56
	cmpl	$259, -12(%rbp)
	jne	.L55
.L51:
	cmpl	$0, -4(%rbp)
	je	.L58
	subl	$1, -4(%rbp)
	jmp	.L59
.L58:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	movl	%eax, -4(%rbp)
.L59:
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %eax
	leal	1(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	jmp	.L50
.L56:
	movl	-28(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%rbp)
	je	.L60
	addl	$1, -4(%rbp)
	jmp	.L61
.L60:
	movl	$0, -4(%rbp)
.L61:
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %eax
	leal	1(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	jmp	.L50
.L53:
	movb	$0, -5(%rbp)
	jmp	.L50
.L55:
	cmpl	$47, -12(%rbp)
	jle	.L65
	movl	-28(%rbp), %eax
	addl	$47, %eax
	cmpl	%eax, -12(%rbp)
	jg	.L65
	movl	-12(%rbp), %eax
	subl	$48, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movl	4(%rax), %eax
	leal	1(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rcx
	movq	-40(%rbp), %rax
	addq	%rcx, %rax
	movl	(%rax), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	movb	$0, -5(%rbp)
.L65:
	nop
.L50:
	cmpb	$0, -5(%rbp)
	jne	.L63
	movl	-4(%rbp), %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	alx_ncur_usr_sel, .-alx_ncur_usr_sel
	.type	loop_w_getdbl, @function
loop_w_getdbl:
.LFB15:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1088, %rsp
	movq	%rdi, -1064(%rbp)
	movsd	%xmm0, -1072(%rbp)
	movsd	%xmm1, -1080(%rbp)
	movsd	%xmm2, -1088(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L67
.L75:
	call	echo@PLT
	movq	-1064(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L68
	leaq	-1040(%rbp), %rcx
	movq	-1064(%rbp), %rax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	wgetnstr@PLT
	jmp	.L69
.L68:
	movl	$-1, %eax
.L69:
	movl	%eax, -12(%rbp)
	call	noecho@PLT
	movq	-1064(%rbp), %rax
	movq	%rax, %rdi
	call	wclear@PLT
	movq	-1064(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	cmpl	$-1, -12(%rbp)
	jne	.L70
	movl	$5, -8(%rbp)
	jmp	.L71
.L70:
	leaq	-1040(%rbp), %rdx
	movsd	-1088(%rbp), %xmm2
	movsd	-1080(%rbp), %xmm1
	movsd	-1072(%rbp), %xmm0
	leaq	-1048(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	alx_sscan_dbl@PLT
	movl	%eax, -8(%rbp)
.L71:
	cmpl	$0, -8(%rbp)
	je	.L77
	movl	-8(%rbp), %edx
	movq	-1064(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	manage_w_error
	addl	$1, -4(%rbp)
.L67:
	cmpl	$1, -4(%rbp)
	jle	.L75
	jmp	.L74
.L77:
	nop
.L74:
	movsd	-1048(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	loop_w_getdbl, .-loop_w_getdbl
	.type	loop_w_getint, @function
loop_w_getint:
.LFB16:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1088, %rsp
	movq	%rdi, -1064(%rbp)
	movsd	%xmm0, -1072(%rbp)
	movq	%rsi, -1080(%rbp)
	movsd	%xmm1, -1088(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L79
.L87:
	call	echo@PLT
	movq	-1064(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L80
	leaq	-1040(%rbp), %rcx
	movq	-1064(%rbp), %rax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	wgetnstr@PLT
	jmp	.L81
.L80:
	movl	$-1, %eax
.L81:
	movl	%eax, -12(%rbp)
	call	noecho@PLT
	movq	-1064(%rbp), %rax
	movq	%rax, %rdi
	call	wclear@PLT
	movq	-1064(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	cmpl	$-1, -12(%rbp)
	jne	.L82
	movl	$5, -8(%rbp)
	jmp	.L83
.L82:
	leaq	-1040(%rbp), %rdx
	movsd	-1088(%rbp), %xmm1
	movq	-1080(%rbp), %rcx
	movsd	-1072(%rbp), %xmm0
	leaq	-1048(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	alx_sscan_int@PLT
	movl	%eax, -8(%rbp)
.L83:
	cmpl	$0, -8(%rbp)
	je	.L89
	movl	-8(%rbp), %edx
	movq	-1064(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	manage_w_error
	addl	$1, -4(%rbp)
.L79:
	cmpl	$1, -4(%rbp)
	jle	.L87
	jmp	.L86
.L89:
	nop
.L86:
	movq	-1048(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	loop_w_getint, .-loop_w_getint
	.type	loop_w_getstr, @function
loop_w_getstr:
.LFB17:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$1072, %rsp
	movq	%rdi, -1048(%rbp)
	movl	%esi, -1052(%rbp)
	movq	%rdx, -1064(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L91
.L99:
	call	echo@PLT
	movq	-1064(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L92
	leaq	-1040(%rbp), %rcx
	movq	-1064(%rbp), %rax
	movl	$1024, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	wgetnstr@PLT
	jmp	.L93
.L92:
	movl	$-1, %eax
.L93:
	movl	%eax, -12(%rbp)
	call	noecho@PLT
	movq	-1064(%rbp), %rax
	movq	%rax, %rdi
	call	wclear@PLT
	movq	-1064(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movl	$0, -8(%rbp)
	cmpl	$-1, -12(%rbp)
	jne	.L101
	movl	$5, -8(%rbp)
	cmpl	$0, -8(%rbp)
	je	.L102
	movl	-8(%rbp), %edx
	movq	-1064(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	manage_w_error
	addl	$1, -4(%rbp)
.L91:
	cmpl	$1, -4(%rbp)
	jle	.L99
	jmp	.L96
.L101:
	nop
	jmp	.L96
.L102:
	nop
.L96:
	cmpl	$0, -8(%rbp)
	jne	.L103
	movl	-1052(%rbp), %eax
	movslq	%eax, %rsi
	leaq	-1040(%rbp), %rdx
	movq	-1048(%rbp), %rax
	movq	%rdx, %rcx
	leaq	.LC1(%rip), %rdx
	movq	%rax, %rdi
	movl	$0, %eax
	call	snprintf@PLT
.L103:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE17:
	.size	loop_w_getstr, .-loop_w_getstr
	.type	loop_w_getfname, @function
loop_w_getfname:
.LFB18:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4144, %rsp
	movq	%rdi, -4120(%rbp)
	movq	%rsi, -4128(%rbp)
	movl	%edx, %eax
	movq	%rcx, -4144(%rbp)
	movb	%al, -4132(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L105
.L113:
	call	echo@PLT
	movq	-4144(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L106
	leaq	-4112(%rbp), %rcx
	movq	-4144(%rbp), %rax
	movl	$4096, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	wgetnstr@PLT
	jmp	.L107
.L106:
	movl	$-1, %eax
.L107:
	movl	%eax, -12(%rbp)
	call	noecho@PLT
	movq	-4144(%rbp), %rax
	movq	%rax, %rdi
	call	wclear@PLT
	movq	-4144(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	cmpl	$-1, -12(%rbp)
	jne	.L108
	movl	$5, -8(%rbp)
	jmp	.L109
.L108:
	movzbl	-4132(%rbp), %edx
	leaq	-4112(%rbp), %rcx
	movq	-4128(%rbp), %rsi
	movq	-4120(%rbp), %rax
	movq	%rax, %rdi
	call	alx_sscan_fname@PLT
	movl	%eax, -8(%rbp)
.L109:
	cmpl	$0, -8(%rbp)
	je	.L114
	movl	-8(%rbp), %edx
	movq	-4144(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	manage_w_error
	addl	$1, -4(%rbp)
.L105:
	cmpl	$1, -4(%rbp)
	jle	.L113
	jmp	.L112
.L114:
	nop
.L112:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	loop_w_getfname, .-loop_w_getfname
	.section	.rodata
.LC6:
	.string	"\302\241 Number is out of range !"
.LC7:
	.string	"\302\241 sscanf() error !"
.LC8:
	.string	"\302\241 wgetstr() error !"
.LC9:
	.string	"\302\241 FILE error !"
	.text
	.type	manage_w_error, @function
manage_w_error:
.LFB19:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	cmpl	$2, -12(%rbp)
	je	.L116
	cmpl	$2, -12(%rbp)
	jg	.L117
	cmpl	$1, -12(%rbp)
	je	.L118
	jmp	.L119
.L117:
	cmpl	$3, -12(%rbp)
	je	.L120
	cmpl	$5, -12(%rbp)
	je	.L121
	jmp	.L119
.L118:
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L130
	movq	-8(%rbp), %rax
	movl	$-1, %edx
	leaq	.LC6(%rip), %rsi
	movq	%rax, %rdi
	call	waddnstr@PLT
	jmp	.L130
.L116:
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L131
	movq	-8(%rbp), %rax
	movl	$-1, %edx
	leaq	.LC7(%rip), %rsi
	movq	%rax, %rdi
	call	waddnstr@PLT
	jmp	.L131
.L121:
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L132
	movq	-8(%rbp), %rax
	movl	$-1, %edx
	leaq	.LC8(%rip), %rsi
	movq	%rax, %rdi
	call	waddnstr@PLT
	jmp	.L132
.L120:
	movq	-8(%rbp), %rax
	movl	$0, %edx
	movl	$0, %esi
	movq	%rax, %rdi
	call	wmove@PLT
	cmpl	$-1, %eax
	je	.L133
	movq	-8(%rbp), %rax
	movl	$-1, %edx
	leaq	.LC9(%rip), %rsi
	movq	%rax, %rdi
	call	waddnstr@PLT
	jmp	.L133
.L130:
	nop
	jmp	.L119
.L131:
	nop
	jmp	.L119
.L132:
	nop
	jmp	.L119
.L133:
	nop
.L119:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	wgetch@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	wclear@PLT
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	wrefresh@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE19:
	.size	manage_w_error, .-manage_w_error
	.ident	"GCC: (Debian 8.2.0-8) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
