#include <bits/stdc++.h>

using namespace std;

int main() {

    bool flag[110];
    int arr[110];
    memset(flag, false, sizeof(flag));

    int i, j = 0, n, k, x;
    cin >> n >> k;
    for (i = 1; i <= n; ++i) {
        cin >> x;
        arr[i] = x;
        if(!flag[x]) ++j;
        flag[x] = true;
    }
    if(j < k) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        for (i = 1, j = 0; i <= n && j < k; ++i) {
            if(flag[arr[i]]) {
                flag[arr[i]] = false;
                cout << i << " ";
                ++j;
            }
        }
        cout << endl;
    }

    return (0);
}
