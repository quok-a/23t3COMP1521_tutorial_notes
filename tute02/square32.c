// Squares a number, unless its square is too big for a 32-bit integer.
// If it is too big, prints an error message instead.

#include <stdio.h>

#define SQUARE_MAX 46340

int main(void) {
    int x, y;

    printf("Enter a number: ");
    scanf("%d", &x);

    if (x > SQUARE_MAX) goto x_gt_square_max;
    y = x * x;
    printf("%d\n", y);

    goto exit;

x_gt_square_max:
    printf("square too big for 32 bits\n");
    
exit:
    return 0;
}