#include <cstdio>

int pro[2][14], req[14];

int main() {
    long long int sum;
    int before, t = 0, i;
    while(scanf("%d", &before) == 1){
        if (before < 0)
            break;
        for(i = 0; i < 12; ++i) {
            scanf("%d", &pro[0][i]);
        }
        for(i = 0; i < 12; ++i) {
            scanf("%d", &pro[1][i]);
        }
        sum = before;
        printf("Case %d:\n", ++t);
        for (i = 0; i < 12; ++i) {
            if (sum < pro[1][i]) {
                printf("No problem. :(\n");
            }
            else {
                printf("No problem! :D\n");
                sum -= pro[1][i];
            }
            sum += pro[0][i];
        }
    }

    return (0);
}
/**
5
3 0 3 5 8 2 1 0 3 5 6 9
0 0 10 2 6 4 1 0 1 1 2 2
-1
**/
