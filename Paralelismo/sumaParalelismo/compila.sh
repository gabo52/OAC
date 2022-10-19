nasm -g -f elf64  asmVecSum.asm -o asmVecSum.o
gcc -g asmVecSum.o sumaParalelismo.c -o sumaParalelismo -lm
./sumaParalelismo
