	.file	"factorial.c" #имя файла на с
	.text
	.p2align 4,,15
	.globl	_factorial # объявляем функцию как глобальную
	.def	_factorial;	.scl	2;	.type	32;	.endef
_factorial: #начало функции factorial
LFB24: #начало области функции для отладки
	.cfi_startproc
	movl	4(%esp), %ecx #загружаем n в регистр ecx
	testl	%ecx, %ecx # ecx (n) < 0 ?
	js	L4 # если да, то к L4 (0)
	cmpl	$1, %ecx # <=1 ?
	jle	L5 # если да, то к L5 (1)
	addl	$1, %ecx # n+1
	movl	$2, %edx # i = 2
	movl	$1, %eax # result = 1
	.p2align 4,,10
L3: # начало цикла: for (i = 2; i < n+1; i++)
	imull	%edx, %eax # result *= i (eax *= edx)
	addl	$1, %edx # i++
	cmpl	%edx, %ecx # i < n+1 
	jne	L3 # если не дошли до конца, переходим в L3
	rep ret # возвращаем результат
	.p2align 4,,10 
L4: # ветка n < 0
	xorl	%eax, %eax #возвращает 0
	ret
L5: # если n == 0 или n == 1
	movl	$1, %eax #возвращаем 1
	ret
	.cfi_endproc #конец описания
LFE24:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
