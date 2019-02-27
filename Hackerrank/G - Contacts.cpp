#include <bits/stdc++.h>

using namespace std;

map < string , int > mpp;

int main() {

    //freopen("in.txt", "r", stdin);

    string cmd, word, tmp;
    int n, i, len;
    cin >> n;
    cin.ignore();
    while(n--) {
        cin >> cmd >> word;
        if(cmd == "add") {
            len = word.size();
            tmp = "";
            for (i = 0; i < len; ++i) {
                tmp += word[i];
                mpp[tmp] += 1;
            }
        }
        else {
            if(mpp.find(word) == mpp.end()) {
                cout << "0" << endl;
            }
            else {
                cout << mpp[word] << endl;
            }
        }
    }


    return (0);
}
