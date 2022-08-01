#include <bits/stdc++.h>

using namespace std;

long long int arr[200000+5];
unsigned long long int ans;

int main() {

    int n, i;
    ans = 0;
    scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%lld", &arr[i]);
    }

    for (i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            ans += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    printf("%llu\n", ans);

    return (0);
}