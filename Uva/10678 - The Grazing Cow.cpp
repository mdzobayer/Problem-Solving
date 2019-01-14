/**

Area of Ellipse and prithagoras triangle law


**/

#include <bits/stdc++.h>

using namespace std;
#define PI 2*acos(0)

int main() {

    int test;
    double a, b, D, L;
    scanf("%d", &test);
    while(test--) {
        scanf("%lf %lf", &D, &L);

        /// a is minor
        a = sqrt(((L/2)*(L/2))-((D/2)*(D/2)));
        /// b is major
        b = L / 2.0;
        printf("%0.3f\n", (b*PI*a));
    }

    return (0);
}
