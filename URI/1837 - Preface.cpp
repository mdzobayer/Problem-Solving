#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, q, r;

    cin >> a >> b;

    if(a < 0 && b > 0) {
        q = 0;
        r = a;

        while(r < 0) {
            q = q - 1;
            r = r + b;
        }

        cout << q << " " << r << endl;
    }
    else if (a < 0 && b < 0) {
        q = 1;
        r = a;

        while(r < b) {
            q = q + 1;
            r = r - b;
        }

        cout << q << " " << (r-b) << endl;
    }
    else {
        cout << (a/b) << " " << (a%b) << endl;
    }
    
    return (0);
}