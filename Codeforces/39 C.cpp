
#include <bits/stdc++.h>
#define LLI long long int

using namespace std;

bool isPosible(string &str, LLI i) {
    LLI i;
    bool use[150];
    memset(use, false, sizeof(use));
    for (i = 0; i < str.size(); ++i) {
        if (use[str[i - 1]] == false && str[i] > 'a' ) return false;
        if (use[str[i]] == false) {
            use[str[i]] = true;
        }
    }
}

int main() {

    string s;
    cin >> s;

    long long int i;
    for (i = 0; i < s.size(); ++i) {

    }



    return (0);
}
