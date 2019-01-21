#include <bits/stdc++.h>


using namespace std;

int main() {

    int n, i, arr[1000+5], mx = 0, mn = 101, cost = INT_MAX, cCost, t;

    cin >> n;
    for (i = 0; i < n; ++i) {
        cin >> arr[i];
        if(mx < arr[i]) mx = arr[i];
        if(mn > arr[i]) mn = arr[i];
    }

    for (mn = 1, t = mn; mn <= mx; ++mn) {
        cCost = 0;
        for (i = 0; i < n; ++i) {
            if(arr[i] > mn)
                cCost += abs(mn - arr[i] + 1);
            else if (arr[i] < mn) cCost += abs(mn - arr[i] - 1);
        }
//        if(mn == 2) {
//            cout << cost << " " << cCost << endl;
//        }
        if(cost > cCost) {
            cost = cCost;
            t = mn;
        }
    }

    cout << t << " " << cost << endl;

    return (0);
}
