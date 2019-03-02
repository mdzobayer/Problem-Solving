#include <bits/stdc++.h>

using namespace std;

int inp[20], out[20], n, m;

int xx(int x) {
    if( x < 0) return (0);
    else return inp[x];
}
int yy(int y) {
    if(y >= n) return (0);
    else return inp[y];
}

int main() {

    //freopen("in.txt", "r", stdin);


    int i, j, k, x, y, sum, togo;
    vector < int > vt;

    while(cin >> n) {
        sum = 0;
        for (i = 0; i < n; ++i) {
            cin >> inp[i];
            sum += inp[i];
        }
        cin >> m;
        for (i = 0; i < m; ++i) {
            cin >> out[i];
        }
        bool flag = false;

        if(m == 1) {
            if(out[0] == sum) {
                cout << "S" << endl;
            }
            else {
                cout << "N" << endl;
            }
            continue;
        }

        for (i = 0; i < n; ++i) {
            vt.clear();
            x = i;
            y = i + 1;

            togo = max(x + 1, n - y);
            for (k = 0; k < togo; ++k) {
                sum = xx(x - k);
                sum += yy(y + k);
                vt.push_back(sum);
            }
//            cout << "x: " << x << " y: " << y << " m: " << vt.size() << endl;
//            if(vt.size() != m) continue;
//            for (k = 0; k < m; ++k) {
//                //sum = xx(x - k);
//                //sum += yy(y + k);
//                cout << vt[k] << " ";
//            }
//            cout << endl;

            flag = true;
            for (k = 0, j = m - 1; k < m; ++k, --j) {
                if(vt[j] != out[k]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << "S" << endl;
                break;
            }

            flag = true;
            for (k = 0, j = m - 1; k < m; ++k, --j) {
                if(vt[k] != out[k]) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                cout << "S" << endl;
                break;
            }

        }
        if(flag == false) {
            cout << "N" << endl;
        }
    }



    return (0);
}