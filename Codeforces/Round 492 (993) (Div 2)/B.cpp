#include <bits/stdc++.h>

using namespace std;
#define ll long long int
ll n, arr[100000+5], x, i, y;

int main() {
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> x;
        arr[i] = x / n;
        y = x % n;
        if ( y > i) {
            ++arr[i];
        }
    }
    cout << (min_element(arr, arr+n) - arr) + 1 << endl;

    return (0);
}
