#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);

    long long int test, k, sum = 0;
    int t, n;
    char str[10];
    scanf("%lld", &test);
    getchar();
    for(t = 1; t <= test; ++t) {
        scanf("%d", &n);
        getchar();
        printf("Case %d:\n", t);
        sum = 0;
        while(n--){
            scanf("%s", &str);
            if (strcmp("donate", str) == 0) {
                getchar();
                scanf("%lld", &k);
                getchar();
                sum += k;
            }
            else if (strcmp("report", str) == 0) {
                getchar();
                printf("%lld\n", sum);
            }
        }
    }

    return (0);
}
