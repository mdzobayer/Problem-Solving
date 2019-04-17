#include <bits/stdc++.h>

using namespace std;

int main() {

    string s, s1, s2, s3;
    int test;
    cin >> test;
    while(test--) {
        int beds, kitchen, living, ans, n, j, i;
        ans = beds = kitchen = living = 0;
        cin >> n;
        cin.ignore();
        for (i = 0; i < n; ++i) {
            cin >> s;
            for (j = 0; j < s.size(); ++j) {
                s[j] = tolower(s[j]);
            }

            s1 = s.substr(0, 3);
            s2 = s.substr(0, 7);
            s3 = s.substr(0, 6);
            if (s1 == "bed") {
                ++beds;
            }
            else if (s2 == "kitchen") {
                ++kitchen;
            }
            else if (s3 == "living") {
                ++living;
            }
        }

        ans = min(kitchen, living);
        if (ans * 2 <= beds) {
            cout << ans << endl;
        }
        else {
            cout << beds/2 << endl;
        }

    }

    return (0);
}
