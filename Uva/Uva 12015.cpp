#include <cstdio>

struct website {
    char siteName[110];
    int rank;
};

int main() {
    int i, test, t, j, k;
    website temp, site[15];
    scanf("%d", &test);
    getchar();
    for (t = 1; t <= test; ++t) {
        for (i = 0; i < 10; ++i) {
            scanf("%s %d", &site[i].siteName, &site[i].rank);
            getchar();
        }
        for (j = 0; j < 9; ++j) {
            for (k = j + 1; k < 10; ++k) {
                if (site[j].rank < site[k].rank) {
                    temp = site[j];
                    site[j] = site[k];
                    site[k] = temp;
                }
            }
        }

        printf("Case #%d:\n", t);
        printf("%s\n",site[0].siteName);
        for (j = 1; j < 10; ++j) {
            if (site[0].rank == site[j].rank){
                printf("%s\n", site[j].siteName);
            }
            else {
                break;
            }
        }
    }

    return (0);
}
