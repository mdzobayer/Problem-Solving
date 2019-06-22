#include <bits/stdc++.h>

using namespace std;

string s;
long long int len, inx;

int solve() {
    long long int ans = 0, recent = 0, multiply = 0;

    for ( ; s[inx] != ')'; ++inx) {

        if (s[inx] == '(') {
            
            if (multiply > 0) {
                recent *= multiply;
            }
            multiply = 0;
            ans += recent;

            ++inx;
            recent = solve();
        }
        else if (s[inx] == 'H') {

            if (multiply > 0) {
                recent *= multiply;
            }
            multiply = 0;
            ans += recent;

            recent = 1;

        }
        else if (s[inx] == 'C') {
            if (multiply > 0) {
                recent *= multiply;
            }
            multiply = 0;
            ans += recent;

            recent = 12;
        }
        else if (s[inx] == 'O') {
            if (multiply > 0) {
                recent *= multiply;
            }
            multiply = 0;
            ans += recent;

            recent = 16;
        }
        else if (s[inx] >= '0' && s[inx] <= '9') {
                //cout << "Test Debug 1" << endl;
            multiply *= 10;
            multiply += (s[inx] - '0');
        }
    }

    //cout << "solve ans = " << ans << endl;
    if (multiply) {
        recent *= multiply;
    }
    multiply = 0;
    ans += recent;


    return ans;
}

int main() {

    // freopen("in.txt", "r", stdin);

    cin >> s;
        //cout << "Input : " << s << endl;

        long long int ans = 0, recent = 0, multiply = 0;

        for ( inx = 0 ; inx < s.size(); ++inx) {
            if (s[inx] == '(') {
                
                if (multiply > 0) {
                    recent *= multiply;
                }
                multiply = 0;
                ans += recent;

                ++inx;
                recent = solve();
                //cout << "Returned ans : " << recent << endl;
            }
            else if (s[inx] == 'H') {

                if (multiply > 0) {
                    recent *= multiply;
                }
                multiply = 0;
                ans += recent;

                recent = 1;

            }
            else if (s[inx] == 'C') {
                if (multiply > 0) {
                    recent *= multiply;
                }
                multiply = 0;
                ans += recent;

                recent = 12;
            }
            else if (s[inx] == 'O') {
                if (multiply > 0) {
                    recent *= multiply;
                }
                multiply = 0;
                ans += recent;

                recent = 16;
            }
            else if (s[inx] >= '0' && s[inx] <= '9') {
                //cout << "Test Debug 1" << endl;
                multiply *= 10;
                multiply += s[inx] - '0';
            }
        }
        //cout << "multiply = " << multiply << endl;
        if (multiply > 0) {
            recent *= multiply;
        }
        multiply = 0;
        ans += recent;

        cout << ans << endl;
    

    return (0);
}