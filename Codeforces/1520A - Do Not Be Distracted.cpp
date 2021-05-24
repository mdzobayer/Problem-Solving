#include <bits/stdc++.h>

using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);

    int test, t, n, i;
    char task[55];
    bool isPrevious[30], flag;

    scanf("%d", &test);

    for (t = 0; t < test; ++t) {
        scanf("%d", &n);
        scanf("%s", &task);

        memset(isPrevious, false, sizeof(isPrevious));
        isPrevious[task[0] - 'A'] = true;
        flag = true;

        for (i = 1; i < n; ++i) {
            if (task[i] != task[i - 1]) {
                if (isPrevious[task[i] - 'A']) {
                    flag = false;
                    break;
                }
                else {
                    isPrevious[task[i] - 'A'] = true;
                }
            }
        }

        if (flag) {
            puts("YES");
        }
        else {
            puts("NO");
        }
    }


    return (0);
}