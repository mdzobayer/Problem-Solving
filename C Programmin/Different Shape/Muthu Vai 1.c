#include <stdio.h>

int main() {

    int row, space, rows, i, j, k, star=0;
    printf("Enter the number of rows in pyramid\n");
    scanf("%d",&rows);

    printf("\n\n");
    for(row = rows;row >= 1; row--) {
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



    for(i = 1; i <= rows; i++) {
        printf(" ");
        for(j = 1; j <= i; ++j) {
           printf("* ");
        }
        printf(" ");
        for(space = 0; space <= ((rows * 2) - (j * 2)) + 1; space++) {
                printf("  ");
        }
        for (--j; j > 0; --j) {
            printf("* ");
        }
        printf("\n");
    }
    for(i = rows - 1; i > 0; i--) {
        printf(" ");
        for(j = i; j > 0; j--) {
           printf("* ");
        }
        printf(" ");
        for(space = ((rows * 2) - (i * 2)); space > 0 ; --space) {
                printf("  ");
        }
        for (j = i; j > 0; --j) {
            printf("* ");
        }
        printf("\n");
    }


    star = 0;
    for(row = 1;row <= rows; row++) {
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

    return (0);
}
