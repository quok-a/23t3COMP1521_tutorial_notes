// A simple program that adds 42 to each element of an array

#define N_SIZE 10

int main(void) {
    int i;
    int numbers[N_SIZE] = {0, 1, 2, -3, 4, -5, 6, -7, 8, 9};
    // compound types in MIPS (arrays/structs) must be aligned so their
    // components are aligned
    i = 0;
loop:
    if (numbers[i] >= N_SIZE) goto loop_end;
    //while (i < N_SIZE) {
    if (numbers[i] >= 0) goto num_pos;
    number[i] += 42;
        // if (numbers[i] < 0) {
        //     numbers[i] += 42;
        // }

num_pos:
    i++;
    goto loop;
    //}
loop_end:
}