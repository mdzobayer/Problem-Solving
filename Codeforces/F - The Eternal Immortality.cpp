#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long int

int main() {

    ull a, b, re;
    cin >> a >> b;

    re = 1;
    ++a;
    while(b >= a) {
        re *= a;
        re %= 10;
        if (re == 0) break;
        ++a;
    }
    cout << re << endl;

    return (0);
}
