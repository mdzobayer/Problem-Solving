#include <bits/stdc++.h>

using namespace std;

int arr[1000000+5];

int main() {

    int n, i, x;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    for (i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }

    return (0);
}