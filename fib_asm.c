#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t compute_fib(uint32_t index) {
    __asm__("cmpl $0,%edi;"
            "jne not_zero;"
            "movl $0,%eax;"
            "jmp end_fun;"
            
            "not_zero:"
            "movl $1,-0x8(%rbp);" //i
            "movl $0,-0xc(%rbp);" //prev
            "movl $1,-0x10(%rbp);" //current
            
            "begin_loop:"
            "mov -0x8(%rbp),%eax;" //check i < index
            "cmpl %edi,%eax;"
            "jge end_loop;"
            
            "mov -0x10(%rbp),%eax;"
            "add -0xc(%rbp),%eax;" //%eax stores new
            "mov -0x10(%rbp),%edx;"
            "mov %edx,-0xc(%rbp);"
            "mov %eax,-0x10(%rbp);"
            "mov -0x8(%rbp),%eax;" //++i
            "add $1,%eax;"
            "mov %eax,-0x8(%rbp);"
            "jmp begin_loop;"

            "end_loop:"
            "mov -0x10(%rbp),%eax;"
            "end_fun:");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: fib [index]\n");
        exit(0);
    }

    uint32_t index = atoi(argv[1]);
    printf("fib[%d]: %d\n", index, compute_fib(index));
}

