#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string str;

void permutation(const string & subStr, int pos) {
    if (str.size() == pos) {
        printf("%s\n", subStr.c_str());
        return;
    }
    for (int i = 0; i <= subStr.size(); ++i) {
        permutation(subStr.substr(0,i) + str[pos] + subStr.substr(i), pos + 1);
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    string ss = "";
    bool flag = false;
    while(cin >> str) {
        if (flag) {
            printf("\n");
        }
        flag = true;
        permutation(ss, 0);
    }

    return (0);
}
