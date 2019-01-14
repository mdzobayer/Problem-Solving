#include <cstdio>
#include <cstring>
#define lli long long int

bool prime[10000010];

void sieve (lli n) {

    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    lli i, j;
    for (i = 4; i <= n; i += 2) {
        prime[i] = false;
    }

    for (i = 3; i * i <= n; i += 2) {
        if (prime[i]) {
            for (j = i * 2; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}

int main() {

    sieve(10000002);

    lli n, i;
    while(scanf("%lld", &n) == 1) {
        if ( n < 8 ) {
            printf("Impossible\n");
        }
        else if ( n % 2 ) {
            printf("2 3 ");
            n -= 5;
            for (i = 3; i <= 10000000; i += 2) {
                if (prime[n - i] && prime[i]) {
                    printf("%lld %lld\n", i, n - i);
                    break;
                }
            }
        }
        else {
            printf("2 2 ");
            n -= 4;
            for (i = 3; i <= 10000000; i += 2) {
                if (prime[n - i] && prime[i]) {
                    printf("%lld %lld\n", i, n - i);
                    break;
                }
            }
        }
    }

    return (0);
}
