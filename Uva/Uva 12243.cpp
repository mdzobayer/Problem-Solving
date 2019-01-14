#include <iostream>
#include <sstream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    string str, temp;
    char test;
    bool flag;
    while(getline(cin, str)) {
        if (str == "*")
            break;
        flag = true;
        stringstream ss;
        ss << str;
        ss >> temp;
        test = temp[0];
        while(ss >> temp) {
            if (test == temp[0])
                continue;
            else if (test == temp[0] + 32)
                continue;
            else if (test == temp[0] - 32)
                continue;
            else {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "Y\n";
        else
            cout << "N\n";
    }

    return (0);
}
