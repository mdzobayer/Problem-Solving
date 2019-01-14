#include <cstdio>
long long int fib[100];
int main() {

    fib[0] = 0;
    fib[1] = 1;

    int i;
    for (i = 2; i < 40; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (i = 0; i < 40; ++i) {
        printf("%lld ", fib[i]);
    }

    return (0);
}
