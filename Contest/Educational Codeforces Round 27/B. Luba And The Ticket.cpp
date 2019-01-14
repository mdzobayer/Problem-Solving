#include <cstdio>

int main() {

    char str[10];
    int sum1 = 0, sum2 = 0, dif, i;
    scanf("%s", &str);

    for (i = 0; i < 3; ++i) {
        sum1 += str[i] - '0';
    }
    for (i ; i < 6; ++i) {
        sum2 += str[i] - '0';
    }
    if (sum1 == sum2) printf("0\n");
    else {
        dif = sum1 - sum2;
        if (dif < 0) dif *= -1;
        if (dif < 9) {
            printf("1\n");
        }
        else if (dif < 18) {
            printf("2\n");
        }
        else printf("3\n");

    }


    return (0);
}
