#include <bits/stdc++.h>

int main() {

    int x;
    float y, balance, charge = 0.50;

    while(scanf("%d %f", &x, &balance) == 2) {
        y = charge + x;
        if (x % 5 == 0 && y <= balance) {
            balance -= y;
        }
        printf("%0.2f\n", balance);
    }

    return (0);
}