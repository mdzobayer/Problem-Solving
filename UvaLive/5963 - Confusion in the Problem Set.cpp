#include <bits/stdc++.h>

using namespace std;

int arr[10000+5], n;

int main() {

    //freopen("in.txt", "r", stdin);

    bool flag;
    int test, t, i;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        sort(arr, arr+n);
        flag = true;
        for (i = 0; i < n; ++i) {
            if (arr[i] != i)
                flag = false;
        }
        //if (arr[0] != 0 || arr[n - 1] != n - 1) flag = false;

        if (flag) {
            printf("Case %d: yes\n", t);
        }
        else {
            printf("Case %d: no\n", t);
        }
    }



    return (0);
}