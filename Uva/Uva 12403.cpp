#include <cstdio>
#include <cstring>
int main() {
    //freopen("input.txt", "r", stdin);
    long long int test, k, sum = 0;
    char str[10];
    scanf("%lld", &test);
    getchar();
    while(test--) {
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

    return (0);
}
