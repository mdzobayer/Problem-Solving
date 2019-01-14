#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {

    ll base, test, t, k, i, n, res;
    int digit[95], Count;
    digit['0'] = 0;
    digit['1'] = 1;
    digit['2'] = 2;
    digit['3'] = 3;
    digit['4'] = 4;
    digit['5'] = 5;
    digit['6'] = 6;
    digit['7'] = 7;
    digit['8'] = 8;
    digit['9'] = 9;
    digit['A'] = 10;
    digit['B'] = 11;
    digit['C'] = 12;
    digit['D'] = 13;
    digit['E'] = 14;
    digit['F'] = 15;

    string s;
    scanf("%lld", &test);
    for(t = 1; t <= test; ++t) {
        scanf("%lld %lld", &base, &k);
        Count = 0;
        getchar();
        cin >> s;
        Count = 0;
        n = s.size();
        res = 1;
        bool flag = true;
        for (i = 0; i < n; ++i)
            if(digit[s[i]] < base)
                ++Count;
            else {
                flag = false;
                break;
            }

        for (i = 1; i <= Count && flag; ++i)
            res *= i;
        if(flag)
            printf("Case %lld: %lld\n", t, res/k);
        else printf("Case %lld: 0\n", t);
    }


    return (0);
}
