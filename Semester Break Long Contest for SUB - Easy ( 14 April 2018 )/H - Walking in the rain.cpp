#include <bits/stdc++.h>

using namespace std;

int main() {

    int arr[1010], n, i, result = INT_MAX, minimum = INT_MAX, maximum = INT_MIN;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    minimum = min(arr[0], arr[n-1]);
    for (i = 1; i < n - 1; ++i) {
        maximum = max(arr[i], arr[i+1]);
        result = min(result, maximum);
    }
    cout << min(result, minimum) << endl;

    return (0);
}
