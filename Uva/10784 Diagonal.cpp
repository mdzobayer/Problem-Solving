#include <bits/stdc++.h>
#define ull long long int
using namespace std;

ull build(ull x) {
    ull res = ((x * x) - (3 * x))/2;
    return res;
}

int main() {

    ull n, t = 1;
    while(scanf("%lld", &n) == 1) {
        if(n == 0) break;

        ull ans, mid, low = 1, high = 1e8;

        while(low <= high) {
            mid = (low + high) / 2;
            if(n <= build(mid)) {
                high = mid - 1;
                ans = mid;
            }
            else if (n > build(mid)) {
                low = mid + 1;
            }

        }

        printf("Case %lld: %lld\n", t++, ans);
    }

    return (0);
}
