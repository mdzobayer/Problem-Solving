#include <bits/stdc++.h>


using namespace std;

#define ll long long int

ll arr[200000+5], n, m;
ll sums[200000+5], x;

void solve() {
    ll low = 0, high = n - 1, mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if(sums[mid] > x) {
            high = mid - 1;
        }
        else if(sums[mid] < x) {
            low = mid + 1;
        }
        else {
            low = mid;
            break;
        }
    }
    //cout << "low = " << low << " " << endl;
    if(low == 0) {
        if(sums[low] >= x )
            cout << 1 << " " << x << endl;
        else {
            cout << 2 << " " << (sums[low + 1] - x) - sums[low] << endl;
        }
    }
    else if (low > 0) {
        //printf("%lld %lld\n", sums[low - 1], x);
        if(sums[low] >= x ) {
            //cout << "Debug 1" << endl;

            cout << low + 1 << " " << x - sums[low - 1] << endl;
        }
        else {
            cout << low << " " << (x - sums[low - 1]) << endl;
        }
    }
}

int main() {

    //freopen("in.txt", "r", stdin);

    ll i;
    cin >> n >> m;

    cin >> arr[0];
    sums[0] = arr[0];

    for (i = 1; i < n; ++i) {
        cin >> arr[i];
        sums[i] = arr[i] + sums[i - 1];
    }

    for (i = 0; i < m; ++i) {
        cin >> x;
        //cout << x << endl;
        solve();
    }


    return (0);
}
