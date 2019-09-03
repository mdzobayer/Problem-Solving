#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int n, x, y, p1 = 0, p2 = 0, leader = 0, leadAmount = 0;
    cin >> n;
    while(n--) {
        cin >> x >> y;
        p1 += x;
        p2 += y;
        x = max(p1, p2) - min(p1, p2);

        if (p1 > p2) {
            if (x >= leadAmount) {
                leadAmount = x;
                leader = 1;
            }
        }
        if (p1 < p2) {
            if (x >= leadAmount) {
                leadAmount = x;
                leader = 2;
            }
        }
    }
    cout << leader << " " << leadAmount << endl;

    return (0);
}