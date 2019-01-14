#include <bits/stdc++.h>

using namespace std;

int main() {

    int arr[110], n, i, k, stolen = 0;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        if(arr[i] < k) {
            stolen += (k - arr[i]);
        }
    }
    cout << stolen << endl;

    return (0);
}
