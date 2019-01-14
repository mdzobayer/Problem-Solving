#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, res, r1, st = 0, x;
    cin >> n;

    for (x = 1; x <= 10000; ++x) {
        ++st;
        r1 = n * x;
        res = sqrt(r1);
        if(res * res == r1) {
            cout << res << " " << st << endl;
            break;
        }
        n = res;
    }


    return (0);
}
