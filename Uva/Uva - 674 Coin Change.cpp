#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

int arr[5] = {1, 5, 10, 25, 50};
/// Reverse Coin Change DP
//int dp[5][30010];
//int countCoin(int currentIndex, int amount) {
//    if (currentIndex < 0) {
//        if (amount == 0) return 1;
//        return 0;
//    }
//    if (dp[currentIndex][amount] != -1) return dp[currentIndex][amount];
//
//    int result1 = 0, result2 = 0;
//    if (amount - arr[currentIndex] >= 0) {
//        result1 = countCoin (currentIndex, amount - arr[currentIndex]);
//    }
//    result2 = countCoin (currentIndex - 1, amount);
//    dp[currentIndex][amount] = result1 + result2;
//
//    return dp[currentIndex][amount];
//}

/// Iterative Way
int CountCoin(int cI, int am) {

    int a, b, i, j, dp[am + 5][cI + 5];
    for (i = 0; i <= cI + 1; ++i) {
        dp[0][i] = 1;
    }
    for (i = 1; i <= am + 1; ++i) {
        for (j = 0; j <= cI; ++j) {
            if (i - arr[j] >= 0)
                a = dp[i - arr[j]][j];
            else a = 0;

            if (j >= 1)
                b = dp[i][j - 1];
            else b = 0;

            dp[i][j] = a + b;
        }
    }
    return dp[am][cI];
}


int main() {
    FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    int n;
    while(scanf("%d", &n) == 1) {
        //memset(dp, -1, sizeof(dp));
        /// Iterative function call
        printf("%d\n",CountCoin(4, n));

    }

    return (0);
}
