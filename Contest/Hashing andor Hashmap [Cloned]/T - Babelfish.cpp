#include <cstdio>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

map<string, string> dic;

int main() {
    //freopen("in.txt", "r", stdin);

    string s1, s2, s3;

    while(getline(cin, s1)) {
        if (s1 == "") break;
        stringstream ss(s1);
        ss >> s2;
        ss >> s3;
        dic[s3] = s2;
    }

    while(cin >> s1) {
        if (dic.find(s1) != dic.end()) {
            printf("%s\n", dic[s1].c_str());
        }
        else {
            printf("eh\n");
        }

    }

    return (0);
}
