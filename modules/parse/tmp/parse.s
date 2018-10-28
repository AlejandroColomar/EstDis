	.file	"parse.c"
	.text
	.section	.rodata
.LC2:
	.string	"start"
.LC3:
	.string	"Verbose"
.LC8:
	.string	"param-c"
.LC9:
	.string	"param-n"
.LC10:
	.string	"param-N"
.LC11:
	.string	"param-r"
.LC12:
	.string	"param-a"
.LC13:
	.string	"param-b"
.LC14:
	.string	"param-p"
.LC15:
	.string	"param-x0"
.LC16:
	.string	"param-x1"
.LC17:
	.string	"param-x2"
.LC18:
	.string	"param-beta"
.LC19:
	.string	"param-lambda"
.LC26:
	.string	"hls:V:vx"
.LC0:
	.string	"help"
.LC1:
	.string	"license"
.LC4:
	.string	"version"
.LC5:
	.string	"exit"
.LC6:
	.string	"copyright"
.LC7:
	.string	"warranty"
	.data
	.align 32
.LC21:
	.quad	.LC0
	.long	0
	.zero	4
	.quad	0
	.long	104
	.zero	4
	.quad	.LC1
	.long	0
	.zero	4
	.quad	0
	.long	108
	.zero	4
	.quad	.LC2
	.long	1
	.zero	4
	.quad	0
	.long	115
	.zero	4
	.quad	.LC3
	.long	1
	.zero	4
	.quad	0
	.long	86
	.zero	4
	.quad	.LC4
	.long	0
	.zero	4
	.quad	0
	.long	118
	.zero	4
	.quad	.LC5
	.long	0
	.zero	4
	.quad	0
	.long	120
	.zero	4
	.quad	.LC6
	.long	0
	.zero	4
	.quad	0
	.long	10000
	.zero	4
	.quad	.LC7
	.long	0
	.zero	4
	.quad	0
	.long	10001
	.zero	4
	.quad	.LC8
	.long	1
	.zero	4
	.quad	0
	.long	10002
	.zero	4
	.quad	.LC9
	.long	1
	.zero	4
	.quad	0
	.long	10003
	.zero	4
	.quad	.LC10
	.long	1
	.zero	4
	.quad	0
	.long	10004
	.zero	4
	.quad	.LC11
	.long	1
	.zero	4
	.quad	0
	.long	10005
	.zero	4
	.quad	.LC12
	.long	1
	.zero	4
	.quad	0
	.long	10006
	.zero	4
	.quad	.LC13
	.long	1
	.zero	4
	.quad	0
	.long	10007
	.zero	4
	.quad	.LC14
	.long	1
	.zero	4
	.quad	0
	.long	10008
	.zero	4
	.quad	.LC15
	.long	1
	.zero	4
	.quad	0
	.long	10009
	.zero	4
	.quad	.LC16
	.long	1
	.zero	4
	.quad	0
	.long	10010
	.zero	4
	.quad	.LC17
	.long	1
	.zero	4
	.quad	0
	.long	10011
	.zero	4
	.quad	.LC18
	.long	1
	.zero	4
	.quad	0
	.long	10012
	.zero	4
	.quad	.LC19
	.long	1
	.zero	4
	.quad	0
	.long	10013
	.zero	4
	.quad	0
	.long	0
	.zero	4
	.quad	0
	.long	0
	.zero	4
	.text
	.globl	parser
	.type	parser, @function
