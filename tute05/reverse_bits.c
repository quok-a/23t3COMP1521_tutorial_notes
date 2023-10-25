#include <stdint.h>


typedef uint32_t Word; 
// is this a good type definition?
// what assumptions are we making?

// 0000 0001 0010 0011 0100 0101 0110 0111
// 1110 0110 1010 0010 1100 0100 1000 0000
Word reverseBits(Word w) {
    Word ret = 0;
    for (uint32_t bit = 0; bit < 32; bit++) {
        Word mask = 1 << bit;
        // 0001 -> 0010
        Word retmask = 1 << (31 - bit);
        // 0001 -> 0100

        if (w & mask) {
            ret = ret | retmask;
        }
    }

    return ret;
}

// testing
int main(void) {
    Word w1 = 0x01234567;
    // 0000 => 0000 = 0
    // 0001 => 1000 = 8
    // 0010 => 0100 = 4
    // 0011 => 1100 = C
    // 0100 => 0010 = 2
    // 0101 => 1010 = A
    // 0110 => 0110 = 6
    // 0111 => 1110 = E
    assert(reverseBits(w1) == 0xE6A2C480);
    puts("All tests passed!");
    return 0;
}
