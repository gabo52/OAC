	global simdInnerProd
	section .text
;(float *arr1,float *arr2,int N);
; rsi <- *arr1, rdi <- *arr2, rdx <- N
simdInnerProd:
    
    xorpd xmm0,xmm0;
    xorpd xmm1,xmm1;
    xorpd xmm2,xmm2;
    xorpd xmm3,xmm3;
    cmp rdx, 0
    je done

    loop:
        movaps xmm0, [rsi]
        movaps xmm1, [rdi]
        mulps xmm0,xmm1
        addps xmm2,xmm0
        add rsi, 16
        add rdi, 16
        sub rdx, 4
        jnz loop

    done:
        movaps xmm3,xmm2                 ; XMM2 = {A,B,C,D}, XMM3 = {A,B,C,D}
        shufps xmm3, xmm2, 00011011b   ; XMM2 = {A,B,C,D}, XMM3 = {D,C,B,A}
        addps xmm2, xmm3                ; XMM2 = {A+D,B+C,C+B,D+A}, XMM3 = {D,C,B,A}

        movaps xmm3,xmm2                ; XMM2 = {A+D,B+C,C+B,D+A}, XMM3 = {A+D,B+C,C+B,D+A}
        shufps xmm3,xmm2, 01001110b    ; XMM2 = {C+B,D+A,A+D,B+C}, XMM3 = {A+D,B+C,C+B,D+A}
        addps xmm3,xmm2                 ; XMM2 = {C+B,D+A,A+D,B+C}, XMM3 = {A+D+B+c,B+C+D+A,C+B+A+D,D+A+B+c}
        movss xmm0, xmm3
ret
