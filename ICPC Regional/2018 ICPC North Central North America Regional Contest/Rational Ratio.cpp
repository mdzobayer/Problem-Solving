#include <bits/stdc++.h>

using namespace std;

#define ll long long int

ll GCD(ll a, ll b) {
    if (b == 0) return a;

    return GCD(b, (a % b));
}

int main() {

    double repeatFractino, tmp;
    int repeatLen, i, fractionLen;
    ll numerator, denominator, intPart, firstMulti = 1, secondMulti = 1;

    string s, fractionPart;
    cin >> s >> repeatLen;

    //cout << s << " " << repeatLen << endl;
    for (i = 0; i < s.size(); ++i) {
        if (s[i] == '.') {
            s[i] = ' ';
            break;
        }
    }
    stringstream ss(s);

    ss >> intPart;
    ss >> fractionPart;

    fractionLen = fractionPart.size();

    numerator = intPart;
    denominator = intPart;
    for (i = 0; i < fractionLen; ++i) {
        numerator *= 10;
        numerator += (fractionPart[i] - '0');
        firstMulti *= 10;
        if (i < fractionLen - repeatLen) {
            denominator *= 10;
            denominator += (fractionPart[i] - '0');
            secondMulti *= 10;
        }
    }


    numerator = numerator - denominator;
    denominator = firstMulti - secondMulti;

    ll gcd;
    if (numerator >= denominator) {
        gcd = GCD(numerator, denominator);
    }
    else {
        gcd = GCD(denominator, numerator);
    }

    if (gcd > 1) {
        numerator /= gcd;
        denominator /= gcd;
    }
    
    cout << numerator << "/" << denominator << endl;
        
    return (0);
}