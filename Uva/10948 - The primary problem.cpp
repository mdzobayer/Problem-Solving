#include <bits/stdc++.h>
#define ll long long int
#define SIZE 1000005

using namespace std;

bool prime[SIZE];

void sieve (ll n) {

    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = false;
    ll i, j;
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

    sieve(SIZE - 2);

    int n, i;
    bool isFound;

    while(scanf("%d", &n) == 1) {

        if (n == 0) break;

        isFound = false;

        if (prime[n - 2] && prime[2]) {
            isFound = true;
            i = 2;
        }
        else {
            for (i = 3; i <= n; i += 2) {
                if (prime[n - i] && prime[i]) {
                    isFound = true;
                    break;
                }
            }
        }

        printf("%d:\n", n);
        if (isFound) {
            printf("%d+%d\n", i, n - i);
        }
        else {
            puts("NO WAY!");
        }

    }

    return (0);
}