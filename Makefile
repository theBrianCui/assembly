.PHONY: all
all : fib fib_asm

fib : fib.c
	gcc fib.c -O0 -g -o fib

fib_asm : fib_asm.c
	gcc fib_asm.c -O0 -g -o fib_asm
