section .text
    global hallaPotenciaASM


hallaPotenciaASM:
;int i, int x
; x<- rdi  n <- rsi
mov rax,1
cvtsi2sd xmm0,rax       ;resultado en xmm0 = 1   
xor rax,rax             ;rax será nuestro i
;el mismo rsi será el limite
cvtsi2sd xmm1,rdi

loop:
    cmp rax,rsi
    je salir
    mulsd xmm0,xmm1
    inc rax
    jmp loop
salir:
    ret
