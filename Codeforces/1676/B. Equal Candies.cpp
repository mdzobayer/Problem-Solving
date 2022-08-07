#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileRead freopen("in.txt", "r", stdin);

using namespace std;

int main() {

    fastIO

    // freopen("in.txt", "r", stdin);

    int test, n, i, arr[55], minNumber, haveToEat;

    cin >> test;
    while(test--) {
        cin >> n;

        for (i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        minNumber = arr[0];
        for (i = 1; i < n; ++i) {
            if (minNumber > arr[i]) minNumber = arr[i];
        }

        haveToEat = 0;
        for (i = 0; i < n; ++i) {
            haveToEat += arr[i] - minNumber;
        }

        cout << haveToEat << endl;
    }

    return (0);
}