#include <bits/stdc++.h>

using namespace std;

int main() {

    int i, n, m, a, b;
    double minValue = INT_MAX, rate, cost;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        rate = (double) a / b;
        cost = rate * m;
        //cout << cost << endl;
        if (cost < minValue) {
            minValue = cost;
        }
    }
    printf("%.10f\n", minValue);

    return (0);
}
