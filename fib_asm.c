#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t compute_fib(uint32_t index) {
    __asm__("push %rsi;"
            "movq 0x08(%rbp),%rsi;"
            "movq $1,%rax;"
            "movl %esi,%eax;");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: fib [index]\n");
        exit(0);
    }

    uint32_t index = atoi(argv[1]);
    printf("fib[%d]: %d\n", index, compute_fib(index));
}

