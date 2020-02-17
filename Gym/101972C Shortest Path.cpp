#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    int t, test;
    ll a, b, c, x;
    double travel, r, n, dis, x3, y3;
    scanf("%d", &test);
    for (t = 0; t < test; ++t) {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &x);
        travel = c;
        cout << travel << endl;
        travel += sqrt(((b+c)*(b+c)) + (a*a));
        cout << travel << endl;

        dis = sqrt((b*b) + (a*a));
        n = (dis * x) / 100.0;

        travel += n;

        r = n / dis;

        x3 = r * b;
        y3 = r * a;
        travel += sqrt(((b+c - x3)*(b+c - x3)) + ((a - y3)*(a - y3)));

        cout << travel << endl;

        travel += c;
        cout << travel << endl;
    }

    return (0);
}