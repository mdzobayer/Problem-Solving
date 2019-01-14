#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, test, t, square, x;
    cin >> test;
    for (t = 0; t < test; ++t) {
        cin >> n;
        square = sqrt(n);
        if (pow(square, 2) == n) {
            cout << "0" << endl;
            continue;
        }
        for (square; square >= 1; --square) {
            if (n % square == 0) {
                x = n / square;
                cout << abs(x - square) << endl;
                break;
            }
        }
    }

    return (0);
}