parser:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$704, %rsp
	movl	%edi, -692(%rbp)
	movq	%rsi, -704(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	leaq	-688(%rbp), %rax
	leaq	.LC21(%rip), %rdx
	movl	$84, %ecx
	movq	%rax, %rdi
	movq	%rdx, %rsi
	rep movsq
	jmp	.L2
.L44:
	cmpl	$10003, -4(%rbp)
	je	.L3
	cmpl	$10003, -4(%rbp)
	jg	.L4
	cmpl	$118, -4(%rbp)
	je	.L5
	cmpl	$118, -4(%rbp)
	jg	.L6
	cmpl	$104, -4(%rbp)
	je	.L7
	cmpl	$104, -4(%rbp)
	jg	.L8
	cmpl	$86, -4(%rbp)
	je	.L9
	jmp	.L10
.L8:
	cmpl	$108, -4(%rbp)
	je	.L11
	cmpl	$115, -4(%rbp)
	je	.L12
	jmp	.L10
.L6:
	cmpl	$10000, -4(%rbp)
	je	.L13
	cmpl	$10000, -4(%rbp)
	jg	.L14
	cmpl	$120, -4(%rbp)
	je	.L15
	jmp	.L10
.L14:
	cmpl	$10001, -4(%rbp)
	je	.L16
	cmpl	$10002, -4(%rbp)
	je	.L17
	jmp	.L10
.L4:
	cmpl	$10008, -4(%rbp)
	je	.L18
	cmpl	$10008, -4(%rbp)
	jg	.L19
	cmpl	$10005, -4(%rbp)
	je	.L20
	cmpl	$10005, -4(%rbp)
	jl	.L21
	cmpl	$10006, -4(%rbp)
	je	.L22
	cmpl	$10007, -4(%rbp)
	je	.L23
	jmp	.L10
.L19:
	cmpl	$10011, -4(%rbp)
	je	.L24
	cmpl	$10011, -4(%rbp)
	jg	.L25
	cmpl	$10009, -4(%rbp)
	je	.L26
	cmpl	$10010, -4(%rbp)
	je	.L27
	jmp	.L10
.L25:
	cmpl	$10012, -4(%rbp)
	je	.L28
	cmpl	$10013, -4(%rbp)
	je	.L29
	jmp	.L10
.L7:
	movl	$2, %edi
	call	print_share_file@PLT
	movl	$0, %edi
	call	exit@PLT
.L11:
	movl	$3, %edi
	call	print_share_file@PLT
	movl	$0, %edi
	call	exit@PLT
.L12:
	movq	optarg(%rip), %rax
	movl	$10, %r8d
	movl	$0, %ecx
	leaq	flag_s(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	call	parse_int
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L9:
	movq	optarg(%rip), %rax
	movl	$4, %r8d
	movl	$0, %ecx
	leaq	flag_V(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	call	parse_int
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L5:
	call	print_version@PLT
	movl	$0, %edi
	call	exit@PLT
.L15:
	movb	$1, flag_x(%rip)
	jmp	.L2
.L13:
	movl	$0, %edi
	call	print_share_file@PLT
	movl	$0, %edi
	call	exit@PLT
.L16:
	movl	$1, %edi
	call	print_share_file@PLT
	movl	$0, %edi
	call	exit@PLT
.L17:
	movq	optarg(%rip), %rax
	movl	$3, %r8d
	movl	$0, %ecx
	leaq	param_i_c(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC8(%rip), %rdi
	call	parse_int
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L3:
	movq	optarg(%rip), %rax
	movabsq	$9223372036854775807, %r8
	movl	$0, %ecx
	leaq	param_i_n(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC9(%rip), %rdi
	call	parse_int
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L21:
	movq	optarg(%rip), %rax
	movabsq	$9223372036854775807, %r8
	movl	$0, %ecx
	leaq	param_i_N(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC10(%rip), %rdi
	call	parse_int
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L20:
	movq	optarg(%rip), %rax
	movabsq	$9223372036854775807, %r8
	movl	$0, %ecx
	leaq	param_i_r(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	call	parse_int
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L22:
	movq	optarg(%rip), %rax
	movsd	.LC22(%rip), %xmm1
	movsd	.LC23(%rip), %xmm0
	leaq	param_a(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC12(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L23:
	movsd	param_a(%rip), %xmm0
	movq	optarg(%rip), %rax
	movsd	.LC22(%rip), %xmm1
	leaq	param_b(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC13(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L18:
	movq	optarg(%rip), %rax
	movsd	.LC24(%rip), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	leaq	param_p(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC14(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L26:
	movq	optarg(%rip), %rax
	movsd	.LC22(%rip), %xmm1
	movsd	.LC23(%rip), %xmm0
	leaq	param_x_dbl(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC15(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L27:
	movq	optarg(%rip), %rax
	movsd	.LC22(%rip), %xmm1
	movsd	.LC23(%rip), %xmm0
	leaq	8+param_x_dbl(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC16(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L24:
	movsd	8+param_x_dbl(%rip), %xmm0
	movq	optarg(%rip), %rax
	movsd	.LC22(%rip), %xmm1
	leaq	16+param_x_dbl(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC17(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L28:
	movq	optarg(%rip), %rax
	movsd	.LC22(%rip), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	leaq	param_beta(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC18(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L29:
	movq	optarg(%rip), %rax
	movsd	.LC22(%rip), %xmm0
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	leaq	param_lambda(%rip), %rdx
	movq	%rax, %rsi
	leaq	.LC19(%rip), %rdi
	call	parse_dbl
	testq	%rax, %rax
	je	.L2
	movl	$1, %edi
	call	exit@PLT
.L10:
	movl	$4, %edi
	call	print_share_file@PLT
	movl	$1, %edi
	call	exit@PLT
.L2:
	leaq	-8(%rbp), %rcx
	leaq	-688(%rbp), %rdx
	movq	-704(%rbp), %rsi
	movl	-692(%rbp), %eax
	movq	%rcx, %r8
	movq	%rdx, %rcx
	leaq	.LC26(%rip), %rdx
	movl	%eax, %edi
	call	getopt_long@PLT
	movl	%eax, -4(%rbp)
	cmpl	$-1, -4(%rbp)
	jne	.L44
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	parser, .-parser
	.section	.rodata
.LC27:
	.string	" %li"
.LC28:
	.string	"%s argument not valid\n"
	.align 8
.LC29:
	.string	"It must be greater an integer [%li U %li]\n"
.LC30:
	.string	"NaN"
	.text
	.type	parse_int, @function
parse_int:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	%rcx, -48(%rbp)
	movq	%r8, -56(%rbp)
	movq	$0, -8(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rax
	leaq	.LC27(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sscanf@PLT
	cmpl	$1, %eax
	jne	.L46
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -48(%rbp)
	jg	.L47
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, -56(%rbp)
	jge	.L49
.L47:
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC28(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	-56(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC29(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	$1, -8(%rbp)
	jmp	.L49
.L46:
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC28(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC30(%rip), %rdi
	call	puts@PLT
	movq	$2, -8(%rbp)
.L49:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	parse_int, .-parse_int
	.section	.rodata
.LC31:
	.string	" %lf"
	.align 8
.LC32:
	.string	"It must be greater an integer [%lf U %lf]\n"
	.text
	.type	parse_dbl, @function
parse_dbl:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movsd	%xmm0, -48(%rbp)
	movsd	%xmm1, -56(%rbp)
	movq	$0, -8(%rbp)
	movq	-40(%rbp), %rdx
	movq	-32(%rbp), %rax
	leaq	.LC31(%rip), %rsi
	movq	%rax, %rdi
	movl	$0, %eax
	call	sscanf@PLT
	cmpl	$1, %eax
	jne	.L51
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm1
	movsd	-48(%rbp), %xmm0
	comisd	%xmm1, %xmm0
	ja	.L52
	movq	-40(%rbp), %rax
	movsd	(%rax), %xmm0
	comisd	-56(%rbp), %xmm0
	jbe	.L55
.L52:
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC28(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	-56(%rbp), %xmm1
	movsd	-48(%rbp), %xmm0
	leaq	.LC32(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movq	$1, -8(%rbp)
	jmp	.L55
.L51:
	movq	-24(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC28(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC30(%rip), %rdi
	call	puts@PLT
	movq	$2, -8(%rbp)
.L55:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	parse_dbl, .-parse_dbl
	.section	.rodata
	.align 8
.LC22:
	.long	0
	.long	2146435072
	.align 8
.LC23:
	.long	0
	.long	-1048576
	.align 8
.LC24:
	.long	0
	.long	1072693248
	.ident	"GCC: (Debian 8.2.0-8) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
