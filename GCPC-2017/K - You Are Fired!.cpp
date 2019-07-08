#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector < pair < ll, ll > > values;
string names[10000 + 10];

int main() {

    freopen("in.txt", "r", stdin);

    ll n, d, k, i, x, j, y;

    cin >> n >> d >> k;
    for (i = 0; i < n; ++i) {
        cin.ignore();
        cin >> names[i] >> x;
        values.push_back(make_pair(x, i));
    }

    stable_sort(values.begin(), values.end(), greater< pair < ll, ll>> ());

    x = 0;
    for (j = 0; j < k && x < d; ++j) {
        x += values[j].first;
    }

    if (x < d) {
        cout << "impossible" << endl;
    }
    else {
        cout << j << endl;
        y = 0;
        for (j = 0; j < k; ++j) {
            x = values[j].second;
            cout << names[x] << ", YOU ARE FIRED!" << endl;
            y += values[j].first;
            //cout << "y = " << y << endl;
            if (y >= d) break;
        }
    }

    return (0);
}