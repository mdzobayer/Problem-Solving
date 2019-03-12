#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i, s, e, k;
    vector < int > vt;
    cin >> n;
    for (i = 0; i < n ; ++i) {
        cin >> s >> e;
        vt.push_back(e);
    }
    cin >> k;
    --k;
    if(k == 0) {
        cout << n << endl;
        return (0);
    }
    for (i = 0; i < n; ++i) {
        if (k <= vt[i]) {
            if(k == vt[i])
            cout << n - (i+1) << endl;
            else
            cout << n - i << endl;
            return (0);
        }
    }

    return (0);
}
