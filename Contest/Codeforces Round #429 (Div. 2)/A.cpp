#include <cstdio>

int color[130] = {0};
char str[110];

int main() {

    bool flag = true;
    int n, k, i, m;
    scanf("%d %d", &n, &k);
    getchar();
    scanf("%s", &str);

    for (i = 0; str[i]; ++i) {
        color[str[i]] += 1;
    }

    for (i = 0; i < 127; ++i) {
        if (color[i] > k) {
            flag = false;
            break;
        }
    }
    if (flag) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return (0);
}
