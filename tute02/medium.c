    #include <stdio.h>

    int main(void) {
        int x;
        printf("Enter a number: ");
        scanf("%d", &x);

        if (x > 100 && x < 1000) {
            printf("medium\n");
        } else {
            printf("small/big\n");
        }
    }


// // A simple program demonstrating how to represent a implementing an && in an
// // if-statement in MIPS.
// // This version: C, but a slightly less nice approach.

// #include <stdio.h>

// int main(void) {
//     int x;
//     printf("Enter a number: ");
//     scanf("%d", &x);

//     char *message = "small/big\n";
//     if (x > 100 && x < 1000) {
//         message = "medium";
//     }

//     printf("%s", message);
// }