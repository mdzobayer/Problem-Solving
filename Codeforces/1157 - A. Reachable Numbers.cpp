#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {

    long long int n;
    map<ll, ll> mp;

    cin >> n;

    while (mp.find(n) == mp.end()) {
        mp[n] = 1;
        ++n;
        while (n % 10 == 0) {
            n /= 10;
        }
    }
    cout << mp.size() << endl;

    return (0);
}