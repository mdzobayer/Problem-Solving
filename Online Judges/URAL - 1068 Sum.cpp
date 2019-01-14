#include <bits/stdc++.h>

using namespace std;

int main () {

    long long int sum = 0, n, i = 1;
    cin >> n;
    if (i > n) {
        i = i + n;
        n = i - n;
        i = i - n;
    }
    for ( ; i <= n; ++i) {
        sum += i;
    }
    cout << sum << endl;

    return (0);
}
