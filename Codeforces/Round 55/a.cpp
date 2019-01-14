#include <bits/stdc++.h>
#define ll long long int

using namespace std;


int main() {

    freopen("in.txt", "r", stdin);

    ll test, n, x, y, d, ans1, ans2, xx, yy;
    cin >> test;
    while(test--) {
        cin >> n >> x >> y >> d;
        xx = n - x;
        yy = n - y;
        if(x % d == 0 && y % d == 0) {
            ans1 = x / d;
            ans2 = y / d;
            cout << abs(ans1 - ans2) << endl;
        }
        else if(x % d != 0 && y % d == 0) {
            ans1 = x / d;
            ++ans1;
            ans1 += (y / d);

            if(xx % d != 0 && yy % d == 0) {
                ans2 = xx / d;
                ans2++;
                ans2 += (yy / d);
            }
            else {ans2 = LLONG_MAX;}
            cout << min(ans1, ans2) << endl;
        }
        else if(xx % d != 0 && yy % d == 0) {
            ans2 = xx / d;
            ans2++;
            ans2 += (yy / d);

            cout << ans2 << endl;
        }
        else cout << "-1" << endl;

    }

    return (0);
}
