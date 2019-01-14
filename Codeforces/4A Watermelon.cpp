#include <bits/stdc++.h>

using namespace std;

int main() {

    int w, i, x;
    cin >> w;
    for (i = 2; i < w; i += 2) {
        x = w - i;
        if (x % 2 == 0) {
            cout << "YES" << endl;
            return (0);
        }
    }
    cout << "NO" << endl;

    return (0);
}
