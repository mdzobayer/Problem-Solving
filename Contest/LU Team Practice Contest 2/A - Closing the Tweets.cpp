#include <bits/stdc++.h>


using namespace std;


int main() {

    int n, k, i, x, opens = 0;
    bool status[1010];
    memset(status, false, sizeof(status));
    string str, s;
    cin >> n >> k;
    cin.ignore();
    for (i = 0; i < k; ++i) {
        //cin.ignore();
        getline(cin, str);
        if (str == "CLOSEALL") {
            memset(status, false, sizeof(status));
            opens = 0;
            printf("%d\n", opens);
        }
        else {
            stringstream ss(str);
            ss >> s;
            ss >> x;
            if (status[x]) {
                --opens;
                status[x] = false;
            }
            else {
                ++opens;
                status[x] = true;
            }

            printf("%d\n", opens);
        }
    }

    return (0);
}
