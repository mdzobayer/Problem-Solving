#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, x, sum = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x < 0) {
            sum += (x * -1);
        }
        else sum += x;
    }
    cout << sum << endl;

    return (0);
}
