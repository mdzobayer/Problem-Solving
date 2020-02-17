#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("in.txt", "r", stdin);

    unsigned long long int a, b, c;
    int q;

    cin >> q;
    while(q--) {
        cin >> a >> b >> c;
        c = c + a + b;
        
        cout << (c / 2) << endl;
    }


    return (0);
}