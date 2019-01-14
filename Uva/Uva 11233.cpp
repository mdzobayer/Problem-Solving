#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

bool isVowel(const char& s) {
    if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
        return true;
    else
        return false;
}

int main() {
    size_t i;
    int l, n, len;
    string str1, str3;
    while(scanf("%d %d", &l, &n) == 2) {
        map<string, string> irregular;
        getchar();
        for(i = 0; i < l; ++i) {
            cin >> str1 >> str3;
            getchar();
            irregular.insert(map<string, string>::value_type(str1, str3));
        }
        for (i = 0; i < n; ++i) {
            cin >> str1;
            len = str1.length();
            getchar();
            string str2 = "";
            str2 += str1[len - 2];
            str2 += str1[len - 1];
            if(irregular.find(str1) != irregular.end()) {
                //printf("%s\n", str1.c_str());
                cout << irregular[str1] << endl;
            }
            else if((str1[len - 1] == 'y') && !(isVowel(str1[len - 2]))) {
                str1.pop_back();
                str1 += "ies";
                printf("%s\n", str1.c_str());
            }
            else if(str1[len-1] == 'o' || str1[len-1] == 's' || str1[len-1] == 'x') {
                str1 += "es";
                printf("%s\n", str1.c_str());
            }
            else if(str2 == "ch" || str2 == "sh") {
                str1 += "es";
                printf("%s\n", str1.c_str());
            }
            else {
                str1 += 's';
                printf("%s\n", str1.c_str());
            }
        }
    }

    return (0);
}
/**
3 7
rice rice
spaghetti spaghetti
octopus octopi
rice
lobster
spaghetti
strawberry
octopus
peach
turkey

**/
