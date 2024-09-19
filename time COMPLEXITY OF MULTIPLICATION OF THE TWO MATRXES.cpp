#include <stdio.h>

void matrixMultiply(int A[][2], int B[][3], int result[][3], int m, int n, int p) {
    // Initialize the result matrix to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[3][2] = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    int B[2][3] = {
        {7, 8, 9},
        {10, 11, 12}
    };
    int result[3][3]; // Resultant matrix of size 3x3

    int m = 3, n = 2, p = 3; // Dimensions of matrices

    matrixMultiply(A, B, result, m, n, p);

    // Print the resultant matrix
    printf("Resultant Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    printf("Time Complexity: O(%d * %d * %d)\n", m, n, p);

    return 0;
}
