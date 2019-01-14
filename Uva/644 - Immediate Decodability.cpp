#include <bits/stdc++.h>

using namespace std;
vector < string > symbols;

bool isPrefix(int x, int y) {
    int i, mn = min(symbols[x].size(), symbols[y].size());
    for (i = 0; i < mn; ++i) {
        if (symbols[x][i] != symbols[y][i])
            return false;
    }
    return true;
}

int main() {

    //freopen("in.txt", "r", stdin);

    string s;
    bool flag;
    int i, j, Set = 0;

    while(getline(cin, s)) {
        symbols.clear();
        //cerr << s << endl;
        if (s != "9") {
            symbols.push_back(s);
            ++Set;
            while(getline(cin, s) && s != "9") {
                symbols.push_back(s);
            }
        }
        flag = false;
        for (i = 0; i < symbols.size() - 1; ++i) {
            for (j = i + 1; j < symbols.size(); ++j) {
                if (isPrefix(i, j)) {
                    flag = true;
                    i = symbols.size();
                    break;
                }
            }
        }
        if (flag) {
            printf("Set %d is not immediately decodable\n", Set);
        }
        else {
            printf("Set %d is immediately decodable\n", Set);
        }
    }

    return (0);
}
