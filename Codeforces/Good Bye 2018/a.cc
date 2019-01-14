#include <bits/stdc++.h>


using namespace std;

int main() {

    int y, b, r, mn;
    cin >> y >> b >> r;
    mn = min(min(y,b), r);

    if(mn == y ) {
        if((y+1) <= b && (y+2) <= r) {
            cout << y + (y+1) + (y+2) << endl;
            return (0);
        }
        --y;
        if((y+1) <= b && (y+2) <= r) {
            cout << y + (y+1) + (y+2) << endl;
            return (0);
        }
        --y;
            cout << y + (y+1) + (y+2) << endl;
            return (0);
    }
    else if(mn == b) {
        if((b+1) <= r) {
            cout << (b-1) + b + (b+1) << endl;
            return (0);
        }
        --b;
            cout << (b-1) + b + (b+1) << endl;
    }
    else {
        cout << (r-2) + (r-1) + r << endl;
    }


    return (0);
}
