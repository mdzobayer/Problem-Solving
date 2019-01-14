#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);


    int test, t, i, sz, j, n;
    char s[20];
    scanf("%d", &test);
    getchar();
    bool flag;
    for (t = 1; t <= test; ++t) {
        printf("Case %d: ", t);
        scanf("%s", &s);
        n = sz = strlen(s);
        --n;

        sz /= 2;
        flag = true;

        for (i = 0; i < sz; ++i) {
            if (s[i] != s[n-i]) {
                flag = false;
                printf("No\n");
                break;
            }
        }
        if (flag)
            printf("Yes\n");
    }


    return (0);
}


/// 152856
