#include <bits/stdc++.h>

using namespace std;

int main() {

    int a, b, dis, are, res, r1, r2;

    cin >> a >> b;

    if (a > b) {
        swap(a,b);
    }

    dis = b - a;
    res = dis / 2;
    if (dis % 2 == 0 ) {
        r1 = ((res * res) + res) / 2;
        //cout << "here" <<endl;
        cout << r1 + r1 << endl;
    }
    else {
        r1 = ((res * res) + res) / 2;
        ++res;
        r2 = ((res * res) + res) / 2;
        cout << r1 + r2 << endl;
    }


    return (0);
}
