#include <cstdio>

int main() {

    int n, k, butts;

    while(scanf("%d%d", &n, &k) == 2 && k > 1) {
        butts = n;
        while ( butts >= k) {
            n += (butts / k);
            butts = (butts / k) + (butts % k);
        }
        printf("%d\n", n);
    }

    return (0);
}
