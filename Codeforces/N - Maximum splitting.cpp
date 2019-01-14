#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main() {

    ll test, n, result;
    cin >> test;
    while(test--) {
        cin >> n;
        if (n <= 3 || n == 5 || n == 7 || n == 11) {
            result = -1;
        }
        else {
            result = n / 4;
            if (n % 2) {
                --result;
            }
        }
        cout << result << endl;
    }

    return (0);
}
