#include <bits/stdc++.h>

using namespace std;

int main() {

    int i, x;

    cin >> x;
    for (i = 1; i * i < x; ++i) {
        
    }
    if (i*i == x) {
        cout << i << endl;
    }
    else {
        int j = 0;
        double low = i - 1, high = i, mid;

        while(j < 100000) {
            ++j;
            mid = (low + high) / 2.0;

            if (mid * mid > x) {
                high = mid;
            }
            else if (mid * mid < x) {
                low = mid;
            }
            else {
                cout << "Found and = " << mid << endl;
                break;
            }

        }
        cout << high << endl;
    }
    

    return (0);
}