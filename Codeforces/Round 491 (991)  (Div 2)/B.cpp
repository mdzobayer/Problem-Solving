#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, arr[110], i, mn = 0, have = 0, need;

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
        have += arr[i];
    }
    need = ceil((double)(4.5 * n));
    //cout << need << endl;
    i = 0;
    sort(arr, arr+n);
    while(have < need && i < n) {
        ++mn;
        have += (5 - arr[i]);
        ++i;
    }
    cout << mn << endl;

    return (0);
}
