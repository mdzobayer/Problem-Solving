#include <bits/stdc++.h>


using namespace std;

string str[2];
int sz;
bool visi[2][105];
bool one(int x) {
    if (x + 1 >= sz) return false;
    if (str[0][x+1] == '0' && visi[0][x+1]){
        if (str[1][x] == '0' && visi[1][x]) {
            visi[0][x+1] = false;
            visi[1][x] = false;
            return true;
        }
    }
    return false;
}
bool two(int x) {
    if (x + 1 >= sz) return false;
    if (str[0][x+1] == '0' && visi[0][x+1]){
        if (str[1][x+1] == '0' && visi[1][x+1]) {
            visi[0][x+1] = false;
            visi[1][x+1] = false;
            return true;
        }
    }
    return false;
}
bool three(int x) {
    if (x - 1 < 0) return false;
    if (str[1][x - 1] == '0' && visi[1][x - 1]){
        if (str[1][x] == '0' && visi[1][x]) {
            visi[1][x - 1] = false;
            visi[1][x] = false;
            return true;
        }
    }
    return false;
}
bool four(int x) {
    if (x + 1 >= sz) return false;
    if (str[1][x] == '0' && visi[1][x]){
        if (str[1][x + 1] == '0' && visi[1][x + 1]) {
            visi[1][x] = false;
            visi[1][x + 1] = false;
            return true;
        }
    }
    return false;
}
int main() {


    int n, i, poss = 0;
    cin >> str[0] >> str[1];

    memset(visi, true, sizeof(visi));
    sz = str[0].size();
    for (i = 0; i < sz; ++i) {
        if (str[0][i] == '0' && visi[0][i]) {
            if (i == 0) {
                if (one(i)){
                    ++poss;
                    visi[0][i] = false;
                }
                else if (two(i)) {
                    ++poss;
                    visi[0][i] = false;
                }
                else if (four(i)) {
                    ++poss;
                    visi[0][i] = false;
                }
            }
            else if (i == sz - 1) {
                if (three(i)) {
                    ++poss;
                    visi[0][i] = false;
                }
            }
            else if (one(i)) {
                //if (one(i) || two(i) || three(i) || four(i)){
                    ++poss;
                    visi[0][i] = false;
                //}
            }
            else if (three(i)) {
                ++poss;
                visi[0][i] = false;
            }
            else if (two(i)) {
                ++poss;
                    visi[0][i] = false;
            }
            else if (four(i)) {
                ++poss;
                visi[0][i] = false;
            }
        }
    }
    cout << poss << endl;

    return (0);
}
