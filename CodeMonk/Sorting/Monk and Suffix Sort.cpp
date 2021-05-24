#include <bits/stdc++.h>

using namespace std;

int main() {

    int k, i;
    string s;

    vector < string > words;

    cin >> s >> k;

    for (i = 0; i < s.length(); ++ i) {
        words.push_back(s.substr(i));
    }

    sort(words.begin(), words.end());

    cout << words[k-1] << endl;


    return (0);
}