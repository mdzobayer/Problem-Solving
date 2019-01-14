#include <bits/stdc++.h>

using namespace std;


int main() {

    int p, y;
    bool flag = false;
    cin >> p >> y;
    for (int i = y; i > p; --i) {
        flag = false;
        for (int j = 2; j <= p && j * j <= i; ++j) {
            if (i % j == 0) {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        cout << i << endl;
        return (0);
    }
    cout << "-1" << endl;
    return (0);
}
