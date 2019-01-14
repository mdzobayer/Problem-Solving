#include <bits/stdc++.h>

using namespace std;
#define LLI long long int
int main() {

    LLI n, i, k1, result = 0, k2, sumA, sumB, C[1000+10], A[1000+10], B[1000+10];
    scanf("%lld %lld %lld", &n, &k1, &k2);
    for (i = 0; i < n; ++i) {
        scanf("%lld", &A[i]);
    }
    for (i = 0; i < n; ++i) {
        scanf("%lld", &B[i]);
        C[i] = abs(A[i] - B[i]);
    }

    k1 += k2;
    sort(C, C+n);
    --n;
    while(k1--) {
        C[n]--;
        if (C[n] < 0) C[n] *= -1;
        sort(C, C + n + 1);
    }
    for (i = 0; i <= n; ++i) {
        result += C[i] * C[i];
    }
    printf("%lld\n", result);

    return (0);
}
