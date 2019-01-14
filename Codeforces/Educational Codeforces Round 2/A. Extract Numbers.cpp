#include <bits/stdc++.h>


using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    int i;
    bool flag = false, ca = true, cb = true, last = false;
    string s, a = "", b = "", tmp = "";
    vector < string > st;
    vector < string > nt;

    cin >> s;

    for (i = 0; i < s.size(); ++i) {
        if(s[i] == ',' || s[i] == ';' ) {
            //cout << tmp << endl;
            if(flag) {
                st.push_back(tmp);
                tmp = "";
                flag = false;
            }
            else if (tmp[0] == '0' && tmp.size() > 1) {
                st.push_back(tmp);
                tmp = "";
                flag = false;
            }
            else if(tmp == "") {
                st.push_back(tmp);
                flag = false;
            }
            else {
                nt.push_back(tmp);
                tmp = "";
            }
            //cout << tmp << endl;
            last = true;
        }
        else if(flag || s[i] == '.' || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            flag = true;
            tmp += s[i];
            last = false;
        }
        else {
            flag = false;
            tmp += s[i];
            last = false;
        }

    }

            if(flag) {
                st.push_back(tmp);
                tmp = "";
                flag = false;
            }
            else if (tmp[0] == '0' && tmp.size() > 1) {
                st.push_back(tmp);
                tmp = "";
                flag = false;
            }
            else if(tmp == "") {
                st.push_back(tmp);
                flag = false;
            }
            else {
                nt.push_back(tmp);
                tmp = "";
            }

    if(nt.size() == 0) {
        cout << "-" << endl;
    }
    else {
        cout << "\"" << nt[0];
        for (i = 1; i < nt.size(); ++i) {
            cout << "," << nt[i];
        }
        cout << "\"" << endl;
    }

    if(st.size() == 0) {
        cout << "-" << endl;
    }
    else {
        cout << "\"" << st[0];
        for (i = 1; i < st.size(); ++i) {
            cout << "," << st[i];
        }
        cout << "\"" << endl;
    }



    return (0);
}
