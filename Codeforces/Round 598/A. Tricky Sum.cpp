#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    ll t, n, x, ans;

    cin >> t;
    while(t--) {
        cin >> n;
        x = 1;
        while(x <= n) {
            x = x << 1;
        }
        //cout << x << endl;
        x = (x - 1) << 1;
        //cout << x << endl;
        ans = (((n * n) + n) >> 1);
        //
        cout << ans - x << endl;
    }

    return (0);
}
