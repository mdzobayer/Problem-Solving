#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, len, result = 1;
    string k;

    while(cin >> n >> k) {
        len = k.size();
        result = 1;
        while(n > 1) {
            result *= n;
            n -= len;
        }
        cout << result << endl;
    }

    return (0);
}
