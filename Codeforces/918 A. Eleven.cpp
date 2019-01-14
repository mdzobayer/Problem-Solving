#include <bits/stdc++.h>

using namespace std;

int main() {
    int x1 = 1, x2 = 2, i, n;
    bool fibo[1000+10];
    memset(fibo, false, sizeof(fibo));
    fibo[0] = true;
    fibo[1] = true;
    while ( x2 < 1000+10) {
        //cout << x2 << endl;
        fibo[x2] = true;
        n = x1 + x2;
        x1 = x2;
        x2 = n;

    }
    scanf("%d", &n);
    for (i = 1; i <= n; ++i) {
        if (fibo[i]) {
            putchar('O');
        }
        else putchar('o');
    }
    putchar('\n');

    return (0);
}
