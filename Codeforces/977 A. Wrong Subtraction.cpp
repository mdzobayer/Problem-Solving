#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int n, k, rem;
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        rem = n % 10;
        if(rem == 0) {
            n /= 10;
        }
        else {
            --n;
        }
    }
    cout << n << endl;

    return (0);
}
