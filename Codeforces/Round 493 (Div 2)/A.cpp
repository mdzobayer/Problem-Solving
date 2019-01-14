#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, arr[1000+5], i, sum = 0;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << "-1" << endl;
    }
    else if (n == 2) {
        if (arr[0] == arr[1]) {
            cout << "-1" << endl;
        }
        else {
            cout << 1 << endl;
            cout << 1 << endl;
        }
    }
    else {
        sort(arr, arr+n);
        sum = 0;
        for (i = 1; i < n; ++i) {
            sum += arr[i];
        }
        if (arr[0] == sum) {
            cout << n - 2 << endl;
            for (i = 2; i < n; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << n - 1 << endl;
            for (i = 1; i < n; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    return (0);
}
