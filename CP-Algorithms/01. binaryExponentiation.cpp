#include <bits/stdc++.h>
#define LLD long long int

using namespace std;

LLD binPowRecursive(LLD a, LLD n) {
    LLD x;
    if (n == 0)
        return 1;

    else if (n % 2 == 0) {
        x = binPowRecursive(a, n/2);
        return  x * x;
    }
    else {
        x = binPowRecursive(a, (n-1)/2);
        return x * x * a;
    }
}

LLD binPowLoop(LLD a, LLD n) {
    LLD result = 1;

    while (n > 0) {
//        cout << "n = " << n << endl;
//        cout << "a = " << a << endl;
        if (n % 2 == 1) {
            result = result * a;
        }
        a = a * a;
        n >>= 1;
//        cout << "result = " << result << endl << endl;

    }

    return result;
}

LLD binPowLoopModule(LLD a, LLD n, LLD m) {
    LLD result = 1;
    a = a % m;
    while(n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % m;
        }

        a = (a * a) % m;
        n >>= 1;
    }

    return result;
}


int main() {

    cout << binPowRecursive(3, 7) << endl;
    cout << binPowLoopModule(3, 7, 10) << endl;

    return (0);
}
