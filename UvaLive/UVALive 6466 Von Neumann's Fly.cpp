#include <bits/stdc++.h>

using namespace std;

int main() {


    double d, f, a, b;
    int test, t;
    cin >> test;
    while(test--) {
        cin >> t >> d >> a >> b >> f;
        cout << t << " " << setprecision(2) << fixed << (d * f)/(a+b) << endl;
    }

    return (0);
}
