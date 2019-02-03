#include <bits/stdc++.h>

using namespace std;

long long int arr[300000+5], n, i, j, sum, tmp;

int main() {

    sum = 0;
    scanf("%I64d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%I64d", &arr[i]);
    }
    sort(arr, arr+n);

    for (i = 0, j = n-1; i < j; ++i, --j) {
        tmp = arr[i]+arr[j];
        sum += (tmp * tmp);
    }
    cout << sum << endl;

    return (0);
}
