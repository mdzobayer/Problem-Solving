#include <bits/stdc++.h>
#define ll long long int

using namespace std;


ll arr[1000+5];

map < ll, int > mp;

int main () {

    ll i, n, mx = 1, x, y;

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
        mp[arr[i]] += 1;
    }

    for (auto it = mp.begin(); it != mp.end(); ++it) {
        x = it->first;
        //cout << x << endl;
        if (x & 1) {
            y = 1;
        }
        else y = -1;

        for (i = 0; i < n; ++i) {
            if (arr[i] == x) {
                arr[i] += y;
                mp[arr[i]] += 1;
            }
        }
    }

    for (i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return (0);
}