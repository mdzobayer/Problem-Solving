#include <cstdio>

int main () {

    int n, i, x, s;
    bool flag = true;
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        flag = true;
        for (s = 0; s < 13; ++s) {
            scanf("%d", &x);
            if(x < 1) flag = false;
        }
        printf("Set #%d: ", i);
        if (flag) printf("Yes\n");
        else printf("No\n");
    }

    return (0);
}
