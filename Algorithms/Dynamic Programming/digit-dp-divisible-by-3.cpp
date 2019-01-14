#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

long long int dp[12][2][83], k;

string toString (long long n) {
    string str;
    while (n != 0) {
        str += (n % 10) + '0';
        n /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
};

long long digitDpSolve (string & s, int index, bool smaller, int mod1) {
    if (index == s.length()) {
        if (mod1 == 0) {
            return 1;
        }
        return 0;
    }
    if (dp[index][smaller][mod1] != -1) {
        return dp[index][smaller][mod1];
    }
    else {
        int limit = 9;

        if (smaller) {
            limit = s[index] - '0';
        }
        long long int count = 0;

        for (int i = 0; i <= limit; ++i) {
            bool ns;
            if (i < s[index] - '0') {
                ns = 0;
            }
            else {
                ns = smaller;
            }
            count += digitDpSolve(s, index + 1, ns, (mod1 + i) % k);
        }
        dp[index][smaller][mod1] = count;
        return count;
    }
}

int main(int argc, char * argv[]) {

    int a, b;
    scanf("%d %d %lld", &a, &b, &k);

    if (k > 82) {
        printf("0\n");
    }
    string s1 = toString(a - 1);
    string s2 = toString(b);

    memset(dp, -1, sizeof(dp));
    long long a1 = digitDpSolve(s1, 0, 1, 0);

    memset(dp, -1, sizeof(dp));
    long long a2 = digitDpSolve(s2, 0, 1, 0);

    printf("%d\n", a2 - a1);

    return (0);
}
