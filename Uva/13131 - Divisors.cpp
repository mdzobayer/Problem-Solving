#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll test, n, k, sz, i, sum, x;
    scanf("%lld", &test);

    while(test--) {
        scanf("%lld %lld", &n, &k);
        if (k == 1) {
            puts("0");
            continue;
        }
        sz = sqrt(n);
        sum = 0;
        for (i = 1; i <= sz; ++i) {
            if (n % i == 0) {
                x = n / i;
                //cout << i << ' ' << x << endl;
                if (i % k) sum += i;
                if (i != x && x % k) sum += x;
                //cout << sum << endl;
            }
        }
        printf("%lld\n", sum);
    }

    return (0);
}
