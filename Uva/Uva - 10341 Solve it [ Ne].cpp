#include <stdio.h>
#include <math.h>

#define EPS 1e-7

int p,q,r,s,t,u;

double f(double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bisection() {
    double lo = 0, hi = 1;
    while(lo + EPS < hi) {
        double x = (lo + hi) / 2;
        if (f(lo) * f(x) <= 0) {
            hi = x;
        }
        else {
            lo = x;
        }
    }
    return (lo + hi) / 2;
}

int main() {

    freopen("in.txt", "r", stdin);

    while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
        if (f(0) * f(1) > 0) {
            puts("No solution");
        }
        else {
            float res = bisection();
            printf("%.4f\n", res);
        }
    }

    return (0);
}
