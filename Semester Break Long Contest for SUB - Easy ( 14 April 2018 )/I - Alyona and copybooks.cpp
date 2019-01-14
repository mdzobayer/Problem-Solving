#include <bits/stdc++.h>

#define ll long long int
using namespace std;
int main () {

    ll n, a, b, c, k, need, tmp;

    cin >> n >> a >> b >> c;

    k = n % 4;
    //cout << "k = " << k << endl;
    if (k == 0) {
        cout << 0 << endl;
        return 0;
    }
    else if (k == 1) {
        need = min(3*a, min(c, a+b));
    }
    else if (k == 2) {
        need = min(2*a, min(b, c+c));
    }
    else need = min(a, min(3*c, b+c));
    cout << need << endl;

    return (0);
}
