#include <bits/stdc++.h>

using namespace std;


int main() {

    int test, n, x, y, k, p, c, i, need;
    bool flag;
    scanf("%d", &test);

    while(test--) {

        scanf("%d %d %d %d", &x, &y, &k, &n);

        need = x - y;
        flag = false;

        for (i = 0; i < n; ++i) {
            scanf("%d %d", &p, &c);
            if (k >= c && p >= need) {
                flag = true;
                //break;
            }
        }
        if (flag) {
            cout << "LuckyChef" << endl;
        }
        else {
            cout << "UnluckyChef" << endl;
        }
    }

    return (0);
}