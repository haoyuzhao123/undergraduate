/* 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, k, l, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8;

    if (M == 32) {
        for (i = 0; i < N; i+=8) {
            for (j = 0; j < M; j+=8) {
                for (k = i; k < i+8; k++) {
                    for (l = j; l < j+8; l+=8) {
                        tmp1 = A[k][l];
                        tmp2 = A[k][l+1];
                        tmp3 = A[k][l+2];
                        tmp4 = A[k][l+3];
                        tmp5 = A[k][l+4];
                        tmp6 = A[k][l+5];
                        tmp7 = A[k][l+6];
                        tmp8 = A[k][l+7];
                        B[l][k] = tmp1;
                        B[l+1][k] = tmp2;
                        B[l+2][k] = tmp3;
                        B[l+3][k] = tmp4;
                        B[l+4][k] = tmp5;
                        B[l+5][k] = tmp6;
                        B[l+6][k] = tmp7;
                        B[l+7][k] = tmp8;
                    }
                }
            }
        }
    } else if (M == 64) {
        //devide into 8x8 small matrices
        for (i = 0; i < N; i+=8) {
            for (j = 0; j < M; j+=8) {
                //devide 8x8 matrix into 4 4x4 matrix
                //transpose the upperleft matrix
                l = j;
                for (k = i; k < i+4; k++) {
                    tmp1 = A[k][l];
                    tmp2 = A[k][l+1];
                    tmp3 = A[k][l+2];
                    tmp4 = A[k][l+3];

                    B[l][k] = tmp1;
                    B[l+1][k] = tmp2;
                    B[l+2][k] = tmp3;
                    B[l+3][k] = tmp4;
                }
                //transpose the upperright matrix and store it in the upper right of B
                l = j+4;
                for (k = i; k < i+4; k++) {
                    tmp1 = A[k][l];
                    tmp2 = A[k][l+1];
                    tmp3 = A[k][l+2];
                    tmp4 = A[k][l+3];

                    B[l-4][k+4] = tmp1;
                    B[l-3][k+4] = tmp2;
                    B[l-2][k+4] = tmp3;
                    B[l-1][k+4] = tmp4;
                }
                //transpose the lowerleft and the upper right
                k = i;
                for (l = j+4; l < j+8; l++) {
                    tmp1 = A[k+4][l-4];
                    tmp2 = A[k+5][l-4];
                    tmp3 = A[k+6][l-4];
                    tmp4 = A[k+7][l-4];

                    tmp5 = B[l-4][i+4];
                    tmp6 = B[l-4][i+5];
                    tmp7 = B[l-4][i+6];
                    tmp8 = B[l-4][i+7];

                    B[l-4][i+4] = tmp1;
                    B[l-4][i+5] = tmp2;
                    B[l-4][i+6] = tmp3;
                    B[l-4][i+7] = tmp4;

                    B[l][k] = tmp5;
                    B[l][k+1] = tmp6;
                    B[l][k+2] = tmp7;
                    B[l][k+3] = tmp8;

                    B[l][i+4] = A[i+4][l];
                    B[l][i+5] = A[i+5][l];
                    B[l][i+6] = A[i+6][l];
                    B[l][i+7] = A[i+7][l];
                }
            }
        }
    } else {
        tmp2 = 22;
        for (i = 0; i < N; i+=tmp2) {
            for (j = 0; j < M; j+=tmp2) {
                for (k = i; k < i+tmp2 && k < N; k++) {
                    for (l = j; l < j+tmp2 && l < M; l++) {
                        tmp1 = A[k][l];
                        B[l][k] = tmp1;
                    }
                }
            }
        }
    }
}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

