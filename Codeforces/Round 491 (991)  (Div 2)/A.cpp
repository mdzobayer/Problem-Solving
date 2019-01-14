#include <bits/stdc++.h>


using namespace std;

int main() {

    int a, b, c, n, uni = 0;
    cin >> a >> b >> c >> n;

    uni = a + b;
    if (c <= a && c <= b) {
        uni -= c;
    }
    else {
        cout << -1 << endl;
        return (0);
    }

    if (uni >= n) {
        cout << "-1" << endl;
    }
    else {
        a = n - uni;
        cout << a << endl;
    }

    return (0);
}
