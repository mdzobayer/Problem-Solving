#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

bool prime[1010];
int count[1010];
vector<int> primes;

void sieveOfEratosthenes(int n) {

    int i, j;

    /// Initialize all numbers as prime
    memset(prime, true, sizeof(prime));
    memset(count, 0, sizeof(count));

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
    primes.push_back(0);

    for (i = 1; i < n; ++i) {
        if (prime[i]) {
            count[i] = count[i - 1] + 1;
            primes.push_back(i);
        }
        else {
            count[i] = count[i - 1];
        }
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("in.txt", "w", stdout);
    sieveOfEratosthenes(1005);
    int n, c, range, j, middle;
    while(scanf("%d %d", &n, &c) == 2) {

        range = c * 2;
        printf("%d %d: ", n, c);
        //printf("Count[%d] is %d\n", n, count[n]);
        if (range >= count[n]) {
            for (j = 1; j <= count[n]; ++j) {
                printf("%d", primes[j]);
                if (j < count[n])
                    putchar(' ');
            }
        }
        else if (count[n] % 2 == 0) {
            middle = count[n] / 2;
            for (j = (middle - c + 1); j <= middle; ++j) {
                printf("%d", primes[j]);
                if (j < middle)
                    putchar(' ');
            }
            j = (middle + 1);
            if (j <= (middle + c))
                putchar(' ');
            for ( ; j <= (middle + c); ++j) {
                printf("%d", primes[j]);
                if (j < middle + c)
                    putchar(' ');
            }
        }
        else {
            middle = (count[n] / 2) + 1;
            for (j = (middle - c + 1); j <= middle; ++j) {
                printf("%d", primes[j]);
                if (j < middle)
                    putchar(' ');
            }
            j = (middle + 1);
            if (j <= (middle + c - 1))
                putchar(' ');
            for (; j <= (middle + c - 1); ++j) {
                printf("%d", primes[j]);
                if (j < (middle + c - 1))
                    putchar(' ');
            }
        }
        putchar('\n');
        putchar('\n');
    }

    return (0);
}
