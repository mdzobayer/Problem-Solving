#include <cstdio>
#include <vector>
#define N 4

int a;

int rows[N];
int cols[N];
int frontDia[2 * N];
int backDia[2 * N];

void print() {
    for (int i = 0; i < N * 2; ++i) {
        printf("%d ", backDia[i]);
    }
    printf("\n");
}
int calc(int row, int col) {
    int a = (col - row);
    if (a >= 0) {
        return a;
    }
    else {
        a *= -1;
        a += (N - 1);
        return a;
    }
}
bool NQueen(int grid[N][N], int n, int row, int col) {
    if (row >= (N - 1) && col >= (N - 1) && n != 0 ) {
        return false;
    }
    if (n == 0) {
        return true;
    }
    if (col > 3) {
        row += 1;
        col = 0;
    }
    int j;
    for (j = col; j < N; ++j) {
        //printf("%d. Hi i am here %d j = %d\n", ++a, n , j);
        int a = calc(row, j);
        //printf("i am here %d j %d\n", backDia[a], j);
        if ((rows[row] == 0) && (cols[j] == 0) && (frontDia[row + j] == 0) && (backDia[a] == 0)) {
            grid[row][j] = 1;
            rows[row] = 1;
            cols[j] = 1;
            frontDia[row + j] = 1;
            backDia[a] = 1;
            --n;
            printf("Queen insert at %d %d\n", row, j);
            //print();
            printf("backDia Index %d Value %d\n",calc(row,j), backDia[calc(row, j)]);
            if (NQueen(grid, n, row + 1, 0)) {

                return true;
            }
            else {
                rows[row] = 0;
                cols[j] = 0;
                frontDia[row + j] = 0;
                backDia[a] = 0;
                ++n;
                grid[row][j] = 0;
            }
        }
        //printf("Other option\n");
    }
    //if (rows[row] == 0) return false;

    return NQueen(grid, n, row, j + 1);
}

int main() {

    a = 0;

    int grid[N][N] = { 0 };
    for (int i = 0; i <= N; ++i) {
        rows[i] = cols[i] = frontDia[i] = backDia[i] = 0;
    }
    NQueen(grid, N, 0, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (grid[i][j] == 1)
                printf("1 ");
            else
                printf("_ ");
        }
        printf("\n");
    }

    return (0);
}
