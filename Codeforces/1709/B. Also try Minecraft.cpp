#include <bits/stdc++.h>
#define ll long long int

using namespace std;

#define SIZE 100000 + 5
ll ascendingOrder[SIZE], descendingOrder[SIZE];
int arr[SIZE];

int main() {

    int n, m, i, x, y, ans1, ans2;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    ascendingOrder[0] = 0;
    descendingOrder[n] = 0;

    for (i = 1; i < n; ++i) {
        if (arr[i+1] < arr[i]) {
            ascendingOrder[i + 1] = (ascendingOrder[i] + (arr[i] - arr[i+1]));
        } else {
             ascendingOrder[i + 1] = ascendingOrder[i];
        }

        if(arr[n - i] < arr[(n + 1) - i]) {
            descendingOrder[n - i] = (descendingOrder[(n + 1) - i] + (arr[(n + 1) - i] - arr[n - i]));
        } else {
            descendingOrder[n - i] = descendingOrder[((n + 1)) - i];
        }
    }

    for (i = 0; i < m; ++i) {
        scanf("%d %d", &x, &y);
        (x < y) ? printf("%lld\n", ascendingOrder[y] - ascendingOrder[x]) : printf("%lld\n", descendingOrder[y] - descendingOrder[x]);
    }

    return (0);
}