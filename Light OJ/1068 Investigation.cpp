#include <bits/stdc++.h>

using namespace std;

long long int dp[15][2][95][95], k ;

string toString (long long n) {
    string str;
    while (n != 0) {
        str += (n % 10) + '0';
        n /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
};

string s;
int nx;

long long digitDpSolve (int index, bool smaller, int mod1, int sum) {
    if (index == nx) {
        if (mod1 == 0 && (sum == 0)) {
            return 1;
        }
        return 0;
    }
    if (dp[index][smaller][mod1][sum] != -1) {
        return dp[index][smaller][mod1][sum];
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
            count += digitDpSolve(index + 1, ns, ((mod1 * 10) + i) % k, (sum + i) % k);
        }
        dp[index][smaller][mod1][sum] = count;

        return count;
    }
}

int main() {

   //freopen("in.txt", "r", stdin);
   //freopen("out.txt", "w", stdout);

    int a, b, test, t;


    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {

        scanf("%d %d %lld", &a, &b, &k);

        if(k == 1) {
            printf("Case %d: %d\n", t, b - a + 1);
        }
        else if(k == 0 || k > 85) {
            printf("Case %d: 0\n", t);
        }
        else {
            s = toString(b);
            nx = s.length();
            memset(dp, -1, sizeof(dp));
            long long a2 = digitDpSolve(0, 1, 0, 0);


            s = toString(a - 1);
            nx = s.length();
            memset(dp, -1, sizeof(dp));
            long long a1 = digitDpSolve( 0, 1, 0, 0);



            printf("Case %d: %lld\n", t, a2 - a1);
        }
    }

    return (0);
}
