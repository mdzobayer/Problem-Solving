
#include <bits/stdc++.h>
#define ull unsigned long long int
#define ll long long int

using namespace std;

int main() {

    int test;
    ll nn;
    ll n, x = 1;
    cin >> test;
    while(test--) {
        cin >> nn;
        x = 1;
        n = nn;
        nn = ((nn*nn) + nn) / 2;
        while(x <= n) {
            nn -= (x *= 2);
        }
        cout << nn << endl;
    }

    return (0);
}
