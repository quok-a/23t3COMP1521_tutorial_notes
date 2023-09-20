# Week 02 Tutorial
 
Mips, mipsy, mipsy web and debugging

The MIPS processor has 32 general purpose 32-bit registers, referenced as $0 .. $31. Some of these registers are intended to be used in particular ways by programmers and by the system. For each of the registers below, give their symbolic name and describe their intended use:

<details>
<summary> $0 </summary>

`$zero`
Read only register that always contains zero. Discards anything written to it. Useful as a source to copy constants into other registers or as a destination when we don't need to result of an instruction. 
</details>

<details>
<summary>$1</summary>

`$at`, assembler temporary. Ideally don't use it directly, is used by the assembler for various purposes, e.g. implementing conditional branch psuedo-instructions.
</details>

<details>
<summary>$2</summary>

`$v0` value register, holds return values from functions that return a single 32-bit result - $v0. $v1 can be used to return a second 32-bit result if needed.
</details>

<details>
<summary>$4</summary>

`$a0`, argument register. If the value fits into a 32-bit result we can use this. $a1, $a2, and $a3 can be used to hold additional arguments.

We use the stack to hold arguments that are larger than 32-bits
</details>

<details>
<summary>$8</summary>

`$t0`, temporary register. We have 10 of these in total from `$t0` to `$t9`. These values cannot be relied on to persist after a function call.
</details>

<details>
<summary>$16</summary>

`$s0`, saved registers. We have `$s0` through to `$s7` available to hold values that need to persist over function calls.

Note that this requires any function that uses these registers to save them to the stack and restore them before returning.
</details>

<details>
<summary>$26</summary>

`$k0` (and `$k1`) are reserved for the operating system. Don't use these.
</details>

<details>
<summary>$29</summary>

`$sp`, stack pointer. Holds the address of the top of the program's runtime stack. Its value will be reduced by each function call to store any required data.
</details>

<details>
<summary>$31</summary>

`$ra`, return address. If a linking instruction such as `jal` is called, then the address of the next instruction is stored in `$ra`. Useful in implementing function calls. `jr $ra` will return from a function to the correct location from where it was called.
</details>
