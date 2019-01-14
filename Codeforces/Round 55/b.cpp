#include <bits/stdc++.h>

using namespace std;

struct seg{
    int Count;
    char c;
};
vector < seg > vt;
int main() {

    //freopen("in.txt", "r", stdin);

    int n, i, cnn = 0, mx = 0, tmpans, gss = 0;
    seg tmp;

    char ch = 'G';
    string s;
    cin >> n;
    cin.ignore();
    cin >> s;
    //cout << "input " << s << endl;
    for (i = 0; i < n; ++i) {
        if(ch == s[i]) {
            ++cnn;
        }
        else if(cnn > 0){
            if(ch == 'G')
                ++gss;
            tmp.c = ch;
            tmp.Count = cnn;
            cnn = 1;
            ch = s[i];
            vt.push_back(tmp);
        }
    }
    if(ch == 'G')
        ++gss;
    tmp.c = ch;
    tmp.Count = cnn;
    vt.push_back(tmp);

    for (i = 0; i < vt.size(); ++i) {
        cout << "Debug " << i << " : " << vt[i].Count << endl;
        if(vt[i].c == 'G') {
            mx = max(mx, vt[i].Count);
        }
        else if(gss > 2 && vt[i].Count == 1) {
            //
            tmpans = 0;
            if(i > 0) {
                tmpans = vt[i-1].Count;
            }
            if(i < vt.size() - 1) {
                tmpans += vt[i+1].Count;
            }
            ++tmpans;
            cout << "Debug critical " << tmpans << endl;
            mx = max(mx,  tmpans);
        }
    }
    cout << mx << endl;

    return (0);
}
