// sum 4 numbers using function calls

#include <stdio.h>

int sum4(int a, int b, int c, int d);
int sum2(int x, int y);

int main(void) {
    int result = sum4(11, 13, 17, 19);
    printf("%d\n", result);
    return 0;
}

int sum4(int a, int b, int c, int d) {
    int res1 = sum2(a, b);
    int res2 = sum2(c, d);
    return sum2 (res1, res2);
}

int sum2(int x, int y) {
    return x + y;
}