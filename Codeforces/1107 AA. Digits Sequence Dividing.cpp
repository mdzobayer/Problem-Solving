#include <bits/stdc++.h>

using namespace std;

void solve() {

}


int main() {

    string s;
    int n, i, q;
    cin >> q;
    while(q--) {
        cin >> n >> s;
        if(s.size() < 2) {
            cout << "NO" << endl;
        }
        else if(s.size() == 2){
            if(s[0] < s[1]) {
                cout << "YES" << endl << 2 << endl;
                cout << s[0] << " " << s[1] << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "YES" << endl << 2 << endl;
            cout << s[0] << " " << s.substr(1) << endl;
        }
    }

    return (0);
}
