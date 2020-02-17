#include <bits/stdc++.h>

using namespace std;

bool prime(int n) {
    if (n < 2) return false;
    for (int x = 2; x * x <= n; ++x) {
        if (n % x == 0) {
            return false;
        }
    }
    return true;
}

int main() {

    cout << prime(19) << endl;
    cout << prime(21) << endl;

    return (0);
}