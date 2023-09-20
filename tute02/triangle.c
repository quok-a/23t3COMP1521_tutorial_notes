// Prints a right - angled triangle of asterisks, 10 rows high.

#include <stdio.h>

int main(void) {

    int i = 1;
loop_i:

    if (i > 10) goto end_loop_i;

    int j = 0;
loop_j:

    if (j >= i) goto end_loop_j; 
    printf("*");    
    j++;

    goto loop_j;

end_loop_j:
    printf("\n");
    i++;

    goto loop_i;
    
end_loop_i:
    return 0;
}