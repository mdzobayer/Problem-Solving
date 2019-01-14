#include <cstdio>
#define lli long long int

lli arr[1000000+10];

int main() {
    bool flag = false;
    lli n, i;
    arr[0] = 0;
    scanf("%lld", &n);
    for (i = 1; i <= n; ++i) {
        scanf("%lld", &arr[i]);
        arr[i] += arr[i - 1];
    }

    for (i = n; i > 0; --i) {
        if (arr[n] % 2 != 0) {
            flag = true;
            break;
        }
        else if ((arr[i] % 2 != 0) && (arr[n] - arr[i]) % 2 != 0 ) {
            flag = true;
            break;
        }
        else {
            flag = false;
        }
    }
    if (flag) {
        printf("First\n");
    }
    else {
        printf("Second\n");
    }

    return (0);
}
