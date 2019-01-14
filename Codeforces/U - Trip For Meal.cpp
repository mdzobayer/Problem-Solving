#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, a, b, c, mn, r, cost = 0;
    cin >> n >> a >> b >> c;
    --n;
    if (n == 0) {
        cout << "0" << endl;
        return (0);
    }
    mn = a;
    mn = min(mn, b);
    mn = min(mn, c);

    if (mn == a) {
        cost = a * n;
    }
    else if (mn == b) {
        cost = b * n;
    }
    else if (mn == c){
        cost = min (a, b);
        --n;
        cost += (c * n);
    }
    cout << cost << endl;
    return (0);
}
