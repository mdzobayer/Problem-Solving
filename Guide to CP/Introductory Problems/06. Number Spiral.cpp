#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int 

int main() {

    int test;
    ull row, col, x, y, ans = 0;

    scanf("%d", &test);
    while(test--) {
        scanf("%llu %llu", &row, &col);

        x = max(row, col);

        y = (x - 1) * (x - 1);

        if ((x - 1) % 2 != 0) {
            if (row > col) {
                ans = y + (x * 2) - 1;
                ans -= (col - 1);
            }
            else {
                ans = y + row;
            }
        }
        else {
            if (row < col) {
                ans = y + (x * 2) - 1;
                ans -= (row - 1);
            }
            else {
                ans = y + col;
            }
        }

        printf("%lld\n", ans);

    }

    return (0);
}