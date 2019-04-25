#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {

    ll n, x, y, res, step = 0;
    vector < ll > vt;

    cin >> x;

    if (x == 1) {
        cout << "0" << endl;
        return (0);
    }


    while(step <= 40) {

        n = ceil(log2(x));

        if ((pow(2, n) - 1 == x)) break;

        vt.push_back(n);
        res = (ll)pow(2, n);
        x ^= res - 1;
        ++step;

        n = ceil(log2(x));
        
        if ((pow(2, n) - 1 == x)) break;
        ++x;
        ++step;

    }


    cout << step << endl;
    for (int i = 0; i < vt.size(); ++i) {
        cout << vt[i] << " ";
    }
    cout << endl;

    return (0);
}