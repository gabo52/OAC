;Halla el factorial y lo devuelve en XMM0
global hallaFactorialASM
    section .text


hallaFactorialASM:
; n--> rdi
;inicializamos variables
;factorial rax <-1
;contador  r8<-2
;limite    rcx <- n*2
mov r8,1
xor rdx,rdx
mov rax, 1        ;rax <-1
mov r8, 1          ;r8<-2
mov rcx, rdi
add rcx, rcx
inc rcx
cvtsi2sd xmm0,r8

loop:
    cmp r8, rcx
    je salir
    cvtsi2sd xmm1,r8
    mulsd xmm0,xmm1
    inc r8
    jmp loop

salir:
    ret
