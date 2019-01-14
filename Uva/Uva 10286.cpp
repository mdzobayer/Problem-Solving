#include <cstdio>
#define finalValue 1.0673956817111818692592637626711;

int main()
{

    double sideOfPentagoan, sideOfSquare;
    while(scanf("%lf", &sideOfPentagoan) != EOF) {

        sideOfSquare = sideOfPentagoan * finalValue;

        printf("%.10lf\n", sideOfSquare);
    }

    return (0);
}
