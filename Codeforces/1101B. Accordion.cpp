#include <bits/stdc++.h>

using namespace std;

string s;
bool expect(int a, int i) {
    if(a == 1) {

    }
}

int main() {
    bool start = true;;
    int i, Max, sta = -1, ends = -1, fColone = -1, eColone = -1;
    string tmp = "";
    cin >> s;
    for (i = 0; i < s.size(); ++i) {
        if(s[i] == '[' && start) {
            tmp += '[';
            sta = tmp.size() - 1;
            start = false;
        }
        else if(s[i] == ':' || s[i] == '|' || s[i] == ']') {
            tmp += s[i];
        }
    }

    if(sta == -1) {

        cout << -1 << endl;
        return (0);
    }

    for (i = tmp.size() - 1; i > sta; --i) {
        if(tmp[i] == ']') {
            ends = i;
            break;
        }
    }

    for (i = sta + 1; i < ends; ++i) {
        if(tmp[i] == ':') {
            fColone = i;
            break;
        }
    }

    for (i = ends - 1; i > fColone; --i) {
        if(tmp[i] == ':') {
            eColone = i;
            break;
        }
    }
    //cout << tmp << endl;
        //cout << "Debug " << ends << " " << eColone << " " << fColone << endl;

    if(ends == -1 || eColone == -1 || fColone == -1) {
        cout << "-1" << endl;
        return (0);
    }
    int ans = 4;
    for (i = fColone + 1; i < eColone; ++i) {
        if(tmp[i] == '|')
            ++ans;
    }
    cout << ans << endl;

    return (0);
}
