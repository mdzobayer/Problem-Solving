#include <cstdio>

int main() {
    //freopen("input.txt", "r", stdin);
    int test, bWin, wWin, i, match, j, ab, tie;
    char res;
    scanf("%d", &test);
    for (i = 1; i <= test; ++i) {
        ab = bWin = tie = wWin = 0;
        scanf("%d", &match);
        getchar();
        for (j = 0; j < match; ++j) {
            scanf("%c", &res);
            switch(res) {
            case 'B':
                ++bWin;
                break;
            case 'W':
                ++wWin;
                break;
            case 'A':
                ++ab;
                break;
            case 'T':
                ++tie;
            }
        }
        getchar();
        printf("Case %d: ", i);

        if (ab == match) {
            printf("ABANDONED");
        }
        else if (bWin == wWin) {
            printf("DRAW %d %d", bWin, tie);
        }
        else if (bWin + ab == match) {
            printf("BANGLAWASH");
        }
        else if (wWin + ab == match) {
             printf("WHITEWASH");
        }
        else {
            if (bWin > wWin) {
                printf("BANGLADESH %d - %d", bWin, wWin);
            }
            else
                printf("WWW %d - %d", wWin, bWin);
        }
        putchar('\n');
    }

    return (0);
}
