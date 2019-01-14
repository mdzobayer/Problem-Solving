#include <stdio.h>

int main() {
    int row, space, rows, i, j, k, star=0;
    printf("Enter the number of rows in pyramid\n");
    scanf("%d",&rows);

    for(row = 1;row <= rows; row++) {
        for (k = 1; k < rows; ++k) {
            printf("  ");
        }
        for(space = 0; space <= rows-row; space++) {
           printf("  ");
        }
        while(star != (2*row - 1)) {
            printf("* ");
            star++;;
        }
        star=0;
        printf("\n");
    }
    printf("\n");

    for(i = 1; i <= rows; i++) {
        for(space = 0; space <= (rows - i); space++) {
                printf("  ");
        }
        for(j = 1; j <= i; ++j) {
           printf("* ");
        }
        for(space = 0 ; space <= (rows*3) - 1; ++space) {
                printf(" ");
        }
        for(j = i; j > 0; --j) {
           printf("* ");
        }

        printf("\n");
    }
    for(i = rows - 1; i > 0; i--) {
        for(space = 0; space <= (rows - i); space++) {
                printf("  ");
        }
        for(j = i; j > 0; j--) {
           printf("* ");
        }
        for(space = 0 ; space <= (rows*3) - 1; ++space) {
                printf(" ");
        }
        for(j = i; j > 0; j--) {
           printf("* ");
        }
        printf("\n");
    }

    printf("\n");

    for(row = rows;row >= 1; row--) {
        for (k = 1; k < rows; ++k) {
            printf("  ");
        }
        for(space = 0; space <= rows-row; space++) {
           printf("  ");
        }
        star = 0;
        while(star != (2*row - 1)) {
            printf("* ");
            star++;
        }
        printf("\n");
    }

    return (0);
}
