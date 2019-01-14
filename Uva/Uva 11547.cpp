#include <cstdio>
#include <cstdlib>
int main () {

    int t , n;

    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d", &n);
        n *= 567;
        n /= 9;
        n += 7492;
        n *= 235;
        n /= 47;
        n -= 498;
        //printf("%d\n", n);

        n /= 10;
        n %= 10;
        printf("%d\n", abs(n));
    }

    return (0);
}
