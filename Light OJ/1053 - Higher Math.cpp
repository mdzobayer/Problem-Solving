#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main() {

    //freopen("in.txt", "r", stdin);

    ll test, t, a, b, c;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case %lld: ", t);

        a *= a;
        b *= b;
        c *= c;

        if (a == (b + c)) {
            printf("yes\n");
        }
        else if ((a + b) == c) {
            printf("yes\n");
        }
        else if (b == (a + c)) {
            printf("yes\n");
        }
        else {
            printf("no\n");
        }
    }

    return (0);
}
