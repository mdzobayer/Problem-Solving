#include <bits/stdc++.h>
using namespace std;

/// Read & Write to File Short-Cut
#define fRead(x) freopen(x, "r", stdin)
#define fWrite(x) freopen(x, "w", stdout)
/// Data type Short-Cut
#define LLI long long int
#define ULL unsigned long long int
#define ff first
#define ss second
#define mk make_pair
#define phb push_back
#define ppb pop_back
#define phf push_front
#define ppf pop_front
/// Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash
#define FastRead std::ios::sync_with_stdio(false);cin.tie(NULL);

///======================== Let's GO ========================

string rev(const string & a){
    int i, j;
    string b = "";
    for(i = 0,j = a.length() - 1; i < a.length(); i++, j--)
        b += a[j];

    return b;
}
string add(string e, char f){
    int i, j, x, y, sum, s;
    string c = "";
    string a, d;
    int temp = 0;
    a = rev(e);
    x = a[0] - '0';
    y = f - '0';
    sum = x + y;
    s = sum % 10;
    c += s + '0';
    if(sum > 9) temp = 1;

    for(i = 1; i < a.length(); i++)
    {
        if (temp > 0) {
            x = a[i] - '0';
            sum = x + temp;
            s = sum % 10;
            c += s + '0';
            temp = 0;
            y = 0;
            if(sum > 9) temp = 1;
        }
        else {
            c += a[i];
        }
    }
    if (temp > 0)
        c += temp + '0';

    d = rev(c);
    return d;
}

int main() {
    FastRead
    int cnnt = 0;
    string str,sum = "0", temp;
    ULL n;
    cin >> n;
    cin.ignore();
    cin >> str;

    label:
    ++cnnt;
    temp = "";
    for (size_t i = 0; i < str.size(); ++i) {
        temp += str[i];
        if (i < str.size() - 1) {
            temp += '+';
        }
        sum = add(sum, str[i]);
    }
    cout << temp << endl;
    if (cnnt < 3) {
        str = sum;
        sum = "0";
        goto label;
    }

    return (0);
}
