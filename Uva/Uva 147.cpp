#include <cstdio>
#include <cstring>

long long int arr[5] = {1, 5, 10, 25, 50}, dp[6][30010];

/// Forward Coin Change DP
int countCoin(int currentIndex, int endIndex, int amount, int make) {
    if (currentIndex >= endIndex + 1) {
        if (make == amount) return 1;
        return 0;
    }
    if (dp[currentIndex][amount] != -1) return dp[currentIndex][amount];

    int result1 = 0, result2 = 0;
    if (amount + arr[currentIndex] <= make) {
        result1 = countCoin (currentIndex, endIndex, amount + arr[currentIndex], make);
    }
    result2 = countCoin (currentIndex + 1, endIndex, amount, make);
    dp[currentIndex][amount] = result1 + result2;
    //printf("dp result %d\n", dp[currentIndex][amount]);

    return dp[currentIndex][amount];
}

/// Reverse Coin Change DP
long long int countCoin(long long int currentIndex, long long int amount) {
    if (currentIndex < 0) {
        if (amount == 0) return 1;
        return 0;
    }
    if (dp[currentIndex][amount] != -1) return dp[currentIndex][amount];

    long long int result1 = 0, result2 = 0;
    if (amount - arr[currentIndex] >= 0) {
        result1 = countCoin (currentIndex, amount - arr[currentIndex]);
    }
    result2 = countCoin (currentIndex - 1, amount);
    dp[currentIndex][amount] = result1 + result2;

    return dp[currentIndex][amount];
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("AC.txt", "w", stdout);
    long long int n, x;
    while(scanf("%lld", &n) == 1) {
        memset(dp, -1, sizeof(dp));
        //printf("There are %d ways to produce %d cents change.\n", countCoin(0, 4, 0, n), n);
        x = countCoin(4, n);
        if (x > 1)
        printf("There are %lld ways to produce %lld cents change.\n", x, n);
        else
        printf("There is only %lld way to produce %lld cents change.\n", x, n);
        /// Uva 674
        //printf("%d\n",countCoin(4, n));
    }

    return (0);
}
