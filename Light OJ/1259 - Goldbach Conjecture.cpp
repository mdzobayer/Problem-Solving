#include <bits/stdc++.h>

using namespace std;
#define N 10000000 + 10
#define LLI long long int
bool prime[N];
vector < int > v;

void sieve() {
    LLI i, j;
    memset(prime, true, sizeof(prime));
    for ( i = 2; i < sqrt(N); ++i) {
        for ( j = i * i; j <= N; j += i) {
            prime[j] = false;
        }
    }
    for (i = 2; i <= N; ++i) {
        if(prime[i]) v.push_back(i);
    }
}

int main() {

    int test, t = 0, n, conn, i;
    sieve();
    cin >> test;
    for (t = 1; t <= test; ++t) {
        conn = 0;
        cin >> n;
        for (i = 0; v[i] <= n - v[i]; ++i) {
            if (prime[n - v[i]]) ++conn;
        }
        cout << "Case " << t << ": " << conn << endl;
    }

    return (0);
}
