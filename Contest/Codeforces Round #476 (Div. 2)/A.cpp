#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int k, n, s, p, i, j, cnn = 0, need, possible;

    cin >> k >> n >> s >> p;
    need =  (n / s);
    if (n % s != 0) ++need;

    need *= k;

    if (need % p != 0) {
        need /= p;
        ++need;
    }
    else {
        need /= p;
    }
    cout << need << endl;

    return (0);
}
