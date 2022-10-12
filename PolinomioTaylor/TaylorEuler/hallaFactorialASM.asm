section .text
    global hallaFactorialASM


hallaFactorialASM:
;int rdi<-i
;inicializamos variables
mov rax,1               ;rax será el i
cvtsi2sd    xmm0,rax   ;guardamos la respuesta en xmm0
inc rdi                 ;rdi será el n                ;rax <-2
xor rdx,rdx


loop:
    cmp rax,rdi
    je salimos
    cvtsi2sd xmm1,rax
    mulsd xmm0,xmm1
    inc rax
    jmp loop
salimos:
    ret
