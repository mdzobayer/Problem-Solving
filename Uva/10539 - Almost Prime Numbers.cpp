#include <bits/stdc++.h>
#define ull unsigned long long int
#define pb push_back

using namespace std;

vector < ull > primes, almostPrime;
vector < ull >::iterator it;

ull test, high, low;

void isAddAble(const ull & tmp) {
    ull SIZE;
    SIZE = sqrt(tmp) + 1;
    for (int i = 1; primes[i] < SIZE; ++i) {
        if (tmp % primes[i] == 0) return;
    }
    primes.pb(tmp);
}

int main() {

    primes.pb(2);
    primes.pb(3);

    ull maximum, tmp;
    for (int i = 5; i < 1000000; i += 4) {
        isAddAble(i);
        isAddAble(i+=2);
    }
    maximum = 1000000000001;
    for (int i = 0; i < primes.size(); ++i) {
        tmp = (primes[i] * primes[i]);
        while(tmp < maximum) {
            almostPrime.pb(tmp);
            tmp *= primes[i];
        }
    }

    sort(almostPrime.begin(), almostPrime.end());



    scanf("%llu", &test);
    while(test--) {
        scanf("%llu %llu", &low, &high);
        it = upper_bound(almostPrime.begin(), almostPrime.end(), high);
        printf("%llu\n",(ull) (it - lower_bound(almostPrime.begin(), it, low)));
    }

    return (0);
}
