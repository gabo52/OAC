    nasm -f elf64  hallaPotenciaASM.asm -o hallaPotenciaASM.o
    nasm -f elf64  hallaFactorialASM.asm -o hallaFactorialASM.o
    gcc	hallaFactorialASM.o hallaPotenciaASM.o TaylorEuler.c -o TaylorEuler -lm
./TaylorEuler
