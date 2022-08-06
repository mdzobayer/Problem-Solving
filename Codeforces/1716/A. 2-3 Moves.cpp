#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, n, result;

    cin >> test;
    while(test--) {
        cin >> n;

        if (n % 3 == 0) {
            cout << n / 3 << endl;
        } else if (n % 3 == 2) {
            cout << (n / 3) + 1 <<  endl;
        } else {
            cout << ((n / 3) - (n > 1 ? 1 : 0)) + 2 << endl; 
        }
    }

    return (0);
}