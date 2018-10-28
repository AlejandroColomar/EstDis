	.file	"dist.c"
	.text
	.section	.rodata
	.align 8
.LC1:
	.string	"\n________________________________________________________________________________"
.LC2:
	.string	"u\t= E(ni*xi)/n\t--Media."
	.align 8
.LC3:
	.string	"o2\t= E(xi^2)/n-u^2\t--Varianza."
	.align 8
.LC4:
	.string	"s2\t= o2*n/(n-1)\t--Cuasivarianza."
	.align 8
.LC5:
	.string	"o\t= sqrt(o2)\t--Desviacion tipica."
	.align 8
.LC6:
	.string	"s\t= sqrt(s2)\t--Cuasidesviacion tipica."
	.align 8
.LC7:
	.string	"CV\t= o/u\t\t--Coeficiente de variacion.\n"
.LC8:
	.string	"N:\t"
.LC11:
	.string	"x_%li:\t"
.LC14:
	.string	"n_%li:\t"
.LC15:
	.string	"\nu\t= %lf"
.LC16:
	.string	"\no2\t= %lf"
.LC17:
	.string	"\no\t= %lf"
.LC18:
	.string	"\ns2\t= %lf"
.LC19:
	.string	"\ns\t= %lf"
.LC20:
	.string	"\nCV\t= %lf\n"
	.text
	.globl	desc_1var
	.type	desc_1var, @function
