#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, a, b, mid, level;
    int res1, res2;
    cin >> n >> a >> b;


    mid = n / 2;

    if ((a <= mid && b > mid) || (a > mid && b <= mid)) {
        cout << "Final!" << endl;
    }
    else {
        if (a > b) {
            swap(a,b);
        }
        level = 1;

        while(a + 1 < b) {
            ++level;

            if (a % 2) {
                a /= 2;
                ++a;
            }
            else a /= 2;

            if (b % 2) {
                b /= 2;
                ++b;
            }
            else b /= 2;

        }
        cout << level << endl;
    }

    return(0);
}
