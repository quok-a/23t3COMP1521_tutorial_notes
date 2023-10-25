/**
 * C function to multiply a matrix by a scalar.
 * 
 * nrows:  Number of rows in the matrix
 * ncols:  Number of columns in the matrix
 * M:      Matrix M
 * factor: Scalar factor to multiply by
 */
void change (int nrows, int ncols, int M[nrows][ncols], int factor)
{
    for (int row = 0; row < nrows; row++) {
        for (int col = 0; col < ncols; col++) {
            M[row][col] = factor * M[row][col];
        }
    }
}

//    li   $a0, 3
//    li   $a1, 4
//    la   $a2, M
//    li   $a3, 2
//    jal  change

//     .data
// M:  .word 1, 2, 3, 4
//     .word 3, 4, 5, 6
//     .word 5, 6, 7, 8