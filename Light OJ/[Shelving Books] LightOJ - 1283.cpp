#include <cstdio>
#include <climits>
#include <cstring>

int arr[110], dp[110][110][110], n, test, j, t;

int max (int a, int b, int c){
    int x = b > c ? b : c;
     a = a > x ? a : x;
    return a;
}


int countMax(int i, int leftIndex, int rightIndex) {

    if (i > n + 1) return (0);

    int maximum = 0;

    if (dp[i][leftIndex][rightIndex] != -1) return dp[i][leftIndex][rightIndex];

    if (arr[i] < arr[leftIndex]) {
        return dp[i][leftIndex][rightIndex] = countMax(i+1, leftIndex, rightIndex);
    }
    else if (arr[i] <= arr[rightIndex]){
        maximum = max(1 + countMax(i+1, i, rightIndex),
                      1 + countMax(i+1, leftIndex, i),
                          countMax(i+1, leftIndex, rightIndex)
                      );
        return dp[i][leftIndex][rightIndex] = maximum;
    }
    else {
        return dp[i][leftIndex][rightIndex] = countMax(i+1, leftIndex, rightIndex);
    }
}

int main() {

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        arr[0] = INT_MAX;
        arr[1] = INT_MIN;
        for (j = 2; j <= n + 1; ++j) {
            scanf("%d", &arr[j]);
        }
        printf("Case %d: %d\n", t, countMax(2, 1, 0));
    }

    return (0);
}
