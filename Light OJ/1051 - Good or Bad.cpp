#include <bits/stdc++.h>

char s[55];
int dp[55][5][7];

bool isVowel(char c) {
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;
    return false;
}

int genResult(int i, int vowel, int conso) {
    if (vowel == 3 || conso == 5) return 1;

    /// End of string && no bad found
    if (!s[i]) return 2;

    int & result = dp[i][vowel][conso];

    if (result != -1)
        return result;

    if (s[i] == '?')
        result = genResult(i + 1, vowel + 1, 0) | genResult(i + 1, 0, conso + 1);
    else if (isVowel(s[i]))
        result = genResult(i + 1, vowel + 1, 0);
    else
        result = genResult(i + 1, 0, conso + 1);

    return result;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, result;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        getchar();
        scanf("%s", &s);
        //printf("Input %s\n", s);
        memset(dp, -1, sizeof(dp));
        result = genResult(0,0,0);
        printf("Case %d: ", t);
        if (result == 1) printf("BAD\n");
        else if (result == 2) printf("GOOD\n");
        else printf("MIXED\n");
    }

    return (0);
}
