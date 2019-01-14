#include <cstdio>

int main() {

    long long int n, a, b, denies = 0, i, arr;
    scanf("%lld %lld %lld", &n, &a, &b);
    for (i = 0; i < n; ++i) {
        scanf("%lld", &arr);
        if(arr == 2 && b < 1) {
            denies++;
            denies++;
        }
        else if (arr == 2) {
            --b;
        }
        else if (arr == 1 && a < 1 && b < 1) {
            denies++;
        }
        else if (arr == 1 && a > 0) {
            --a;
        }
        else if (arr == 1 && b > 0) {
            --b;
            ++a;
        }
        //printf("a = %d b = %d\n", a, b);
    }
    printf("%lld\n", denies);

    return (0);
}
