#include <bits/stdc++.h>
#define SIZE 5000000
#define ll long long int

using namespace std;
bool prime[SIZE+5];
int record[SIZE+5];

void sieve() {
    int i, j, sz;
    memset(prime, true, sizeof(prime));
    memset(record, 0, sizeof(record));
    sz = sqrt(sz) + 1;
    for (i = 4; i < SIZE; i += 2) {
        prime[i] = false;
    }

    for (i = 3; i <= sz; i += 2) {
        if (prime[i]) {
            for (j = i + i; j < SIZE; j += i) {
                prime[j] = false;
            }
        }
    }

    record[0] = record[1] = 0;
    for (i = 2; i < SIZE; ++i) {
        if (prime[i])
            record[i] = record[i-1] + 1;
        else record[i] = record[i-1];
    }
}

int main() {

    int test, t, i, x, y;
    ll result;

    return (0);
}
