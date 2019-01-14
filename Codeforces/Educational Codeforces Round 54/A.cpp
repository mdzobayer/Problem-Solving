#include <bits/stdc++.h>
using namespace std;

int main() {

    int i, n, in = 0;

    cin >> n;
    cin.ignore();
    string s;
    cin >> s;
    in = n - 1;
    for (i = 0; i < n - 1; ++i) {
        if(s[i] > s[i + 1]) {
            in = i;
            break;
        }
    }


    for (i = 0; i < n; ++i) {
        if(i != in)
            putchar(s[i]);
    }
    cout << endl;

    return (0);
}
