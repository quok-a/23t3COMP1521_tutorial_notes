// rite a C program, `print_file_bits.c`, which given as a command line arguments the name of 
// a file contain 32-bit hexadecimal numbers, one per line, prints the low (least significant) bytes of each number 
// as a signed decimal number (-128..127).

#include <stdio.h>
#include <stdint.h>

int main (int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (f == NULL) {
        perror (argv[1]);
        return;
    }

    uint32_t num;
    while (fscanf(f, "%x", &num) == 1) { 
        int32_t low = num & 0xff; // 0b0000 1000 -> 0b0000 0000 0000 0000 0000 0000 0000 1000

        if (low & (1 << 7)) { // 0b1000 1000 -> 0b1111 1111 1111 1111 1111 1111 1000 1000
            low |= 0xffffff00;
        }

        printf("%d\n", low)

    }
    fclose(f);
    return 0;
}