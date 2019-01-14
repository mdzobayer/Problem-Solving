#include <bits/stdc++.h>


using namespace std;


int main(){

    int arr[110], n, d, i, j, ans = INT_MAX;

    cin >> n >> d;
    for (i = 0 ; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    for(i = 0; i < n; ++i) {
        for (j = i; j < n; ++j) {
            if (arr[j] - arr[i] <= d) {
                ans = min(ans, i + n - j - 1);
            }
        }
    }
    cout << ans << endl;

    return (0);
}
