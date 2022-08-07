#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {
    int n, i, x, j, decreasingCount = 0, arr[100000+5];
 
    bool isNonDecreasing = true;
 
    cin >> n;
    for (i = 0, j = 0; i < n; ++i) {
        cin >> x;
        if (j > 0) {
            if (arr[j-1] != x) {
                arr[j] = x;
                ++j;
            }

        } else {
            arr[j] = x;
            ++j;
        }
    }

    n = j;
 
    for (i = 1; i < n - 1; ++i) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            isNonDecreasing = false;
        }  
    }
 
    if (isNonDecreasing) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
 
int main() {
 
    // freopen("in.txt", "r", stdin);
 
    int test;
    cin >> test;
    while(test--) {
        solve();
    }
 
    return (0);
}