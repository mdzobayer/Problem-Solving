
#include <bits/stdc++.h>

using namespace std;


int main() {

    int n, i, cCost, cost = INT_MAX;

    string s, s2, s3;
    cin >> n >> s3;

    // RGB
    s = s3;
    cCost = 0;
    for (i = 0; i < n; i += 3) {
        if(s[i] != 'R') {
            ++cCost;
            s[i] = 'R';
        }

        if(i + 1 >= n) break;
        if(s[i + 1] != 'G') {
            ++cCost;
            s[i + 1] = 'G';
        }

        if(i + 2 >= n) break;
        if(s[i + 2] != 'B') {
            ++cCost;
            s[i + 2] = 'B';
        }
    }
    if(cCost < cost) {
        cost = cCost;
        s2 = s;
    }

    // RBG
    s = s3;
    cCost = 0;
    for (i = 0; i < n; i += 3) {
        if(s[i] != 'R') {
            ++cCost;
            s[i] = 'R';
        }

        if(i + 1 >= n) break;
        if(s[i + 1] != 'B') {
            ++cCost;
            s[i + 1] = 'B';
        }

        if(i + 2 >= n) break;
        if(s[i + 2] != 'G') {
            ++cCost;
            s[i + 2] = 'G';
        }
    }
    if(cCost < cost) {
        cost = cCost;
        s2 = s;
    }


    // GBR
    s = s3;
    cCost = 0;
    for (i = 0; i < n; i += 3) {
        if(s[i] != 'G') {
            ++cCost;
            s[i] = 'G';
        }

        if(i + 1 >= n) break;
        if(s[i + 1] != 'B') {
            ++cCost;
            s[i + 1] = 'B';
        }

        if(i + 2 >= n) break;
        if(s[i + 2] != 'R') {
            ++cCost;
            s[i + 2] = 'R';
        }
    }
    if(cCost < cost) {
        cost = cCost;
        s2 = s;
    }

    // GRB
    s = s3;
    cCost = 0;
    for (i = 0; i < n; i += 3) {
        if(s[i] != 'G') {
            ++cCost;
            s[i] = 'G';
        }

        if(i + 1 >= n) break;
        if(s[i + 1] != 'R') {
            ++cCost;
            s[i + 1] = 'R';
        }

        if(i + 2 >= n) break;
        if(s[i + 2] != 'B') {
            ++cCost;
            s[i + 2] = 'B';
        }
    }
    if(cCost < cost) {
        cost = cCost;
        s2 = s;
    }

    // BRG
    s = s3;
    cCost = 0;
    for (i = 0; i < n; i += 3) {
        if(s[i] != 'B') {
            ++cCost;
            s[i] = 'B';
        }

        if(i + 1 >= n) break;
        if(s[i + 1] != 'R') {
            ++cCost;
            s[i + 1] = 'R';
        }

        if(i + 2 >= n) break;
        if(s[i + 2] != 'G') {
            ++cCost;
            s[i + 2] = 'G';
        }
    }
    if(cCost < cost) {
        cost = cCost;
        s2 = s;
    }

    // BGR
    s = s3;
    cCost = 0;
    for (i = 0; i < n; i += 3) {
        if(s[i] != 'B') {
            ++cCost;
            s[i] = 'B';
        }

        if(i + 1 >= n) break;
        if(s[i + 1] != 'G') {
            ++cCost;
            s[i + 1] = 'G';
        }

        if(i + 2 >= n) break;
        if(s[i + 2] != 'R') {
            ++cCost;
            s[i + 2] = 'R';
        }
    }
    if(cCost < cost) {
        cost = cCost;
        s2 = s;
    }



    cout << cost << endl;
    cout << s2 << endl;



    return (0);
}
