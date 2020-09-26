#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, i, j, x, count;
    string str;
    vector < string > words;

    cin >> n;

    for (i = 0; i < n; ++i) {
        cin >> str;

        count = 0;
        for (j = 0; j < i; ++j) {
            if (words[j] < str) {
                ++count;
            }
        }

        printf("%d\n", count);

        words.push_back(str);

        sort(words.begin(), words.end());
    }

    return (0);
}