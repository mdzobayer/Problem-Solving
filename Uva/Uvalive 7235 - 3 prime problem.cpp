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

    lli n, i, test, low, high;
    scanf("%lld", &test);
    while(test--) {
        scanf("%lld", &n);
        if ( n < 7 ) {
            printf("0\n");
        }
        else {
            printf("2 ");
            n -= 2;
            low = 2; high = n - 1;
            while(low <= high) {

                while(!prime[low]) ++low;
                while(!prime[high]) --high;

                if (low + high < n)
                    ++low;
                else if (low + high > n)
                    --high;
                else {
                    printf("%lld %lld\n",low, high);
                    break;
                }
            }
        }
    }

    return (0);
}


