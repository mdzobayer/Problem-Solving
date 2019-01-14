#include <cstdio>
#include <cstring>
#include <cmath>

bool isPrime(int n) {
    if (n == 1)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    int i, range = sqrt(n);
    for (int i = 3; i <= range; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    char input[2010];
    int test, t, len, i, j, numbers[125], k;
    scanf("%d", &test);
    getchar();
    for ( t = 1; t <= test; ++t) {
        gets(input);
        len = strlen(input);
        for (k = 0; k < 125; ++k) {
            numbers[k] = 0;
        }
        for (i = 0; i < len; ++i) {
            if ((input[i] >= 'A' && input[i] <= 'Z') || (input[i] >= '0' && input[i] <= '9') || (input[i] >= 'a' && input[i] <= 'z')) {
                numbers[input[i]] += 1;
            }
        }
        len = 0;
        printf("Case %d: ", t);
        for (j = 30; j <= 124; ++j) {
            if (isPrime(numbers[j])) {
                len++;
                printf("%c", j);
            }
        }
        if (len == 0) {
            printf("empty");
        }
        putchar('\n');
    }

    return (0);
}
