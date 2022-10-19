	global asmVecSum
	section .text
;(float *v, float *u, float *w, int TAM)
; rsi <- *v, rdi <- *u , rdx <- *w, rcx <- TAM
asmVecSum:
	xorpd	xmm0, xmm0
	xorpd	xmm1, xmm1
	cmp	rcx, 0
	je 	done

arreglarN:
    xor rax,rax
    xor r8,r8
    xor r9,r9
    mov r8,4
    mov rax,rcx
    mov r9,rdx
    xor rdx, rdx
    div r8
    mov r8,rdx
    mov rdx,r9
    cmp r8, 0
    je next
    sub rcx, r8
    xor r9, r9


    loop:
        movss	xmm0, [rdi]
        movss	xmm1, [rsi]
        addss	xmm0, xmm1
        movss  [rdx], xmm0
        add	    rdi, 4
        add	    rsi, 4
        add	    rdx, 4
        inc     r9
        cmp     r8, r9
        jne      loop

xorpd xmm0,xmm0
xorpd xmm1,xmm1
ret
next:
	movaps	xmm0, [rdi]
    ret
	movaps	xmm1, [rsi]
	addps	xmm0, xmm1
	movaps  [rdx], xmm0
    
	add	rdi, 16
	add	rsi, 16
	add	rdx, 16
	sub	rcx, 4
	jnz 	next
done:
	ret
