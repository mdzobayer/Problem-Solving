#include <cstdio>
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

int main() {
    string s = "";
    stringstream ss;
    int i, count = 1;
    char preS = 0;
    char str[8010];
    gets(str);
    int len = strlen(str);
    preS = str[0];
    for (i = 1; i < len; ++i) {
        if (str[i] == preS) {
            count++;
        }
        else {
            ss << count;
            ss << preS;
            preS = str[i];
            count = 1;
        }
    }
    ss << count;
    ss << preS;
    s = ss.str();
    printf("%s ", s.c_str());
    printf("%d\n", s.size());

    return (0);
}
