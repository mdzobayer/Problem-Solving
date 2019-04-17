#include <bits/stdc++.h>

using namespace std;

int x[100000+5], pre[100000+5];
bool taken[100000+5];

int binarySearch(int key, int n) {
    int low, high, mid;

    low = 1, high = n; 
    while(low <= high) {
        mid = (low + high) / 2;
        if (pre[mid] > key) {
            high = mid - 1;
        }
        else if (pre[mid] < key) {
            low = mid + 1;
        }
        else return mid;
    }
    return 0;
}

int main() {

    freopen("in.txt", "r", stdin);

    int n, i, j, ans, togo, arch, arch2, arch3, thirdPoint;

    while(scanf("%d", &n) == 1) {

        memset(pre, 0, sizeof(pre));

        for (i = 1; i <= n; ++i) {
            scanf("%d", &x[i]);
            pre[i] = pre[i - 1] + x[i];
        }
        ans = 0;
        memset(taken, true, sizeof(taken));

        for (i = 1; i <= n; ++i) {
            if (taken[i]) {
                togo = ( n / 3 ) + i;
                for (j = i + 1; j <= togo && j <= n; ++j) {
                    if (taken[j]) {
                        arch = pre[j] - pre[i];
                        arch2 = pre[j] + arch;
                        if (arch2 > pre[n]) {
                            arch2 -= pre[n];
                        }
                        arch3 = pre[i] - arch;
                        if (arch3 < 0) {
                            arch3 += pre[n];
                        }

                        if (arch3 == arch2) {
                            thirdPoint = binarySearch(arch2, n);
                            if (thirdPoint > 0) {
                                taken[thirdPoint] = taken[j] = taken[i] = false;
                                ++ans;
                            }
                        }
                    }
                }
            }
        }

        printf("%d\n", ans);

    }

    return (0);
}