#include <bits/stdc++.h>

using namespace std;

int i, n, x, arr1[200000+10];

map<int, int> mp;

int main() {

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr1[i]);
    }

    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        mp[x] += 1;
    }

    return (0);
}