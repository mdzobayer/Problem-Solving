#include <cstdio>
#include <cstring>
#define ull unsigned long long int

bool prime[20000000 + 10];
int twinSeries[1000000];

void sieve (ull n) {

    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    ull i, j;
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
    for (i = 2, j = 1; i < 20000005; ++i) {
        if (prime[i] && prime[i + 2]){
            twinSeries[j++] = i;
        }
    }
}
int main() {
    sieve(20000000 + 5);

    int n;
    while(scanf("%d", &n) == 1) {
        printf("(%d, %d)\n", twinSeries[n], twinSeries[n] + 2);
    }

    return (0);
}
