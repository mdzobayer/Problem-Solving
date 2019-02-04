#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string str;

void dfs(const string &s, const int l) {
    printf("Level %d Tree  %s\n", l, s.c_str());
    if (l == str.size()) {
        //cout << s << endl;
    }
    else {
        for (int i = 0; i <= s.size(); ++i) {
            dfs(s.substr(0,i) + str[l] + s.substr(i), l+1);
        }
    }
}

int main() {

    bool n1 = false;

    while ( cin >> str) {
        if (n1) putchar('\n');
        else n1 = true;

        dfs("", 0);
    }

    return (0);
}
