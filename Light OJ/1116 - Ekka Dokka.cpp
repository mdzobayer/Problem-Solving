#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main() {

    ll test, t, w, even, odd;

    cin >> test;
    for (t = 1; t <= test; ++t) {
        cin >> w;
        printf("Case %lld: ", t);
        if (w % 2) {
            printf("Impossible\n");
        }
        else {
            even = 1;
            while(w % 2 == 0) {
                even *= 2;
                w /= 2;
            }
            odd = w;
            printf("%lld %lld\n", odd, even);
        }
    }

    return (0);
}
