#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, arr[610], Count = 0, x;
    memset(arr, 0, sizeof(arr));
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (arr[x] == 0 && x) {
            Count++;
            arr[x]++;
        }

    }
    cout << Count << endl;

    return (0);
}
