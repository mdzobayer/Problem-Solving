#include <bits/stdc++.h>

using namespace std;

int main() {

    double a, b, c, weight1 = 3.5, weight2 = 7.5, weight3 = 5.0;

    scanf("%lf %lf", &a, &b);

    // cerr << a << " " << b << " " << c << endl;

    // cerr <<  ((a*weight1)+( b*weight2) + (c*weight3)) << endl;

    printf("MEDIA = %0.5lf\n", ((a*weight1)+( b*weight2)) / (weight1 + weight2));

    return (0);
}