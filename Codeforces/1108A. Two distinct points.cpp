#include <bits/stdc++.h>

using namespace std;

int main() {

    int l1,r1,l2,r2, n;
    cin >> n;
    while(n--) {
        cin >> l1 >> r1 >> l2 >> r2;
        for (l1; l1 <= r1; ++l1) {
            for (l2; l2 <= r2; ++l2) {
                if(l1 != l2) {
                    cout << l1 << " " << l2 << endl;
                    l2 = r2 + 1;
                    l1 = r1 + 1;
                    break;
                }
            }
        }
    }

    return (0);
}
