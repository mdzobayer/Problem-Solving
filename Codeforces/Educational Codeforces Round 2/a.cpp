#include <bits/stdc++.h>


using namespace std;

int main() {


    int q, l, r, d, x;

    cin >> q;
    while(q--) {
        cin >> l >> r >> d;

        if(d < l) {
            cout << d << endl;
            continue;
        }

        int ans = r / d;
        ++ans;
        cout << ans * d << endl;
    }

    return (0);
}
