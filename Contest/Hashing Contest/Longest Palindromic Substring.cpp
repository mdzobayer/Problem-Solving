#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <iostream>
#define lli long long int

using namespace std;

lli max(lli x, lli y){
    return x > y ? x : y;
}

map<string, lli> dp;
string s;
char number[20];


lli lps(char * str, lli l, lli r) {
    if (l == r) return 1;

    if (str[l] == str[r] && l + 1 == r) {
        return 2;
    }
    s = "";
    sprintf(number,"%lld%lld", l, r);
    s = number;

    if (dp.find(s) != dp.end()) {
        return dp[s];
    }

    if (str[l] == str[r]) {
        return dp[s] = 2 + lps(str, l + 1, r - 1);
    }

    return dp[s] = max(lps(str, l + 1, r), lps(str, l, r - 1));
}

int main() {

    lli n;
    char str[100000 + 5];
    while(scanf("%lld", &n) == 1) {
        dp.clear();
        getchar();
        scanf("%s", &str);
        printf("%lld\n", lps(str, 0, n - 1));
    }

    return (0);
}
