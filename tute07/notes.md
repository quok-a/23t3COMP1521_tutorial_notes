# Week 05 Tutorial
 
Negative and floating point numbers


1. On a machine with 16-bit ints, the C expression (30000 + 30000) yields a negative result.
Why the negative result? How can you make it produce the correct result?
30000u + 30000u
use uint16_t

2. Assume that the following hexadecimal values are 16-bit twos-complement. Convert each to the corresponding decimal value.
```
-13 = 0b00001101 -> invert the bits = 0b11110011
0x0013 - 0b00010011
0x0444 - 0b0000 0100 0100 0100 = 2^2 + 2^6 + 2^10 = 1092
0x1234

0xffff - 0b1111 1111 1111 1111 = -1 * (0x0000 + 0x1) = - 0x1
0x8000 - 0b1000 0000 0000 0000 = 0b0111 1111 1111 1111 = 0x7fff * -1 + 1 =  -32766 

-2 - 0010, 1101 + 1 = 1110
``````

3. Give a representation for each of the following decimal values in 16-bit twos-complement bit-strings. Show the value in binary, octal and hexadecimal.
```
1
100
1000
10000
100000
-5
-100 
```

4. What decimal numbers do the following single-precision IEEE 754-encoded bit-strings represent?

> recall that floating point numbers are calculated using the formula `sign * (1 + frac) * 2^(exp - 127)`

```    
0 00000000 00000000000000000000000 = frac : `0*2^-1 + 0*2^-2 + 0*2^-3 +  ... + 0*2^-23`, `1 * (1 + 0) * 2^(0-127) = 1 * 2^-127` = 5.8774718e-39 = 0
1 00000000 00000000000000000000000 = -0
0 01111111 10000000000000000000000 = `1 * (1 + 1*2^-1) * 2^(127 - 127) = 1 * (1 + 0.5) * 1` = 1.5
0 01111110 00000000000000000000000
0 01111110 11111111111111111111111
0 10000000 01100000000000000000000 = `1 * (1 + (1*2^-2 + 1*2^-3)) * 2^(128-127) = (1 + 0.375) * 2^1 = 1.375 * 2 = 2.75`
0 10010100 10000000000000000000000 = `1 * (1 + 1*2^-1) * 2^(148-127) = 1*2^-1 * 2^21`
0 01101110 10100000101000001010000 
```

> Each of the above is a single 32-bit bit-string, but partitioned to show the sign, exponent and fraction parts.

5. Convert the following decimal numbers into IEEE 754-encoded bit-strings:
```
2.5    = sign 0, (1 + frac) * 2^n, frac = 2^1 + 1.25 = (1 + 0.25) * 2^(1 + 127), exp = 128
0.375  = sign 0, (1 + 0.5) * 2^(125 - 127)
27.0 
100.0 
```

