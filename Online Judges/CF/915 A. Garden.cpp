
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, i, a[110], ans = INT_MAX , temp ;
    bool chk = false;
    cin >> n >> k;
    for (i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == k) chk = true;
        else {
            temp = k / a[i];
            if (temp * a[i] == k) {
                ans = min(ans, temp);
            }
        }
    }
    if (chk) {
        cout << "1" << endl;
    }
    else {
        //sort(a, a+n);
        cout << ans << endl;
    }

    return (0);
}
