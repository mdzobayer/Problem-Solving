#include <cstdio>
#include <cstring>
#define lli long long int

int stockPrice[1000000 + 10];
int stockCount[10000 + 10];


int main() {

    //freopen("in.txt", "r", stdin);

    lli n, i, test, maxValue, maxProfit;
    scanf("%lld", &test);
    while(test--) {

        memset(stockCount, 0, sizeof(stockCount));

        maxValue = 0;
        maxProfit = 0;
        scanf("%lld", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &stockPrice[i]);
            if (stockPrice[i] > maxValue) maxValue = stockPrice[i];
            stockCount[stockPrice[i]] += 1;
        }
        /// Check stockCount
//        for (i = 1; i <= maxValue; ++i) {
//            printf("%d ", stockCount[i]);
//        }
//        printf("\n");

        for (i = 0; i < n; ++i) {
            if (stockPrice[i] < maxValue && stockCount[maxValue] > 0) {
                stockCount[stockPrice[i]] -= 1;
                maxProfit += (maxValue - stockPrice[i]);
            }
            else {
                stockCount[maxValue] -= 1;
            }
            while(stockCount[maxValue] <= 0 && maxValue >= 0) {
                --maxValue;
            }
        }
        printf("%lld\n", maxProfit);


    }


    return (0);
}
