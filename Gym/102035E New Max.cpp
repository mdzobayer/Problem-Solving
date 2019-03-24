#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, m, k, x, i, wa = 0, co = 0;
    cin >> n >> m >> k;
    for (i = 0; i < n; ++i) {
        cin >> x;
        if (x > m) ++wa;
        else if (x == m) ++co;
    }
    
    if (wa > k) {
        cout << "NO" << endl;
    }
    else if (wa < k){
        cout << "YES" << endl;
    }
    else if(k > 0 || co > 0) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;

    return (0);
}