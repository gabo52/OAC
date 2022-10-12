    nasm -f elf64  hallaPotenciaASM.asm -o hallaPotenciaASM.o
    nasm -f elf64  hallaFactorialASM.asm -o hallaFactorialASM.o
    gcc	hallaFactorialASM.o hallaPotenciaASM.o TaylorCos.c -o TaylorCos -lm
./TaylorCos
