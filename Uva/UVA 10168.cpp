#include <cstdio>
#include <cstring>
#include <vector>
#define ld long long int

using namespace std;
bool prime[10000010];
vector<ld> primes;
void sieveOfEratosthenes(ld n) {

    ld i, j;

    /// Initialize all numbers as prime
    memset(prime, true, sizeof(prime));

    /// Cross out multiples of 2 (all even numbers less then or equal n without 2)
    for ( i = 4; i <= n; i += 2) {
        if (prime[i])
            prime[i] = false;
    }
    /// Cross out multiples of other true marked number (Ex 3, 5, 7 etc).
    for ( i = 3; i * i <= n; i += 2) {
        if (prime[i]) {
            for ( j = i + i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    for (i = 2; i < n; ++i) {
        if (prime[i])
            primes.push_back(i);
    }

}
int main() {
    //freopen("input.txt", "r", stdin);
    bool impossible;
    sieveOfEratosthenes(1000000);
    ld n, low, high;
    while(scanf("%lld", &n)) {
        if (n < 8) {
            printf("Impossible.\n");
        }
        else if (n % 2 == 0) {
            printf("2 2 ");
            n -= 4;
        }
        else {
            printf("2 3 ");
            n -= 5;
        }

        low = 0; high = n;

        while(low <= high) {

            if (primes[low] + primes[high] < n) {
                ++low;
            }
            else if ((primes[low] + primes[high]) > n)
                --high;
            else {
                printf("%lld %lld\n", primes[low] , primes[high]);
                break;
            }
        }

    }

    return (0);
}
