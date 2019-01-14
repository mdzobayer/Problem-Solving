#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, t, n, tempN, maximum;
    cin >> test;
    while(test--) {
        cin >> t >> n;
        maximum = n;
        label:
        if (maximum < n) maximum = n;

        if (n == 1) {
            cout << t << " " << maximum << endl;
        }
        else if (n % 2) {
            n *= 3;
            n += 1;
            goto label;
        }else {
            n /= 2;
            goto label;
        }
    }

    return (0);
}
