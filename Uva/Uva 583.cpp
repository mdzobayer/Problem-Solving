#include <cstdio>
#include <cstring>

int primes[7000];
int sieveOfEratosthenes(int n) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; ++p) {
        if (prime[p] == true) {
            for (int i = p * 2; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    int j = 0;
    for (int p = 2; p <= n; ++p) {
        if (prime[p])
            primes[j++] = p;
    }
    return j - 1;
}

int main() {

    int range, n, i;
    range = sieveOfEratosthenes(60000);

    while(scanf("%d", &n) == 1) {
        if (n == 0)
            break;
        printf("%d =", n);
        if (n < 0) {
            printf(" -1 x");
            n *= -1;
        }
        if (n == 1) {
            printf(" 1\n");
            continue;
        }
        for (i = 0; primes[i] < n && i <= range; ++i) {
            while(n % primes[i] == 0) {
                n /= primes[i];
                if (n > 1)
                    printf(" %d x", primes[i]);
                else
                    printf(" %d", primes[i]);
            }
        }
        if (n > 1) {
            printf(" %d", n);
        }
        printf("\n");
    }

    return (0);
}
