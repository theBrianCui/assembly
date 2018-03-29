fib : fib.c
	gcc fib.c -O0 -g -m32 -o fib

fib_asm : fib_asm.c
	gcc fib_asm.c -O0 -g -m32 -o fib_asm
