
#include <bits/stdc++.h>


using namespace std;

int main() {


    int a, l, r, y;

    cin >> l >> r >> a;

    int x = abs(r - l);

    if (x == 0) {
        y = r + l + (a / 2) * 2;

    }
    else {
        //int m = min(l,r);
        //a -= x;
        if (x > a)
            y = min(l, r) + a;
        else
            y = min(l, r) + x;
        y *= 2;
        a -= x;
        if (a > 0) {
            y += (a / 2) * 2;
        }

    }
    cout << y << endl;

    return (0);
}
