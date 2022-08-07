#include <bits/stdc++.h>

using namespace std;

int main() {    

    int w;
    cin >> w;
    if (w > 3 && !(w & 1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return (0);
}