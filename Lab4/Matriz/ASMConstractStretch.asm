	global ASMConstrastStretch
	section .text
;void extern SIMDConstrastStretch(int *matIn,int *matOut,int N,int minCs,int maxCs,int max);
; rdi -> *matIn , rsi -> *matOut, rdx -> N, rcx -> minCs, r8 -> maxCS, r9 -> max
ASMConstrastStretch:
	;inicializamos el contador
	xor rax, rax
	mov rax, rdx
	xor rdx, rdx
	mul rax
	mov rdx, rax
	xor rax, rax
	cmp rdx, 0 
	je done

	;limpiamos registros
	xor r10, r10
	xor r11, r11
	xorpd xmm0,xmm0
	xorpd xmm1,xmm1
	xorpd xmm2,xmm2
	xorpd xmm3,xmm3
	xorpd xmm4,xmm4

	cvtsi2ss xmm1, rcx		;guardamos minCs en xmm1
	cvtsi2ss xmm2, r8		;guardamos maxCS en r8
	cvtsi2ss xmm3, r9		;guardamos max en xmm3
	subss xmm2,xmm1    		;guardamos maxCs- minCs en xmm2
	xor rax, rax
	loop:
		mov eax, [rdi]
		cvtsi2ss xmm0, eax
		mulss xmm0, xmm2
		divss xmm0, xmm3
		roundss xmm0,xmm0,0
		addss xmm0,xmm1
		cvtss2si rax, xmm0
		mov [rsi],rax
		add rdi, 4
		add rsi, 4
		sub rdx, 1
		jnz loop
	done: 
ret
