#include <cstdio>

int main() {
    //freopen("input.txt", "r", stdin);
    int test, i;
    long long int num[5], max, sum;
    scanf("%d", &test);
    while(test--) {
        max = sum = 0;
        for (i = 0; i < 4; ++i) {
            scanf("%lld", &num[i]);
            if (max < num[i])
                max = num[i];
        }
        if ( num[0] == num[2] && num[1] == num[3]) {
            if (num[1] == num[2]) {
                printf("square\n");
            }
            else
                printf("rectangle\n");
            continue;
        }
        if ( num[0] == num[2] && num[1] == num[3]) {
            if (num[1] == num[2]) {
                printf("square\n");
            }
            else
                printf("rectangle\n");
            continue;
        }
        if ( num[0] == num[1] && num[2] == num[3]) {
            if (num[1] == num[2]) {
                printf("square\n");
            }
            else
                printf("rectangle\n");
            continue;
        }
        if ( num[0] == num[3] && num[1] == num[2]) {
            if (num[1] == num[3]) {
                printf("square\n");
            }
            else
                printf("rectangle\n");
            continue;
        }
        for (i = 0; i < 4; ++i) {
            sum += num[i];
        }
        sum -= max;
        if (max < sum)
            printf("quadrangle\n");
        else
            printf("banana\n");
    }

    return (0);
}
