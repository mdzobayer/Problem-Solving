#include <cstdio>
#include <cmath>

int main() {

    long long int a, b;
    while(scanf("%lld", &a) == 1) {
        if (a == 0)
            break;
        b = sqrt(a);
        b *= b;
        if (b == a)
            printf("yes\n");
        else
            printf("no\n");
    }

    return (0);
}
