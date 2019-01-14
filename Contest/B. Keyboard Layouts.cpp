#include <bits/stdc++.h>

using namespace std;

int main() {

    string s1, s2, s3, s = "";
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    int i , j;
    for ( i = 0; i < s3.size(); ++i) {
        if (s3[i] >= 65 && s3[i] <= 90) {

            for (j = 0; j < s1.size(); ++j) {
                if (s1[j] == (s3[i] + 32)) {
                    s += (s2[j] - 32);
                }
            }

        }
        else if (s3[i] >= 97 && s3[i] <= 122) {
            for (j = 0; j < s1.size(); ++j) {
                if (s1[j] == s3[i]) {
                    s += s2[j];
                }
            }
        }
        else {
            s += s3[i];
        }
    }
    printf("%s\n", s.c_str());

    return (0);
}
