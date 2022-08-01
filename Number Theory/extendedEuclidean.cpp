#include <bits/stdc++.h>

using namespace std;

int d, x, y;

void extendedEuclid(int A, int B) {
    if (B == 0) {
        d = A;
        y = 0;
        x = 1;
    }
    else {
        extendedEuclid(B, A % B);
        int tmp = x;
        x = y;
        y = tmp - (A / B) * y;
    }
}

int main() {

    extendedEuclid(16, 10);
    cout << "The GCD of 16 and 10 is " << d << endl;
    cout << "Coefficients of x and y are " << x << " " << y << endl;


    return (0);
}