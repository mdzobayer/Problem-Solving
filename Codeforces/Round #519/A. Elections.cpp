#include <bits/stdc++.h>


using namespace std;

int main() {

    int i, n, arr[100+5], mx, sum = 0, j, tmp;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (i == 0)
            mx = arr[i];
        else mx = max(mx, arr[i]);
    }
    for (i = mx; i < 100000; ++i) {
        tmp = 0;
        for (j = 0; j < n; ++j) {
            tmp += (i - arr[j]);
        }
        if (tmp > sum) {
            printf("%d\n", i);
            return (0);
        }
    }



    return (0);
}
