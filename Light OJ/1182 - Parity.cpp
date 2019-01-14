#include <bits/stdc++.h>


using namespace std;


int main() {

    int test, t, n, bits, parity, x;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        parity = 0;
        while(n > 0) {
            bits = n % 2;
            parity += bits;
            n >>= 1;
        }
        printf("Case %d: ", t);
        if (parity % 2) printf("odd\n");
        else printf("even\n");
    }

    return (0);
}
