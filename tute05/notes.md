# Week 05 Tutorial
 
Types and bases

Assignment is due this **Friday** at 8pm.

<details>
<summary> When should the types in stdint.h be used: </summary>

You are only guaranteed a minimum number of bits with standard types in c.

https://en.wikipedia.org/wiki/C_data_types
</details>

```
#include <stdint.h>

                 // range of values for type
                 //             minimum               maximum
    int8_t   i1; //                 -128                  127
    uint8_t  i2; //                    0                  255
    int16_t  i3; //               -32768                32767
    uint16_t i4; //                    0                65535
    int32_t  i5; //          -2147483648           2147483647
    uint32_t i6; //                    0           4294967295
    int64_t  i7; // -9223372036854775808  9223372036854775807
    uint64_t i8; //                    0 18446744073709551615
```

What bases are the following numbers in?
Which of them are valid c?

- `0b10`
- `0x64`
- `0144`
- `0`

Convert the following to binary, octal and hex:

- 1, 0b1, 01, 1
- 8, 0b1000, 10, 0x8
- 10
- 15
- 16, 0b10000, 0x10, 020
- 100, 0b01100100, 0x0x64
- 127
- 200


<details>
<summary> Conversion in C: </summary>

`printf("%d = 0%3o = 0x%2x\n", 100, 100, 100);`
</details>

Given the following:
`uint16_t a = 0x5555, b = 0xAAAA, c = 0x0001;`

a  = 0101010101010101
b  = 1010101010101010
~b = 0101010101010101
c  = 0000000000000001
~c = 0xfffe

What are the values of the following expressions:

- `a | b` (bitwise OR) = `0xFFFF`
- `a & b` (bitwise AND) = `0x0000`
- `a ^ b` (bitwise XOR) = `0xFFFF`
- `a & ~b` (bitwise AND) = `0x5555`
- `c << 6` (left shift) = 0000 0000 0100 0000 = 0040
- `a >> 4` (right shift) = 0000 0101 0101 0101 = 0555
- `a & (b << 1)` = 010101010101 0100
- `b | c` = aaab
- `a & ~c` = 


```
#define READING   0x01 - 0b0000 0001
#define WRITING   0x02 - 0b0000 0010
#define AS_BYTES  0x04 - 0b0000 0100
#define AS_BLOCKS 0x08 - 0b0000 1000
#define LOCKED    0x10 - 0b0001 0000
```

`unsigned char device;`

device = READING | AS_BYTES | LOCKED = 0b0001 0101

mark the device as locked for reading bytes

device = WRITING | AS_BLOCKS | LOCKED

mark the device as locked for writing blocks

device = device | LOCKED

set the device as locked, leaving other flags unchanged

device = device & ~LOCKED, 0b1110 1111

remove the lock on a device, leaving other flags unchanged
switch a device from reading to writing, leaving other flags unchanged

device = device ^ (READING | WRITING)

swap a device between reading and writing, leaving other flags unchanged 