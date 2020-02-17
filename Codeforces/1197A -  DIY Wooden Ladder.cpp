#include <bits/stdc++.h>

using namespace std;

int arr[100000+5];

int main() {

    //freopen("in.txt", "r", stdin);

    int test, i, n, x;
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &n);

        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            //++arr[x];
        }
        sort(arr, arr+n);

        // if (arr[n-1] <= 1 || arr[n - 2] <= 1) {
        //     cout << "0" << endl;
        //     return (0);
        // }

        int mx = min(arr[n-1], arr[n-2]) - 1;

        cout << min(mx, n - 2) << endl;
    }

    return (0);
}