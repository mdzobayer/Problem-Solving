#include <cstdio>

int main(int argc, char ** argv) {

    int a[3], Max, i, sumOfSq;

    while(scanf("%d%d%d", &a[0], &a[1], &a[2]) && a[0] > 0 && a[1] > 0 && a[2] > 0) {
        Max = a[0];
        sumOfSq = 0;
        for ( i = 1; i < 3; ++i ) {
            if (a[i] > Max)
                Max = a[i];
        }
        //printf("Max is %d\n", Max);
        for (i = 0; i < 3; ++i ) {
            if (a[i] != Max)
                sumOfSq += (a[i] * a[i]);
        }
        //printf("Sum is %d\n", sumOfSq);
        Max = ( Max * Max);
        if (Max == sumOfSq)
            printf("right\n");
        else
            printf("wrong\n");
    }


    return (0);
}
