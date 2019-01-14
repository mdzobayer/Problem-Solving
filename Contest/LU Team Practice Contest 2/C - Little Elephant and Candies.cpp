#include <bits/stdc++.h>
#define LLI long long int
using namespace std;


int main() {

    LLI arr[110], test, t, n, c, i;
    bool flag;
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld %lld", &n, &c);
        for (i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
        }
        flag = true;
        for (i = 0; i < n; ++i) {
            c -= arr[i];
            if (c < 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("Yes\n");
        }
        else printf("No\n");
    }

    return (0);
}
