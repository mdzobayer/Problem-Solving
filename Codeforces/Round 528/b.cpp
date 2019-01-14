#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int i, mod, r ,n, k, j = -1, x;
    cin >> n >> k;

    for (mod = 1; mod < k; ++mod) {

        if(n % mod != 0) continue;

        r = n / mod;
        x = (r * k) + mod;
        //cout << x << endl;
        if(j == -1) j = x;
        j = min(j, x);
    }
    cout << j << endl;

    return (0);
}
