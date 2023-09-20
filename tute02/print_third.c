// Print every third number from 24 to 42.
#include <stdio.h>

int main(void) {
    // This 'for' loop is effectively equivalent to a while loop.
    // i.e. it is a while loop with a counter built in.
    int x = 24;
count_loop:
    if (x >= 42) goto exit;
    // for (int x = 24; x < 42; x += 3) {
    // printf("%d\n", x);
    printf("%d", x);
    printf("\n");
    x += 3;
goto count_loop

exit:
    return 0;
}