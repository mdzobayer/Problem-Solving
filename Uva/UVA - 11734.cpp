#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    char str[25];
    int test, t, i, j;
    bool isMatch, oferror;
    scanf("%d", &test);
    getchar();
    for (t = 1; t <= test; ++t) {
        string str1, str2;
        gets(str);
        str1 = str;

        gets(str);
        str2 = str;
        isMatch = true;
        oferror = false;
        for (i = j = 0; i < str2.size(); ++i, ++j) {
            while((j < str1.size()) && (str1[j] == ' ')) {
                ++j;
                oferror = true;
                //printf("-- %d %d\n", i, j);
            }
            if (str1[j] != str2[i]) {
                //printf("%d %d\n", i, j);
                isMatch = false;
                break;
            }
        }
        while(j < str1.size()) {
            //printf("Hello\n");
            if (str1[j] != ' ') {
                isMatch = false;
                break;
            }
            ++j;
        }
        printf("Case %d: ", t);
        if (isMatch == false) {
            printf("Wrong Answer\n");
        }
        else if (oferror || (str2.size() < str1.size())) {
            printf("Output Format Error\n");
        }
        else {
            printf("Yes\n");
        }
    }

    return (0);
}
