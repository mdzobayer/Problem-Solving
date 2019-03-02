#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, v, tank = 0, need = 0, cost = 0, tmp;
    cin >> n >> v;

    if(n - 1 <= v) {
        cout << n - 1 << endl;
        return (0);
    }

    for (int i = 1; i <= n - v; ++i) {
        //cout << i << " " << tank << endl;
        if ( tank < v) {
            cost += (v - tank) * i;
            tank = v;
        }
        --tank;
    }
    cout << cost << endl;

    return (0);
}
