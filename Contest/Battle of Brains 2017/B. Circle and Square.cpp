
#include <cstdio>
#include <cmath>

using namespace std;


int main() {

    double sqrt2, total, r;
    int test, i;
    sqrt2 = sqrt(2);
    scanf("%d", &test);
    while(test--) {
        scanf("%lf", &r);
        total = r;
        for (i = 0; i < 10000; ++i) {
            r /= sqrt2;
            total += r;
            if (r < 0) break;
        }
        printf("%0.1lf\n", total);
    }

    return (0);
}
