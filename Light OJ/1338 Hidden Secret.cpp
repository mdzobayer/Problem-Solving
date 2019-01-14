#include <bits/stdc++.h>

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);

    string s1, s2;
    int test, t, i, arr1[100], arr2[100];
    bool flag;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {
        getline(cin, s1);
        getline(cin, s2);

        memset(arr1, 0, sizeof(arr1));
        memset(arr2, 0, sizeof(arr2));

        for (i = 0; i < s1.size(); ++i) {
            if (isalpha(s1[i])) {
                if (islower(s1[i])) {
                    s1[i] = toupper(s1[i]);
                }
                ++arr1[s1[i]];
            }
        }

        for (i = 0; i < s2.size(); ++i) {
            if (isalpha(s2[i])) {
                if (islower(s2[i])) {
                    s2[i] = toupper(s2[i]);
                }
                ++arr2[s2[i]];
            }
        }
        printf("Case %d: ", t);
        flag = true;
        for (i = 65 ; i < 100; ++i) {

            if (arr1[i] != arr2[i]) {
                flag = false;
                break;
            }

            //printf("%c %d %d\n", i, arr1[i], arr2[i]);
        }
        if (flag) {
            printf("Yes\n");
        }
        else printf("No\n");
    }

    return (0);
}
