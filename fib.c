#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint32_t compute_fib(uint32_t index) {
    if (0 == index) {
        return 0;
    }

    uint32_t i = 1;
    uint32_t prev = 0;
    uint32_t current = 1;
    for (i = 1; i < index; ++i) {
        uint32_t new = current + prev;
        prev = current;
        current = new;
   }

    return current;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: fib [index]\n");
        exit(0);
    }

    uint32_t index = atoi(argv[1]);
    printf("fib[%d]: %d\n", index, compute_fib(index));
}
