#include <stdio.h>

int main() {

    int a[2][2], b[2][2], c[2][2];

    printf("Enter first 2 X 2 matrix elements: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter second 2 X 2 matrix elements: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &b[i][j]);
        }
    }
    printf("2 X 2 matrix is Adding: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            c[i][j] = a[i][j] + b[i][j];
        printf("..");
        }
    }

    printf("\n\nSummation of matrix ab is given below\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf(" %d ",c[i][j]);
        }
        printf("\n");
    }
    return (0);
}
