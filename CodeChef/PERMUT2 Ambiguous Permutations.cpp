#include <bits/stdc++.h>


using namespace std;

int ori[100000+5], inv[100000+5];

int main() {

    //freopen("in.txt", "r", stdin);

    int n, i;
    while(scanf("%d", &n) == 1){
        if (n == 0) break;
        for (i = 1; i <= n; ++i) {
            scanf("%d", &ori[i]);
            inv[ori[i]] = i;
        }
        bool flag = true;
        for (i = 1; i <= n; ++i) {
            if (ori[i] != inv[i]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << "ambiguous" << endl;
        }
        else {
            cout << "not ambiguous" << endl;
        }
    }


    return (0);
}
