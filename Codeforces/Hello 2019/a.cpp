#include <bits/stdc++.h>


using namespace std;


int main() {

    string table, t;
    map<string, int> mp;

    memset(suit, 0, sizeof(suit));
    cin >> table;


    for (int i = 0; i < 5; ++i) {
        cin >> t;
        if(table[0] == t[0]) {
            cout << "YES" << endl;
            return (0);
        }
    }
    cout << "NO" << endl;

    return (0);
}
