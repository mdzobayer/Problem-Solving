#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ll test, t, i, vagsesh;
    ll vajok;
    string s, vajjo;
    cin >> test;
    cin.ignore();
    for (t = 1; t <= test; ++t) {
        cin >> vajjo >> vajok;
        //cout << vajjo << " " << vajok << endl;
        cin.ignore();
        if (vajjo[0] == '-')
            i = 1;
        else i = 0;

        vagsesh = 0;
        for ( ; vajjo[i]; ++i) {
            vagsesh = ((vagsesh*10)+(vajjo[i]-'0'))%vajok;
        }
        printf("Case %d: ", t);
        if (vagsesh == 0) {
            printf("divisible\n");
        }
        else {
            printf("not divisible\n");
        }
    }

    return (0);
}
