#include <bits/stdc++.h>

using namespace std;
bool mark[2000000+5];

vector < int > xs, ys;

int main() {

    memset(mark, 0, sizeof(mark));
    int n, i, x, t, j, conn = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        //cout << "input " << x << endl;
        xs.push_back(x);
        mark[x] = true;
    }
    //sort(xs.begin(), xs.end());
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        ys.push_back(x);
        //cout << "input2 " << x << endl;
        mark[x] = true;
    }
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            t = (xs[j] ^ ys[i]);
            //cout << "Tmp " << t << endl;
            if (t > 2000000) continue;
            if (mark[t])
                ++conn;
        }
    }
    //cout << conn << endl;
    if (conn % 2 == 0) {
        cout << "Karen" << endl;
    }
    else cout << "Koyomi" << endl;

    return (0);
}
