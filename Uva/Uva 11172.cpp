#include <cstdio>

int main() {

    unsigned long long int a, b;
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%llu %llu", &a, &b);
        if (a == b)
            printf("=\n");
        else
            a < b ? printf("<\n") : printf(">\n");
    }


    return (0);
}
