#include <bits/stdc++.h>

using namespace std;
string str[110];

int main() {
    //freopen("in.txt", "r", stdin);
    vector<string> mins;
    string s;
    int test, t, R, C, i, j;

    scanf("%d", &test);

    for (t = 1; t <= test; ++t) {
        mins.clear();
        scanf("%d %d", &R, &C);
        getchar();

        /// Take input
        for (i = 0; i < R; ++i) {
            //gets(str[i]);
            //scanf("%s", &str[i]);
            //getchar();
            cin >> str[i];
        }

        /// Find Vertically
        for (i = 0; i < R; ++i) {

            s = "";
            for (j = 0; j < C; ++j) {

                if (str[i][j] != 'X') {
                    s += str[i][j];
                }
                else if (s.size() > 1) {
                    mins.push_back(s);
                    s = "";
                }
                else {
                    s = "";
                }
            }
            if (s.size() > 1) {
                mins.push_back(s);
                s = "";
            }
        }

        /// Find Horizontally
        for (i = 0; i < C; ++i) {
            s = "";
            for (j = 0; j < R; ++j) {
                if (str[j][i] != 'X') {
                    s += str[j][i];
                }
                else if (s.size() > 1) {
                    mins.push_back(s);
                    s = "";
                }
                else s = "";
            }
            if (s.size() > 1) {
                mins.push_back(s);
                s = "";
            }
        }

        /// Find Minimum
        s = mins[0];
        for (i = 0; i < mins.size(); ++i) {
            if (s > mins[i])
                s = mins[i];
        }

        printf("Case %d: %s\n", t, s.c_str());
    }

    return (0);
}
