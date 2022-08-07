#include <bits/stdc++.h>

using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);

    int test, key1, key2, key3, i, arr[5], doorStatus[5];
    cin >> test;
    while(test--) {
        cin >> key1;

        for (i = 1; i < 4; ++i) {
            cin >> arr[i];
        }

        memset(doorStatus, false, sizeof(doorStatus));

        key2 = arr[key1];
        if (key2 > 3 || key2 < 1) {
            cout << "NO" << endl;
            continue;
        }

        key3 = arr[key2];
        if (key3 > 3 || key3 < 1) {
            cout << "NO" << endl;
            continue;
        }

        doorStatus[key1] = doorStatus[key2] = doorStatus[key3] = true;

        if (doorStatus[1] && doorStatus[2] && doorStatus[3]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return (0);
}