	global SIMDConstrastStretch
	section .text

;void extern SIMDConstrastStretch(int *matIn,int *matOut,int N,int minCs,int maxCs,int max);
; rdi -> *matIn , rsi -> *matOut, rdx -> N, rcx -> minCs, r8 -> maxCS, r9 -> max
SIMDConstrastStretch:
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
	xorpd xmm0,xmm0
	xorpd xmm1,xmm1
	xorpd xmm2,xmm2
	xorpd xmm3,xmm3
	xorpd xmm4,xmm4

	cvtsi2ss xmm1, rcx		;guardamos minCs en xmm1
	shufps xmm1,xmm1 , 00000000b
	cvtsi2ss xmm2, r8		;guardamos maxCS en xmm2
	shufps xmm2,xmm2 , 00000000b
	cvtsi2ss xmm3, r9		;guardamos max en xmm3
	shufps xmm3,xmm3 , 00000000b
	subps xmm2,xmm1    		;guardamos maxCs- minCs en xmm2




	loop:
		movdqa xmm0, [rdi]
		cvtdq2ps xmm0,xmm0
		mulps xmm0, xmm2
		divps xmm0, xmm3
		roundps xmm0,xmm0,0
		addps xmm0,xmm1
		cvtps2dq xmm0, xmm0
		movdqa [rsi], xmm0
		add rdi,16
		add rsi,16
		sub rdx,4
		cmp rdx,0
		jne loop
	
	done:


ret
