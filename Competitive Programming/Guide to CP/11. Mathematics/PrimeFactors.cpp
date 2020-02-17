#include <bits/stdc++.h>

using namespace std;

vector<int> Factors(int n) {
    vector<int> f;
    for (int x = 2; x * x <= n; ++x) {
        while(n % x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) {
        f.push_back(n);
    }

    return f;
}

int main() {

    vector < int > factors;

    factors = Factors(40);

    for (int x : factors) {
        cout << x << " ";
    }
    cout << endl;

    return (0);
}