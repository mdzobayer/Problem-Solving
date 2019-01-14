#include <bits/stdc++.h>
#define ll long long int

using namespace std;
ll arr[200000+5];
ll n,m, x;

ll binarySearch() {
    ll low = 0, high = n - 1, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] > x) {
            high = mid - 1;
        }
        else if (arr[mid] < x)
            low = mid + 1;
        else {
            if(mid != n-1 && arr[mid] == arr[mid+1]) {
                low = mid + 1;
            }
            else return mid + 1;
        }
    }

    if (arr[mid] > x) return mid;
    else if(arr[mid] < x) return mid + 1;

    return mid;
}

int main() {

    ll i;
    scanf("%I64d %I64d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &arr[i]);
    }
    sort(arr, arr+n);
    for (i = 0; i < m; ++i) {
        scanf("%I64d", &x);
        printf("%I64d ", binarySearch());
    }
    puts("");

    return (0);
}
