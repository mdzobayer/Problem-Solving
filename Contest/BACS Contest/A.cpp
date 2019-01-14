#include <cstdio>

long long int N[1010], n, test, t, i, goodDay, badDay;

int main() {

    scanf("%lld", &test);
    for (t = 0; t < test; ++t){
        scanf("%lld", &n);
        for (i = 0; i < n; ++i) {
            scanf("%lld", &N[i]);
        }
        goodDay = badDay = 0;
        for (i = 1; i < n - 1; ++i) {
            if (N[i - 1] <= N[i])
                goodDay += N[i - 1];
            if (N[n - (i + 1)] >= N[n - i])
                badDay += N[n - i];
        }
        if (badDay == 0) {
            printf("allGoodDays\n");
        }
        else if (goodDay == 0) {
            printf("allBadDays\n");
        }
        else if (goodDay == badDay) {
            printf("neutral\n");
        }
    }

    return (0);
}
