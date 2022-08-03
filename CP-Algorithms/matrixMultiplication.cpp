#include <bits/stdc++.h>

using namespace std;

int A[5][5], B[5][5], C[5][5];

void matrixMultiplication(int aRow, int aColumn, int bRow, int bColumn) {
    int i, j, k, sum;
    for (i = 0; i < aRow; ++i) {
        for (j = 0; j < bColumn; ++j) {
            sum = 0;
            for (k = 0; k < bRow; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }

}

int main() {

    A[0][0] = 1; A[0][1] = 4;
    A[1][0] = 3; A[1][1] = 9;
    A[2][0] = 8; A[2][1] = 6;

    B[0][0] = 1; B[0][1] = 6;
    B[1][0] = 2; B[1][1] = 9;

    matrixMultiplication(3, 2, 2, 2);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d ", C[i][j]);
        }
        puts("");
    }



    return (0);
}