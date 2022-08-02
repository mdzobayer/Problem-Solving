#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, i, s;
    cin >> test;
    while(test--) {
        cin >> s;

        vector<int> vt;

        int num = 9;

        while(num > 0) {
            if (s >= num) {
                vt.push_back(num);
                s -= num;
            }

            --num;
        }

        if (s > 0) {
            vt.push_back(s);
        }
        for (i = vt.size() - 1; i >= 0; --i) {
            cout << vt[i];
        }
        cout << endl;
    }

    return (0);
}