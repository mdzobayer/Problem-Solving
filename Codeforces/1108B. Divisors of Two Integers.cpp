#include <bits/stdc++.h>

using namespace std;

int flag[10000+5];

int main() {

    //freopen("in.txt", "r", stdin);

    int n, i, x, j, xx, mx = 0;

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x;
        if(x > mx) mx = x;
        ++flag[x];
    }

    for (i = 1; i <= mx; ++i) {
        if(flag[i] == 2) {
            xx = i;
        }
        else if(flag[i] == 1) {
            if(mx % i != 0)
                xx = i;
        }
    }
    cout << xx << " " << mx << endl;


    return (0);
}
