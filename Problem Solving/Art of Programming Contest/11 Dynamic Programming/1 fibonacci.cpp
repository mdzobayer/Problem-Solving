#include <cstdio>

#define MAX 20

int memo[MAX];

/// The slowest unnecessary computation is repeated
int Non_DP(int n) {
    if (n == 1 || n == 2)
        return 1;
    else
        return Non_DP(n - 1) + Non_DP(n - 2);
}
/// Top down DP
int DP_Top_Down(int n) {
    /// base case
    if (n == 1 || n == 2)
        return 1;

    /// immediately return the previously computed result
    if (memo[n] != 0)
        return memo[n];

    /// Otherwise do the same as no DP
    memo[n] = DP_Top_Down(n - 1) + DP_Top_Down(n - 2);

    return memo[n];
}
/// Fastest DP, bottom up, store the previous results in array
int DP_Bottom_Up(int n) {
    memo[1] = memo[2] = 1;

    /// from 3 to n
    for (int i = 3; i <= n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    return memo[n];
}

int main() {

    int z;

    /// this will be the slowest
    for (z = 1; z < MAX; z++) printf("%d-", Non_DP(z));
    printf("\n");

    /// This will be much faster than first
    for (z = 1; z < MAX; z++) printf("%d-", DP_Top_Down(z));
    printf("\n");

    /// This normally will be the faster
    for (z = 1; z < MAX; z++) printf("%d-", DP_Bottom_Up(z));
    printf("\n");

    return (0);
}
