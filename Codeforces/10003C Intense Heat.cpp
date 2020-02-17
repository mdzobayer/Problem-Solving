#include <bits/stdc++.h>

using namespace std;
#define ll long long int 

ll arr[5000+5];
int main() {

    ll n, k, i, j;
    scanf("%lld %lld", &n, &k);
    arr[0] = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i-1];
    }
    double ans = 0.0, average;
    for (i = k; i <= n; ++i) {
        for (j = 0; j < n; ++j) {
            if (j + i > n) break;

            average = (double)(arr[j + i] - arr[j]) / i;
            //cout << average << " " << i << endl;

            ans = max(ans, average);
        }
    }
    printf("%0.15f\n", ans);

    return (0);
}