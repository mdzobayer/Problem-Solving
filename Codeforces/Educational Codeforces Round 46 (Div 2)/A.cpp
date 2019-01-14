#include <bits/stdc++.h>

using namespace std;
string a[105], b[105];
bool aa[105], bb[105];

int main() {

    memset(aa, true, sizeof(aa));
    memset(bb, true, sizeof(bb));

    int n, i, j, sz, time = 0, foundIndex, possMin, k, tmp, x, y;
    cin >> n;
    for (i = 0; i < n; ++i) {
        cin.ignore();
        cin >> a[i];
    }
    for (i = 0; i < n; ++i) {
        cin.ignore();
        cin >> b[i];
    }

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            if (a[i] == b[j] && aa[i] && bb[j]) {
                aa[i] = false;
                bb[j] = false;
                //cout << a[i] << " " << b[j] << endl;
                break;
            }
        }
    }

    for (i = 0; i < n; ++i) {
        if (aa[i]){
            foundIndex = -1;
            possMin = INT_MAX;
            for (j = 0; j < n; ++j) {
                tmp = 0;
                if (bb[j]) {
                    x = a[i].size();
                    y = b[j].size();
                    sz = min(x, y);
                    //cout << "--- " << a[i] << " " << b[j] << endl;
                    tmp = abs(x - y);
                    //cout << a[i] << " " << b[j] << endl;
                    //cout << x - y << endl;
                    //cout << "Debug 1: " << tmp << endl;
                    for (k = 0; k < sz; ++k) {
                        if (a[i][k] != b[j][k]) {
                            ++tmp;
                            //cout << "here" << endl;
                        }
                    }

                    if (possMin > tmp) {
                        possMin = tmp;
                        foundIndex = j;
                    }
                    //cout << "Check " << possMin << " " << tmp << endl;
                }

            }
            aa[i] = false;
            bb[foundIndex] = false;
            time += possMin;
            //cout << possMin << endl;
        }
    }

    cout << time << endl;

    return (0);
}
