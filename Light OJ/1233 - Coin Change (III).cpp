#include <bits/stdc++.h>
#define SIZE 105

using namespace std;

int n, m, arr[SIZE], coin[SIZE], cnn;
bool found[100000+5];

void solve (int index, int sum) {
    //printf("sum is %d\n", sum);
    if(sum > m) return;

    //printf("Base sum is %d\n", sum);

    if(found[sum]) {
        ++cnn;
        found[sum] = false;
        //printf("\t%d is increased\n", sum);
    }
    // 2nd Base
    if(index >= n) return ;

    int i, res = sum;

    for (i = 0; i < coin[index]; ++i) {
        res += arr[index];
        if(res <= m) {
            solve(index + 1, res);
        }
        else break;
    }
    solve(index + 1, sum);
}

int main() {
    //freopen("in.txt", "r" ,stdin);

    int test, t, i, sum, tmpSum;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        for (i = 0; i < n; ++i) {
            scanf("%d", &coin[i]);
        }

        memset(found, true, sizeof(found));
        cnn = 0;

        solve(0, 0);
        printf("Case %d: %d\n", t, cnn-1);

    }

    return (0);
}
