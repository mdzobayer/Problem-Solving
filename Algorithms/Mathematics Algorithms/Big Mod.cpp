#include <bits/stdc++.h>
using namespace std;

int bigMod(int a, int b, int m) {
    if (b == 0) return 1;

    int x = bigMod(a, b / 2, m);

    x = ((x % m) * (x % m)) % m;

    if (b % 2 == 1) {
        x = ((x % m) * (a % m)) % m;
    }
    return x;
}

int main() {

    int b, p, m;

    while(scanf("%d %d %d", &b, &p, &m) == 3) {
        printf("%d\n", bigMod(b, p, m));
    }

    return (0);
}
