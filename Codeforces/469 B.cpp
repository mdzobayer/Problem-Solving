#include <bits/stdc++.h>
#define LLI long long int

using namespace std;

LLI x[100000+5], y[100000+5];

int main() {

    LLI n, m, i, j, block1 = 0, block2 = 0, conn = 0;

    cin >> n >> m;
    for (i = 0; i < n; ++i) {
        cin >> x[i];
    }
    for (i = 0; i < m; ++i) {
        cin >> y[i];
    }
    block1 = x[0];
    block2 = y[0];
    for (i = 0, j = 0; (i < n && j < m); ) {

        //block2 += y[j];
        //cout << block1 << " " << block2 << endl;
        if (block1 == block2) {
            ++conn;
            ++i; ++j;
            block2 = block1 = 0;
            block1 = x[i];
            block2 = y[j];
        }
        else if (block1 < block2) {
            ++i;
            block1 += x[i];
            //cout << "i am" << endl;
        }
        else {
            //cout <<  "j am" << endl;
            ++j;
            block2 += y[j];

        }
    }

    cout << conn << endl;

    return (0);
}
