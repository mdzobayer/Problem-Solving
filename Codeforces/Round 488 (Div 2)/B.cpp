
#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int n, k, i, x, u, arr[100000+5];
ll arr2[100000+5], arr3[100000+5];
vector < pair < int , int > > name_power;

int main() {

    scanf("%d %d", &n, &k);
    for (i = 1; i <= n; ++i) {
        scanf("%d", &x);
        name_power.push_back({x, i});
    }
    arr[0] = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    sort(name_power.begin(), name_power.end());

    int y = name_power[0].second;
    arr2[y] = arr[y];
    for (i = 1; i < n; ++i) {
        x = name_power[i].second;
        //cout << "power " << x << endl;
        arr2[x] = arr2[y] + arr[x];
        y = x;
    }

    y = name_power[0].second;
    arr3[y] = arr2[y];
    for (i = 1; i < n; ++i) {
        x = name_power[i].second;
        //cout << "power " << x << endl;
        //arr2[x] = arr2[y] + arr[x];
        u = i - k - 1;
        arr3[x] = arr2[x];
        if (u >= 0) {
            u = name_power[u].second;
            arr3[x] -= arr2[u];
        }
        y = x;
    }
    for (i = 1; i <= n; ++i) {
        //printf("%lld ", arr3[i]);
        cout << arr3[i] << " ";
    }


    return (0);
}
