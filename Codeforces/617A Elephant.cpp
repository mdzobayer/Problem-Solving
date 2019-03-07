#include <bits/stdc++.h>

using namespace std;

int main() {

    float a, b, c;
    int test;
    cin >> test;
    while(test--) {
        cin >> a >> b >> c;
        if((a + b + c) == 180.0) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

    return (0);
}
