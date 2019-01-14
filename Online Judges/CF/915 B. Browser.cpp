
#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, pos, l, r, s = 1, time = 0;
    cin >> n >> pos >> l >> r;
    //printf("%d %d %d %d\n", n, pos, l, r);
    if (s == l && n == r) {
        cout << "0" << endl;
    }
    else {
        if (pos < l) {
            time += (l - pos) + 1;
            if (n > r){
                time += (r - l) + 1;
            }
        }
        else if (pos > r) {
            time += (pos - r) + 1;
            if (l > 1){
                time += (r - l) + 1;

            }
        }
        else if ((pos - l) <= (r - pos) && l != 1 && r != n) {
            time += (pos - l) + 1;
            time += (r - l) + 1;

        }
        else if ((pos - l) > (r - pos) && l != 1 && r != n) {
            time += (r - pos) + 1;
            time += (r - l) + 1;
        }
        else if (l == 1) {
            //cout << "here" << endl;
            time += (r - pos) + 1;
        }
        else {
            time += (pos - l) + 1;
        }
        cout << time << endl;
    }

    return (0);
}
