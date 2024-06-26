#include <cstdio>
#include <cstring>
#define MAX 100

char X[MAX], Y[MAX];
int i, j, m, n, c[MAX][MAX], b[MAX][MAX];

int LCSlength() {
    m = strlen(X);
    n = strlen(Y);

    for (i = 1; i <= m; i++)
        c[i][0] = 0;
    for (i = 0; i <= n; i++)
        c[0][i] = 0;

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1; /// From north west
            }

            else if (c[i-1][j] >= c[i][j-1]) {
                c[i][j] = c[i-1][j];
                b[i][j] = 2; /// From north
            }
            else {
                c[i][j] = c[i][j-1];
                b[i][j] = 3; /// From west
            }
        }
    return c[m][n];
}
void printLCS(int i, int j) {
    if (i == 0 || j == 0) return;

    if (b[i][j] == 1) {
        printLCS(i - 1, j - 1);
        printf("%c", X[i - 1]);
    }
    else if (b[i][j] == 2)
        printLCS(i-1, j);
    else
        printLCS(i, j-1);
}
int main() {
    gets(X);
    gets(Y);
    //strcpy("ACCGGGTTAC",X);
    //strcpy("AGGAACCA", Y);

    printf("LCS length -> %d\n", LCSlength()); /// count length
    printLCS(m,n); /// Reconstruct LCS
    printf("\n");

    return (0);
}
