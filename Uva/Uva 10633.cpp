#include <cstdio>

int main() {
    unsigned long long int n, answer;
    while(scanf("%llu", &n) == 1) {
        if (n == 0)
            break;
        answer = (n * 10) / 9;
        if (n % 9 == 0)
            printf("%llu %llu\n", answer - 1, answer);
        else
            printf("%llu\n", answer);
    }
    return (0);
}
