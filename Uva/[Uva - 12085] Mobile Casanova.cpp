#include <cstdio>

int main() {
    //freopen("in.txt", "r", stdin);
    char s1[25], s2[25];
    int n, i, x, count, preNumber, j, cases = 0;;
    while(scanf("%d", &n) == 1 && n) {
        preNumber = -1;
        count = 1;
        printf("Case %d:\n", ++cases);
        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            if (preNumber + count != x) {
                if (preNumber > 0) {
                    /// Print the result;
                    printf("0%d", preNumber);
                    if(preNumber == preNumber + count - 1){
                        printf("\n");
                    }
                    else {
                        sprintf(s1, "%d", preNumber);
                        sprintf(s2, "%d", preNumber + count - 1);
                        j = 0;
                        while(s1[j] == s2[j]) ++j;
                        printf("-%s\n", s2 + j);
                    }
                }
                preNumber = x;
                count = 1;
            }
            else {
                ++count;
            }
        }
        /// Final Checking after ending loop
        if (preNumber > 0) {
            /// Print the result;
            printf("0%d", preNumber);
            if(preNumber == preNumber + count - 1){
                printf("\n");
            }
            else {
                sprintf(s1, "%d", preNumber);
                sprintf(s2, "%d", preNumber + count - 1);
                j = 0;
                /// Finding miss match elements
                while(s1[j] == s2[j]) ++j;

                printf("-%s\n", s2 + j);
            }
        }
        printf("\n");
    }

    return (0);
}
