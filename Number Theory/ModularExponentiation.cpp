#include <bits/stdc++.h>

using namespace std;

int binaryExponentiation(int x, int n) {

    
    int y, z;

    if (n == 0) return 1;
    cout << x << endl;
    
    if (n % 2 == 0) {
        y = binaryExponentiation(x * x, n / 2);
        //cout << "y = " << y << endl;
        return y;
    }
    else z = x * binaryExponentiation(x * x, (n-1)/2);
    //cout << "z = " << z << endl;
    return z;
}

int binaryExponentiationIterative(int x, int n) {
    int result = 1;

    while(n > 0) {
        if (n % 2 == 1) {
            result *= x;
        }

        x *= x;
        n /= 2;
    }
    return result;
}

int modularExpnentiation(int x, int n, int m) {
    if (n == 0) return 1;

    else if (n % 2 == 0) {
        return modularExpnentiation((x*x) % m, n/2, m);
    }
    else return (x * modularExpnentiation((x*x) % m, (n-1)/2, m) % m);
}
int modularExpnentiationIterative(int x, int n, int m) {
    int result = 1;

    while(n > 0) {
        if (n % 2 == 1) {
            result = (x*result) % m;
        }

        x = (x*x) % m;
        n /= 2;
    }
    return result;
}

int main() {

    cout << binaryExponentiation(3, 10) << endl;
    cout << binaryExponentiationIterative(3, 10) << endl;

    cout << modularExpnentiation(50, 50, 9) << endl;
    cout << modularExpnentiationIterative(50, 50, 9) << endl;

    return (0);
}