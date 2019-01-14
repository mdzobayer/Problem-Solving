#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll digitSum(ll x) {
    ll sum = 0;
    while(x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    vector < ll > vt;
    ll n, i, x;
    cin >> n;
    for (i = max(n-81, 1ll); i < n; ++i) {
        if (i + digitSum(i) == n) {
            vt.push_back(i);
        }
    }
    cout << vt.size() << endl;
    for (i = 0; i < vt.size(); ++i) {
        cout << vt[i] << endl;
    }

    return (0);
}
