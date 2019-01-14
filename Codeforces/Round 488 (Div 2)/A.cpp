#include <bits/stdc++.h>


using namespace std;

vector < int > vt;


int main() {

    int n, m, i, x;
    bool use[12];
    memset(use, 0, sizeof(use));
    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> x;
        vt.push_back(x);
    }
    for (i = 0; i < m; ++i) {
        cin >> x;
        use[x] = true;
    }
    bool flag = true;
    for (i = 0; i < n; ++i) {
        if(use[vt[i]]) {
            cout << vt[i] << " ";
            flag = false;
        }
    }
    if (flag) cout << endl;

    return (0);
}
