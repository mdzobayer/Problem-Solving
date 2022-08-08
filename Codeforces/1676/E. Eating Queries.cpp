#include <bits/stdc++.h>

#define fileRead freopen("in.txt", "r", stdin);

using namespace std;

int binarySearch(int arr[], int len, int target) {
    int low = 0, high = len - 1, mid, last_found = -1;

    while(low <= high) {
        mid = low + high;
        mid >>= 1;

        if (arr[mid] == target) {
            return mid;
            break;
        } else if (arr[mid] > target) {
            last_found = max(last_found, mid);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return last_found;
}

int main() {

    // fileRead

    int test, n, q, i, target, index, arr[150000 + 5], aggregateSum[150000 + 5];
    cin >> test;
    while(test--) {
        cin >> n >> q;

        for (i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sort(arr, arr+n);
        for (i = n - 1; i >= 0; --i) {
            if (i == n - 1) aggregateSum[i] = arr[i];
            else aggregateSum[i] = arr[i] + aggregateSum[i+1];
        }

        for (i = 0; i < q; ++i) {
            cin >> target;

            if (target > aggregateSum[0]) {
                cout << "-1" << endl;
                continue;
            }

            index = binarySearch(aggregateSum, n, target);
            cout << n - index << endl;

        }

        
    }

    return (0);
}