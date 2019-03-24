#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a, b, s, tmp;
    cin >> n >> a >> b >> s;

    tmp = a + b;
    n -= 2;

    if((tmp + (n * a)) <= s && (tmp + (n * b)) >= s) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return (0);
}
