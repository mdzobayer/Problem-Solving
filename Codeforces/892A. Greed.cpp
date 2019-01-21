#include <bits/stdc++.h>


using namespace std;

int a[100000+5], b[100000+5];

int main() {

    int n, i;
    long long int tmp, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    for (i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    sort(b, b+n);
    tmp = b[n - 1] + b[n - 2];
    if(tmp < sum) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
    }


    return (0);
}
