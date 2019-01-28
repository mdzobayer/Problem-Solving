#include <bits/stdc++.h>


using namespace std;

#define ll long long int

ll arr[200000+5], n, m;
ll sums[200000+5], x;

void solve() {
    ll low = 0, high = n - 1, mid;

    while(low < high) {
        mid = (low + high) / 2;

        if(sums[mid] > x) {
            high = mid - 1;
        }
        else if(sums[mid] < x) {
            low = mid;
        }
        else {
            low = mid;
            break;
        }
    }
    cout << "low = " << low << " " << endl;
    if(low == 0 && x <= sums[0]) {
        cout << low + 1 << " " << x << endl;
    }
    else if (x >= sums[low]) {
        ++low;
        cout << low + 1 << " " << (sums[low] - x) - x << endl;
    }
}

int main() {

    freopen("in.txt", "r", stdin);

    ll i;
    scanf("%lld %lld", &n, &m);

    scanf("%lld", &arr[0]);
    sums[0] = arr[0];

    for (i = 1; i < n; ++i) {
        scanf("%lld", &arr[i]);
        sums[i] = arr[i] + arr[i - 1];
    }

    for (i = 0; i < m; ++i) {
        scanf("%lld", &x);
        cout << x << endl;
        solve();
    }


    return (0);
}