desc_1var:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$80, %rsp
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	leaq	.LC3(%rip), %rdi
	call	puts@PLT
	leaq	.LC4(%rip), %rdi
	call	puts@PLT
	leaq	.LC5(%rip), %rdi
	call	puts@PLT
	leaq	.LC6(%rip), %rdi
	call	puts@PLT
	leaq	.LC7(%rip), %rdi
	call	puts@PLT
	movsd	.LC9(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	movl	$0, %edx
	leaq	.LC8(%rip), %rsi
	movl	$2, %edi
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_N(%rip)
	movq	$0, -8(%rbp)
	jmp	.L2
.L3:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	.LC12(%rip), %xmm2
	movsd	.LC10(%rip), %xmm1
	movsd	.LC13(%rip), %xmm0
	movl	$0, %esi
	movl	$0, %edi
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rcx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC14(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	.LC12(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	movl	$0, %esi
	movl	$0, %edi
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rcx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movl	$10, %edi
	call	putchar@PLT
	addq	$1, -8(%rbp)
.L2:
	movq	param_i_N(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L3
	movq	$0, -8(%rbp)
	jmp	.L4
.L5:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm0
	call	descrip_Exi@PLT
	movapd	%xmm0, %xmm1
	movsd	-24(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm0
	call	descrip_Exi2@PLT
	movapd	%xmm0, %xmm1
	movsd	-32(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -32(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm0
	call	descrip_Eni@PLT
	movapd	%xmm0, %xmm1
	movsd	-16(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	addq	$1, -8(%rbp)
.L4:
	movq	param_i_N(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L5
	movsd	-16(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	call	descrip_u@PLT
	movq	%xmm0, %rax
	movq	%rax, -40(%rbp)
	movsd	-40(%rbp), %xmm2
	movsd	-16(%rbp), %xmm1
	movsd	-32(%rbp), %xmm0
	call	descrip_o2@PLT
	movq	%xmm0, %rax
	movq	%rax, -48(%rbp)
	movsd	-48(%rbp), %xmm0
	call	descrip_o@PLT
	movq	%xmm0, %rax
	movq	%rax, -56(%rbp)
	movsd	-16(%rbp), %xmm1
	movsd	-48(%rbp), %xmm0
	call	descrip_s2@PLT
	movq	%xmm0, %rax
	movq	%rax, -64(%rbp)
	movsd	-64(%rbp), %xmm0
	call	descrip_s@PLT
	movq	%xmm0, %rax
	movq	%rax, -72(%rbp)
	movsd	-40(%rbp), %xmm1
	movsd	-56(%rbp), %xmm0
	call	descrip_CV@PLT
	movq	%xmm0, %rax
	movq	%rax, -80(%rbp)
	movsd	-40(%rbp), %xmm0
	leaq	.LC15(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-48(%rbp), %xmm0
	leaq	.LC16(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-56(%rbp), %xmm0
	leaq	.LC17(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-64(%rbp), %xmm0
	leaq	.LC18(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-72(%rbp), %xmm0
	leaq	.LC19(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-80(%rbp), %xmm0
	leaq	.LC20(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	desc_1var, .-desc_1var
	.section	.rodata
.LC21:
	.string	"u\t= E(xi)/n\t\t--Media."
	.align 8
.LC22:
	.string	"o2\t= E(xi^2)/n-u^2\t\t--Varianza."
	.align 8
.LC23:
	.string	"o\t= sqrt(o2)\t\t--Desviacion tipica."
	.align 8
.LC24:
	.string	"oxy\t= E(xi*yi)/n-ux*uy\t--Covarianza.\n"
.LC25:
	.string	"a\t= oxy/ox2\t\t--Pendiente."
.LC26:
	.string	"b\t= uy-a*ux\t\t--Sesgo."
	.align 8
.LC27:
	.string	"r\t= oxy/(ox*oy)\t\t--Coeficiente de correlacion lineal.\n"
.LC28:
	.string	"n\t=\t\t\t--Numero de puntos.\n"
.LC29:
	.string	"n:\t"
.LC30:
	.string	"y_%li:\t"
.LC31:
	.string	"\nux\t= %lf"
.LC32:
	.string	"\nox2\t= %lf"
.LC33:
	.string	"\nox\t= %lf\n"
.LC34:
	.string	"\nuy\t= %lf"
.LC35:
	.string	"\noy2\t= %lf"
.LC36:
	.string	"\noy\t= %lf\n"
.LC37:
	.string	"\noxy\t= %lf"
.LC38:
	.string	"\na\t= %lf"
.LC39:
	.string	"\nAa\t= %lf"
.LC40:
	.string	"\nb\t= %lf"
.LC41:
	.string	"\nAb\t= %lf"
.LC42:
	.string	"\nc\t= %lf"
.LC43:
	.string	"\nAc\t= %lf"
.LC44:
	.string	"\nd\t= %lf"
.LC45:
	.string	"\nAd\t= %lf"
.LC46:
	.string	"\nr\t= %lf"
.LC47:
	.string	"\nVr\t= %lf"
.LC48:
	.string	"\nR2\t= %lf\n"
	.text
	.globl	desc_2var
	.type	desc_2var, @function
desc_2var:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$208, %rsp
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -24(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -32(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -40(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -48(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -56(%rbp)
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -64(%rbp)
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC21(%rip), %rdi
	call	puts@PLT
	leaq	.LC22(%rip), %rdi
	call	puts@PLT
	leaq	.LC23(%rip), %rdi
	call	puts@PLT
	leaq	.LC24(%rip), %rdi
	call	puts@PLT
	leaq	.LC25(%rip), %rdi
	call	puts@PLT
	leaq	.LC26(%rip), %rdi
	call	puts@PLT
	leaq	.LC27(%rip), %rdi
	call	puts@PLT
	leaq	.LC28(%rip), %rdi
	call	puts@PLT
	movsd	.LC9(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	movl	$0, %edx
	leaq	.LC29(%rip), %rsi
	movl	$2, %edi
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_N(%rip)
	movq	$0, -8(%rbp)
	jmp	.L7
.L8:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	.LC12(%rip), %xmm2
	movsd	.LC10(%rip), %xmm1
	movsd	.LC13(%rip), %xmm0
	movl	$0, %esi
	movl	$0, %edi
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rcx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC30(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	.LC12(%rip), %xmm2
	movsd	.LC10(%rip), %xmm1
	movsd	.LC13(%rip), %xmm0
	movl	$0, %esi
	movl	$0, %edi
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rcx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	movl	$10, %edi
	call	putchar@PLT
	addq	$1, -8(%rbp)
.L7:
	movq	param_i_N(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L8
	movq	$0, -8(%rbp)
	jmp	.L9
.L10:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movsd	.LC10(%rip), %xmm0
	call	descrip_Exi@PLT
	movapd	%xmm0, %xmm1
	movsd	-16(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -16(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movsd	.LC10(%rip), %xmm0
	call	descrip_Exi2@PLT
	movapd	%xmm0, %xmm1
	movsd	-24(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movsd	.LC10(%rip), %xmm0
	call	descrip_Exi@PLT
	movapd	%xmm0, %xmm1
	movsd	-32(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -32(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movsd	.LC10(%rip), %xmm0
	call	descrip_Exi2@PLT
	movapd	%xmm0, %xmm1
	movsd	-40(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movsd	(%rdx,%rax), %xmm0
	call	descrip_Exiyi@PLT
	movapd	%xmm0, %xmm1
	movsd	-48(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -48(%rbp)
	addq	$1, -8(%rbp)
.L9:
	movq	param_i_N(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L10
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	-16(%rbp), %xmm0
	call	descrip_u@PLT
	movq	%xmm0, %rax
	movq	%rax, -72(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	-72(%rbp), %xmm2
	movsd	-24(%rbp), %xmm0
	call	descrip_o2@PLT
	movq	%xmm0, %rax
	movq	%rax, -80(%rbp)
	movsd	-80(%rbp), %xmm0
	call	descrip_o@PLT
	movq	%xmm0, %rax
	movq	%rax, -88(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	-32(%rbp), %xmm0
	call	descrip_u@PLT
	movq	%xmm0, %rax
	movq	%rax, -96(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	-96(%rbp), %xmm2
	movsd	-40(%rbp), %xmm0
	call	descrip_o2@PLT
	movq	%xmm0, %rax
	movq	%rax, -104(%rbp)
	movsd	-104(%rbp), %xmm0
	call	descrip_o@PLT
	movq	%xmm0, %rax
	movq	%rax, -112(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	-96(%rbp), %xmm3
	movsd	-72(%rbp), %xmm2
	movsd	-48(%rbp), %xmm0
	call	descrip_oxy@PLT
	movq	%xmm0, %rax
	movq	%rax, -120(%rbp)
	movsd	-80(%rbp), %xmm1
	movsd	-120(%rbp), %xmm0
	call	descrip_a@PLT
	movq	%xmm0, %rax
	movq	%rax, -128(%rbp)
	movsd	-128(%rbp), %xmm2
	movsd	-96(%rbp), %xmm1
	movsd	-72(%rbp), %xmm0
	call	descrip_b@PLT
	movq	%xmm0, %rax
	movq	%rax, -136(%rbp)
	movsd	-104(%rbp), %xmm1
	movsd	-120(%rbp), %xmm0
	call	descrip_a@PLT
	movq	%xmm0, %rax
	movq	%rax, -144(%rbp)
	movsd	-144(%rbp), %xmm2
	movsd	-72(%rbp), %xmm1
	movsd	-96(%rbp), %xmm0
	call	descrip_b@PLT
	movq	%xmm0, %rax
	movq	%rax, -152(%rbp)
	movsd	-112(%rbp), %xmm2
	movsd	-88(%rbp), %xmm1
	movsd	-120(%rbp), %xmm0
	call	descrip_r@PLT
	movq	%xmm0, %rax
	movq	%rax, -160(%rbp)
	movq	$0, -8(%rbp)
	jmp	.L11
.L12:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movsd	(%rdx,%rax), %xmm0
	movsd	-136(%rbp), %xmm3
	movsd	-128(%rbp), %xmm2
	call	descrip_Eyiy2@PLT
	movapd	%xmm0, %xmm1
	movsd	-56(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -56(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_x_dbl(%rip), %rax
	movsd	(%rdx,%rax), %xmm1
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_y(%rip), %rax
	movsd	(%rdx,%rax), %xmm0
	movsd	-152(%rbp), %xmm3
	movsd	-144(%rbp), %xmm2
	call	descrip_Eyiy2@PLT
	movapd	%xmm0, %xmm1
	movsd	-64(%rbp), %xmm0
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -64(%rbp)
	addq	$1, -8(%rbp)
.L11:
	movq	param_i_N(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L12
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-56(%rbp), %xmm3
	movsd	-24(%rbp), %xmm2
	movsd	-16(%rbp), %xmm1
	call	descrip_Aa@PLT
	movq	%xmm0, %rax
	movq	%rax, -168(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-168(%rbp), %xmm2
	movsd	-24(%rbp), %xmm1
	call	descrip_Ab@PLT
	movq	%xmm0, %rax
	movq	%rax, -176(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-64(%rbp), %xmm3
	movsd	-40(%rbp), %xmm2
	movsd	-32(%rbp), %xmm1
	call	descrip_Aa@PLT
	movq	%xmm0, %rax
	movq	%rax, -184(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-184(%rbp), %xmm2
	movsd	-40(%rbp), %xmm1
	call	descrip_Ab@PLT
	movq	%xmm0, %rax
	movq	%rax, -192(%rbp)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movsd	-56(%rbp), %xmm1
	call	descrip_Vr@PLT
	movq	%xmm0, %rax
	movq	%rax, -200(%rbp)
	movsd	-200(%rbp), %xmm1
	movsd	-104(%rbp), %xmm0
	call	descrip_R2@PLT
	movq	%xmm0, %rax
	movq	%rax, -208(%rbp)
	movsd	-72(%rbp), %xmm0
	leaq	.LC31(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-80(%rbp), %xmm0
	leaq	.LC32(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-88(%rbp), %xmm0
	leaq	.LC33(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-96(%rbp), %xmm0
	leaq	.LC34(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-104(%rbp), %xmm0
	leaq	.LC35(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-112(%rbp), %xmm0
	leaq	.LC36(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-120(%rbp), %xmm0
	leaq	.LC37(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-128(%rbp), %xmm0
	leaq	.LC38(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-168(%rbp), %xmm0
	leaq	.LC39(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-136(%rbp), %xmm0
	leaq	.LC40(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-176(%rbp), %xmm0
	leaq	.LC41(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-144(%rbp), %xmm0
	leaq	.LC42(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-184(%rbp), %xmm0
	leaq	.LC43(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-152(%rbp), %xmm0
	leaq	.LC44(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-192(%rbp), %xmm0
	leaq	.LC45(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-160(%rbp), %xmm0
	leaq	.LC46(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-200(%rbp), %xmm0
	leaq	.LC47(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-208(%rbp), %xmm0
	leaq	.LC48(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	desc_2var, .-desc_2var
	.section	.rodata
	.align 8
.LC49:
	.string	"\nESTADISTICA/Distribuciones:\tDistribucion Binomial: B(n,p)\n"
	.align 8
.LC50:
	.string	"n = numero de veces que se repite el experimento (con reemplazamiento)"
	.align 8
.LC51:
	.string	"p = probabilidad del suceso individual"
	.align 8
.LC52:
	.string	"x = numero de veces que interesa que ocurra el suceso"
	.align 8
.LC53:
	.string	"c = cantidad de x que interesan (inroducir [0] para intervalo [a U b])\n"
.LC54:
	.string	"p:\t"
.LC56:
	.string	"c:\t"
.LC57:
	.string	"\nP{X}\t= %lf"
.LC58:
	.string	"\nE(X)\t= %lf"
.LC59:
	.string	"\nVar(X)\t= %lf\n"
	.align 8
.LC61:
	.string	"\nAproximacion a Distribucion Normal N(u = np, o2 = np(1-p))"
.LC62:
	.string	"\no2\t= %lf\n"
	.text
	.globl	dist_binomial
	.type	dist_binomial, @function
dist_binomial:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC49(%rip), %rdi
	call	puts@PLT
	leaq	.LC50(%rip), %rdi
	call	puts@PLT
	leaq	.LC51(%rip), %rdi
	call	puts@PLT
	leaq	.LC52(%rip), %rdi
	call	puts@PLT
	leaq	.LC53(%rip), %rdi
	call	puts@PLT
	movsd	.LC9(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	movl	$0, %edx
	leaq	.LC29(%rip), %rsi
	movl	$2, %edi
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_N(%rip)
	movsd	.LC10(%rip), %xmm1
	movsd	.LC55(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC54(%rip), %rdi
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_p(%rip)
	movq	param_i_N(%rip), %rax
	addq	$1, %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$0, %edx
	leaq	.LC56(%rip), %rsi
	movapd	%xmm0, %xmm1
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_c(%rip)
	call	dist_binomial_P
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	param_p(%rip), %xmm1
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	call	binomial_E@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	param_p(%rip), %xmm1
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	call	binomial_Var@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC57(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	leaq	.LC58(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-24(%rbp), %xmm0
	leaq	.LC59(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	param_p(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	comisd	.LC60(%rip), %xmm0
	ja	.L17
	jmp	.L19
.L17:
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	param_p(%rip), %xmm2
	movsd	.LC10(%rip), %xmm0
	subsd	%xmm2, %xmm0
	mulsd	%xmm1, %xmm0
	comisd	.LC60(%rip), %xmm0
	ja	.L18
	jmp	.L19
.L18:
	leaq	.LC61(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	leaq	.LC15(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-24(%rbp), %xmm0
	leaq	.LC62(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
.L19:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	dist_binomial, .-dist_binomial
	.section	.rodata
	.align 8
.LC63:
	.string	"\nESTADISTICA/Distribuciones:\tDistribucion de Poisson: P(lambda)\n"
	.align 8
.LC64:
	.string	"lambda = veces que ocurre de media/ud. de tiempo"
	.align 8
.LC65:
	.string	"x = veces que interesa que ocurra X/ud. de tiempo"
.LC66:
	.string	"l:\t"
	.text
	.globl	dist_poisson
	.type	dist_poisson, @function
dist_poisson:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC63(%rip), %rdi
	call	puts@PLT
	leaq	.LC64(%rip), %rdi
	call	puts@PLT
	leaq	.LC65(%rip), %rdi
	call	puts@PLT
	leaq	.LC53(%rip), %rdi
	call	puts@PLT
	movq	$65536, param_i_N(%rip)
	movsd	.LC12(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC66(%rip), %rdi
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_lambda(%rip)
	movsd	.LC9(%rip), %xmm0
	movl	$0, %edx
	leaq	.LC56(%rip), %rsi
	movapd	%xmm0, %xmm1
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_c(%rip)
	call	dist_poisson_P
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	param_lambda(%rip), %xmm0
	call	poisson_E@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	param_lambda(%rip), %xmm0
	call	poisson_Var@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC57(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	leaq	.LC58(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-24(%rbp), %xmm0
	leaq	.LC59(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	dist_poisson, .-dist_poisson
	.section	.rodata
	.align 8
.LC67:
	.string	"\nESTADISTICA/Distribuciones:\tDistribucion Geometrica: G(p)\n"
	.align 8
.LC68:
	.string	"p = probabilidad del suceso en cada repeticion"
	.align 8
.LC69:
	.string	"x = vez que interesa que ocurra el suceso\n"
.LC70:
	.string	"\nP{X=x}\t= %lf"
	.text
	.globl	dist_geometric
	.type	dist_geometric, @function
dist_geometric:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC67(%rip), %rdi
	call	puts@PLT
	leaq	.LC68(%rip), %rdi
	call	puts@PLT
	leaq	.LC69(%rip), %rdi
	call	puts@PLT
	movsd	.LC10(%rip), %xmm1
	movsd	.LC55(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC54(%rip), %rdi
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_p(%rip)
	call	dist_geometric_P
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	param_p(%rip), %xmm0
	call	geometric_E@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	param_p(%rip), %xmm0
	call	geometric_Var@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC70(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	leaq	.LC58(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-24(%rbp), %xmm0
	leaq	.LC59(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	dist_geometric, .-dist_geometric
	.section	.rodata
	.align 8
.LC71:
	.string	"\nESTADISTICA/Distribuciones:\tDistribucion Uniforme: U(a, b)\n"
	.align 8
.LC72:
	.string	"a = limite inferior de la distribucion."
	.align 8
.LC73:
	.string	"b = limite superior de la distribucion."
	.align 8
.LC74:
	.string	"x1 = limite inferior de interes."
	.align 8
.LC75:
	.string	"x2 = limite superior de interes.\n"
.LC76:
	.string	"a:\t"
.LC77:
	.string	"b:\t"
.LC78:
	.string	"x1:\t"
.LC79:
	.string	"x2:\t"
.LC80:
	.string	"\nP{x1<X<x2}\t= %lf"
.LC81:
	.string	"\nE(X)\t\t= %lf"
.LC82:
	.string	"\nVar(X)\t\t= %lf\n"
	.text
	.globl	dist_uniform
	.type	dist_uniform, @function
dist_uniform:
.LFB5:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC71(%rip), %rdi
	call	puts@PLT
	leaq	.LC72(%rip), %rdi
	call	puts@PLT
	leaq	.LC73(%rip), %rdi
	call	puts@PLT
	leaq	.LC74(%rip), %rdi
	call	puts@PLT
	leaq	.LC75(%rip), %rdi
	call	puts@PLT
	movsd	.LC12(%rip), %xmm1
	movsd	.LC13(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC76(%rip), %rdi
	movapd	%xmm1, %xmm2
	pxor	%xmm1, %xmm1
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_a(%rip)
	movsd	param_a(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	param_a(%rip), %xmm0
	movsd	.LC12(%rip), %xmm2
	movl	$0, %esi
	leaq	.LC77(%rip), %rdi
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_b(%rip)
	movsd	param_b(%rip), %xmm2
	movsd	param_a(%rip), %xmm1
	movsd	param_a(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC78(%rip), %rdi
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, 8+param_x_dbl(%rip)
	movsd	param_b(%rip), %xmm2
	movsd	param_b(%rip), %xmm1
	movsd	8+param_x_dbl(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC79(%rip), %rdi
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, 16+param_x_dbl(%rip)
	movsd	16+param_x_dbl(%rip), %xmm3
	movsd	8+param_x_dbl(%rip), %xmm2
	movsd	param_b(%rip), %xmm1
	movsd	param_a(%rip), %xmm0
	call	uniform_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	param_b(%rip), %xmm1
	movsd	param_a(%rip), %xmm0
	call	uniform_E@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	param_b(%rip), %xmm1
	movsd	param_a(%rip), %xmm0
	call	uniform_Var@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC80(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	leaq	.LC81(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-24(%rbp), %xmm0
	leaq	.LC82(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE5:
	.size	dist_uniform, .-dist_uniform
	.section	.rodata
	.align 8
.LC83:
	.string	"\nESTADISTICA/Distribuciones:\tDistribucion Exponencial: exp(beta)\n"
.LC84:
	.string	"beta = coeficiente beta"
	.align 8
.LC85:
	.string	"x = tiempo para que ocurra el suceso"
.LC86:
	.string	"\nP{x1<X<x2}\t= %lf\n"
	.text
	.globl	dist_exponential
	.type	dist_exponential, @function
dist_exponential:
.LFB6:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC83(%rip), %rdi
	call	puts@PLT
	leaq	.LC84(%rip), %rdi
	call	puts@PLT
	leaq	.LC85(%rip), %rdi
	call	puts@PLT
	leaq	.LC74(%rip), %rdi
	call	puts@PLT
	leaq	.LC75(%rip), %rdi
	call	puts@PLT
	movsd	.LC12(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC77(%rip), %rdi
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_beta(%rip)
	movsd	.LC12(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC78(%rip), %rdi
	movapd	%xmm0, %xmm2
	pxor	%xmm1, %xmm1
	pxor	%xmm0, %xmm0
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, 8+param_x_dbl(%rip)
	movsd	8+param_x_dbl(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	addsd	%xmm0, %xmm1
	movsd	8+param_x_dbl(%rip), %xmm0
	movsd	.LC12(%rip), %xmm2
	movl	$0, %esi
	leaq	.LC79(%rip), %rdi
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, 16+param_x_dbl(%rip)
	movsd	16+param_x_dbl(%rip), %xmm2
	movsd	8+param_x_dbl(%rip), %xmm1
	movsd	param_beta(%rip), %xmm0
	call	exponential_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	param_beta(%rip), %xmm0
	call	exponential_E@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	param_beta(%rip), %xmm0
	call	exponential_Var@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC86(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	leaq	.LC58(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-24(%rbp), %xmm0
	leaq	.LC59(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	dist_exponential, .-dist_exponential
	.section	.rodata
	.align 8
.LC87:
	.string	"\nESTADISTICA/Distribuciones:\tDistribucion Normal (Gauss): N(mu, sigma2)\n"
.LC88:
	.string	"X -> N(mu,sigma2)"
.LC89:
	.string	"mu\t=\t\t--Esperanza de X."
.LC90:
	.string	"sigma2\t=\t\t--Varianza de X.\n"
	.align 8
.LC91:
	.string	"sigma\t=\t\t--Desviacion tipica de X.\n"
.LC92:
	.string	"Z = aX + b"
.LC93:
	.string	"Z -> N(0,1)"
.LC94:
	.string	"a\t= 1/o"
.LC95:
	.string	"b\t= -u/o\n"
.LC96:
	.string	"u:\t"
.LC97:
	.string	"o2:\t"
.LC98:
	.string	"\na\t= %lf\nb\t= %lf\n"
	.text
	.globl	dist_normal
	.type	dist_normal, @function
dist_normal:
.LFB7:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
	leaq	.LC87(%rip), %rdi
	call	puts@PLT
	leaq	.LC88(%rip), %rdi
	call	puts@PLT
	leaq	.LC89(%rip), %rdi
	call	puts@PLT
	leaq	.LC90(%rip), %rdi
	call	puts@PLT
	leaq	.LC91(%rip), %rdi
	call	puts@PLT
	leaq	.LC92(%rip), %rdi
	call	puts@PLT
	leaq	.LC93(%rip), %rdi
	call	puts@PLT
	leaq	.LC94(%rip), %rdi
	call	puts@PLT
	leaq	.LC95(%rip), %rdi
	call	puts@PLT
	movsd	.LC12(%rip), %xmm1
	movsd	.LC13(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC96(%rip), %rdi
	movapd	%xmm1, %xmm2
	pxor	%xmm1, %xmm1
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_mu(%rip)
	movsd	.LC12(%rip), %xmm1
	movsd	.LC10(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC97(%rip), %rdi
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	pxor	%xmm0, %xmm0
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_sigma2(%rip)
	movsd	param_sigma2(%rip), %xmm0
	call	normal_o@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	call	normal_A@PLT
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movsd	param_mu(%rip), %xmm0
	movsd	-8(%rbp), %xmm1
	call	normal_B@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm1
	movsd	-16(%rbp), %xmm0
	leaq	.LC98(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movsd	-24(%rbp), %xmm1
	movsd	-16(%rbp), %xmm0
	call	dist_normal_m
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	dist_normal, .-dist_normal
	.section	.rodata
.LC99:
	.string	"\nTipificar:"
.LC100:
	.string	"X -> Z [1]\tZ -> X [2]\tExit[0]"
	.text
	.type	dist_normal_m, @function
dist_normal_m:
.LFB8:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movq	$1, -8(%rbp)
	jmp	.L26
.L29:
	leaq	.LC99(%rip), %rdi
	call	puts@PLT
	leaq	.LC100(%rip), %rdi
	call	puts@PLT
	movsd	.LC101(%rip), %xmm0
	movl	$0, %edx
	movl	$0, %esi
	movapd	%xmm0, %xmm1
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, -16(%rbp)
	cmpq	$1, -16(%rbp)
	je	.L27
	cmpq	$2, -16(%rbp)
	je	.L28
	cmpq	$0, -16(%rbp)
	jne	.L26
	movq	$0, -8(%rbp)
	jmp	.L26
.L27:
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	call	dist_normal_m_1
	jmp	.L26
.L28:
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	call	dist_normal_m_2
	nop
.L26:
	cmpq	$0, -8(%rbp)
	jne	.L29
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	dist_normal_m, .-dist_normal_m
	.section	.rodata
.LC102:
	.string	"Z = %lf * X + %lf\n"
.LC103:
	.string	"x:\t"
.LC104:
	.string	"\nz = %lf\n"
	.text
	.type	dist_normal_m_1, @function
dist_normal_m_1:
.LFB9:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	leaq	.LC102(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movsd	.LC12(%rip), %xmm1
	movsd	.LC13(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC103(%rip), %rdi
	movapd	%xmm1, %xmm2
	pxor	%xmm1, %xmm1
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_X(%rip)
	movsd	param_X(%rip), %xmm2
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	call	normal_Z@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC104(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	dist_normal_m_1, .-dist_normal_m_1
	.section	.rodata
.LC105:
	.string	"X = (Z - %lf) / %lf\n"
.LC106:
	.string	"z:\t"
.LC107:
	.string	"\nx = %lf\n"
	.text
	.type	dist_normal_m_2, @function
dist_normal_m_2:
.LFB10:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	-24(%rbp), %xmm1
	movsd	-32(%rbp), %xmm0
	leaq	.LC105(%rip), %rdi
	movl	$2, %eax
	call	printf@PLT
	movsd	.LC12(%rip), %xmm1
	movsd	.LC13(%rip), %xmm0
	movl	$0, %esi
	leaq	.LC106(%rip), %rdi
	movapd	%xmm1, %xmm2
	pxor	%xmm1, %xmm1
	movl	$3, %eax
	call	alx_getdbl@PLT
	movq	%xmm0, %rax
	movq	%rax, param_Z(%rip)
	movsd	param_Z(%rip), %xmm2
	movsd	-32(%rbp), %xmm1
	movsd	-24(%rbp), %xmm0
	call	normal_X@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC107(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	dist_normal_m_2, .-dist_normal_m_2
	.section	.rodata
.LC108:
	.string	"P_%li\t= %lf\n"
	.text
	.type	dist_binomial_P, @function
dist_binomial_P:
.LFB11:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movq	param_i_c(%rip), %rax
	testq	%rax, %rax
	je	.L33
	movq	$0, -8(%rbp)
	jmp	.L34
.L35:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$0, %edx
	movl	$0, %esi
	movapd	%xmm0, %xmm1
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, %rcx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_i_x(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	addq	$1, -8(%rbp)
.L34:
	movq	param_i_c(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L35
	jmp	.L36
.L33:
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$0, %edx
	leaq	.LC76(%rip), %rsi
	movapd	%xmm0, %xmm1
	movl	$0, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_a(%rip)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	param_i_N(%rip), %rax
	movq	param_i_a(%rip), %rdx
	cvtsi2sdq	%rdx, %xmm0
	movl	$0, %edx
	leaq	.LC77(%rip), %rsi
	movq	%rax, %rdi
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_b(%rip)
.L36:
	movq	param_i_c(%rip), %rax
	testq	%rax, %rax
	je	.L37
	movq	$0, -8(%rbp)
	jmp	.L38
.L39:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_i_x(%rip), %rax
	movq	(%rdx,%rax), %rax
	cvtsi2sdq	%rax, %xmm2
	movsd	param_p(%rip), %xmm1
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	call	binomial_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_i_x(%rip), %rax
	movq	(%rdx,%rax), %rax
	movsd	-24(%rbp), %xmm0
	movq	%rax, %rsi
	leaq	.LC108(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	addq	$1, -8(%rbp)
.L38:
	movq	param_i_c(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L39
	jmp	.L40
.L37:
	movq	param_i_a(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L41
.L42:
	cvtsi2sdq	-8(%rbp), %xmm2
	movsd	param_p(%rip), %xmm1
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	call	binomial_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC108(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	addq	$1, -8(%rbp)
.L41:
	movq	param_i_b(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L42
	movq	param_i_b(%rip), %rax
	cvtsi2sdq	%rax, %xmm2
	movsd	param_p(%rip), %xmm1
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	call	binomial_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movq	param_i_b(%rip), %rax
	movsd	-24(%rbp), %xmm0
	movq	%rax, %rsi
	leaq	.LC108(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
.L40:
	movsd	-16(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	dist_binomial_P, .-dist_binomial_P
	.type	dist_poisson_P, @function
dist_poisson_P:
.LFB12:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -16(%rbp)
	movq	param_i_c(%rip), %rax
	testq	%rax, %rax
	je	.L45
	movq	$0, -8(%rbp)
	jmp	.L46
.L47:
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC11(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$0, %edx
	movl	$0, %esi
	movapd	%xmm0, %xmm1
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, %rcx
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_i_x(%rip), %rax
	movq	%rcx, (%rdx,%rax)
	addq	$1, -8(%rbp)
.L46:
	movq	param_i_c(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L47
	jmp	.L48
.L45:
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$0, %edx
	leaq	.LC76(%rip), %rsi
	movapd	%xmm0, %xmm1
	movl	$0, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_a(%rip)
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movq	param_i_N(%rip), %rax
	movq	param_i_a(%rip), %rdx
	cvtsi2sdq	%rdx, %xmm0
	movl	$0, %edx
	leaq	.LC77(%rip), %rsi
	movq	%rax, %rdi
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_b(%rip)
.L48:
	movq	param_i_c(%rip), %rax
	testq	%rax, %rax
	je	.L49
	movq	$0, -8(%rbp)
	jmp	.L50
.L51:
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_i_x(%rip), %rax
	movq	(%rdx,%rax), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	param_lambda(%rip), %xmm0
	call	poisson_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movq	-8(%rbp), %rax
	leaq	0(,%rax,8), %rdx
	leaq	param_i_x(%rip), %rax
	movq	(%rdx,%rax), %rax
	movsd	-24(%rbp), %xmm0
	movq	%rax, %rsi
	leaq	.LC108(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	addq	$1, -8(%rbp)
.L50:
	movq	param_i_c(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L51
	jmp	.L52
.L49:
	movq	param_i_a(%rip), %rax
	movq	%rax, -8(%rbp)
	jmp	.L53
.L54:
	cvtsi2sdq	-8(%rbp), %xmm1
	movsd	param_lambda(%rip), %xmm0
	call	poisson_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movsd	-24(%rbp), %xmm0
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC108(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
	addq	$1, -8(%rbp)
.L53:
	movq	param_i_b(%rip), %rax
	cmpq	%rax, -8(%rbp)
	jl	.L54
	movq	param_i_b(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	param_lambda(%rip), %xmm0
	call	poisson_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movq	param_i_b(%rip), %rax
	movsd	-24(%rbp), %xmm0
	movq	%rax, %rsi
	leaq	.LC108(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-16(%rbp), %xmm0
	addsd	-24(%rbp), %xmm0
	movsd	%xmm0, -16(%rbp)
.L52:
	movsd	-16(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	dist_poisson_P, .-dist_poisson_P
	.section	.rodata
.LC109:
	.string	"P\t= %lf\n"
	.text
	.type	dist_geometric_P, @function
dist_geometric_P:
.LFB13:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	pxor	%xmm0, %xmm0
	movsd	%xmm0, -8(%rbp)
	leaq	.LC103(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	param_i_N(%rip), %rax
	cvtsi2sdq	%rax, %xmm0
	movl	$0, %edx
	movl	$0, %esi
	movapd	%xmm0, %xmm1
	movl	$1, %edi
	pxor	%xmm0, %xmm0
	movl	$2, %eax
	call	alx_getint@PLT
	movq	%rax, param_i_x(%rip)
	movq	param_i_x(%rip), %rax
	cvtsi2sdq	%rax, %xmm1
	movsd	param_p(%rip), %xmm0
	call	geometric_P@PLT
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm0
	leaq	.LC109(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	movsd	-8(%rbp), %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	dist_geometric_P, .-dist_geometric_P
	.section	.rodata
	.align 8
.LC9:
	.long	0
	.long	1089470464
	.align 8
.LC10:
	.long	0
	.long	1072693248
	.align 8
.LC12:
	.long	0
	.long	2146435072
	.align 8
.LC13:
	.long	0
	.long	-1048576
	.align 8
.LC55:
	.long	0
	.long	1071644672
	.align 8
.LC60:
	.long	0
	.long	1075052544
	.align 8
.LC101:
	.long	0
	.long	1073741824
	.ident	"GCC: (Debian 8.2.0-8) 8.2.0"
	.section	.note.GNU-stack,"",@progbits
