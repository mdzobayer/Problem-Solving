#include <bits/stdc++.h>


using namespace std;

int main() {

    bool went[10000+5];

    int i, n, r, x;
    while(cin >> n >> r) {
        memset(went, true, sizeof(went));
        for (i = 0; i < r; ++i) {
            cin >> x;
            went[x] = false;
        }
        int cnn = 0;
        for (i = 1; i <= n; ++i) {

            if(went[i]){
                if(cnn > 0) cout << " ";
                cout << i;
                cnn++;
            }
        }
        if(cnn > 0)
            cout << " " << endl;
        else cout << "*" << endl;

    }


    return (0);
}
