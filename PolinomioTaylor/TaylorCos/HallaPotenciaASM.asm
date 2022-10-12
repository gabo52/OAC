global hallaPotenciaASM
    section .text
;int i, int x;
;rdi<-- i   rsi<--x
hallaPotenciaASM:

    ;inicializamos registros
    mov rcx, rdi
    add rcx,rcx     ;rcx <- i*2
    mov r8,1        ;r8 <- 2
    cvtsi2sd    xmm0,r8  ;<- aux=1
    xor r8,r8
    cvtsi2sd    xmm1,rsi

    ;obtenemos el signo
    xor rdx,rdx
    mov r9,2
    mov rax,rdi
    div r9
    mov rax,1
    cmp rdx,0
    je loop
    mov rax,-1

    ;realizamos el ciclo
    loop:
        cmp r8,rcx
        je salimosunu
        mulsd xmm0,xmm1
        inc r8
        jmp loop

    salimosunu:
    cvtsi2sd    xmm1,rax
    mulsd xmm0,xmm1
    
ret
