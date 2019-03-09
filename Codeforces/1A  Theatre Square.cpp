#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int n, m, ans1, ans2, a;
    cin >> n >> m >> a;

    ans1 = n / a;
    if (n % a != 0) {
        ++ans1;
    }

    ans2 = m / a;
    if (m % a != 0) {
        ++ans2;
    }

    cout << ans1 * ans2 << endl;


    return (0);
}
