#include <cstdio>
#include <cmath>
int main() {
    double n, p, result;
    while(scanf("%lf%lf", &n, &p) == 2) {
        //printf("%lf %lf\n", n, p);
        printf("%0.00lf\n", pow(p, 1.0/n));
    }

    return (0);
}
