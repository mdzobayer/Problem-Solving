#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int test, a, b;
    cin >> test;
    while(test--) {
        cin >> a >> b;
        cout << max(a,b) << " " << a+b << endl;
    }

    return (0);
}
