    nasm -f elf64  SIMDConstrastStretch.asm -o SIMDConstrastStretch.o
    nasm -f elf64  ASMConstrastStretch.asm -o ASMConstrastStretch.o
    gcc	ASMConstrastStretch.o SIMDConstrastStretch.o Matriz.c -o Matriz -lm
./Matriz
