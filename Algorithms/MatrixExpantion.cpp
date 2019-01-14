#include <cstdio>
#define lli long long int

lli a[2][2], b[2][2], res[2][2], c[2][2], d[2][2], modValue;

bool matrixMultiplication(lli a[2][2], lli b[2][2], lli res[2][2], lli ar, lli ac, lli br, lli bc) {
    if (ac != br) {
        return false;
    }
    lli i, j, sum, k;
    for (i = 0; i < ar; ++i) {
        for (j = 0; j < ac; ++j) {
            sum = 0;
            for (k = 0; k < br; ++k) {
                sum += a[i][k] * b[k][j];
            }
            res[i][j] = sum % modValue;
        }
    }
    return true;
}

void calculate(lli range){

    lli i, j;
    if (range == 1) {
        for (i = 0; i < 2; ++i) {
            for (j = 0; j < 2; ++j) {
                b[i][j] = a[i][j];
            }
        }
        return ;
    }

    if (range % 2 == 0) {
        calculate(range / 2);
        matrixMultiplication(b, b, res, 2, 2, 2, 2);
        for (i = 0; i < 2; ++i) {
            for (j = 0; j < 2; ++j) {
                b[i][j] = res[i][j];
            }
        }
    }
    else {
        calculate(range / 2);
        matrixMultiplication(b, b, res, 2, 2, 2, 2);
        matrixMultiplication(res, a, b, 2, 2, 2, 2);
    }
}

int main() {


    a[0][0] = 1;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 0;

    b[0][0] = 0;
    b[0][1] = 0;
    b[1][0] = 0;
    b[1][1] = 0;

    c[0][0] = 1;
    c[0][1] = 0;
    c[1][0] = 0;
    c[1][1] = 0;

    d[0][0] = 0;
    d[0][1] = 0;
    d[1][0] = 0;
    d[1][1] = 0;

    lli test, t, A, B, range;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld %lld %lld %lld", &A, &B, &range, &modValue);
        c[0][0] = B;
        c[0][1] = 0;
        c[1][0] = A;
        c[1][1] = 0;
        if (modValue == 4) modValue = 10000;
        else if (modValue == 3) modValue = 1000;
        else if (modValue == 2) modValue = 100;
        else if (modValue == 1) modValue = 10;

        calculate(range);

        matrixMultiplication(b, c, res, 2, 2, 2, 2);
        printf("Case %lld: %lld\n", t, res[1][0]);
        /*
        lli i , j;

        for ( i = 0; i < 2; ++i) {
            for ( j = 0; j < 1; ++j) {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
        */
    }

    return (0);
}
