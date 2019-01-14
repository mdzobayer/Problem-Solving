#include <cstdio>
#include <cstring>

bool prime[1000010];

void sieveOfEratosthenes(int n) {

    int i, j;

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

}
int main() {
    //freopen("input.txt", "r", stdin);
    bool impossible;
    sieveOfEratosthenes(1000000);
    int n, low, high;
    while(scanf("%d", &n)) {
        if (n == 0) break;
        low = 2; high = n - 1;
        impossible = true;
        while(low <= high) {

            while(!prime[low]) ++low;
            while(!prime[high]) --high;
            if (low + high < n)
                ++low;
            else if (low + high > n)
                --high;
            else {
                impossible = false;
                printf("%d = %d + %d\n", n, low, high);
                break;
            }
        }
        if (impossible)
            printf("Goldbach's conjecture is wrong.\n");
    }

    return (0);
}
