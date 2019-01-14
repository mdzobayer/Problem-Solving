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
/// C Style Input Short-Cut
#define scan(a) scanf("%d", &a);
#define scan2(a, b) scanf("%d %d", &a, &b);
#define scan3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define scan4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/// Utility
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

struct number {

    string str;
    number() {
        str = "";
    }
    number(string s) {
        str = s;
    }
    char AT(size_t a) {
        return str[a];
    }
    void operator = ( number n) {
        this->str = n.str;
    }
    size_t size() {
        return str.size();
    }
    bool operator < ( number x) {
        if (this->str == x.str) return false;
        size_t n = min(this->size(), x.size());
        for (size_t i = 0; i < n; ++i) {
            if (this->AT(i) >= x.AT(i)) return true;
            else if(x.AT(i) < this->AT(i)) return false;
        }
        if (this->size() == n) return true;
        else return false;
    }
};

int main() {
    FastRead
    fRead("in.txt");
    //fWrite("out.txt");

    vector <number> nt;

    number temp;
/*
    temp.str = "123";
    nt.phb(temp);
    temp.str = "124";
    nt.phb(temp);
    temp.str = "56";
    nt.phb(temp);
    temp.str = "90";
    nt.phb(temp);
    temp.str = "9";
    nt.phb(temp);

    sort(nt.begin(), nt.end());
    for (int i = 0; i < nt.size(); ++i) {
        cout << nt[i].str << " ";
    }
*/
    string s;
    LLI n, i;
    while(cin >> n) {
        if (n == 0) break;
        nt.clear();
        cin.ignore();
        for (i = 0; i < n; ++i) {
            cin >> s;
            temp.str = s;
            nt.phb(temp);
        }
        sort(nt.begin(), nt.end());
        for (i = 0; i < nt.size(); ++i) {
            cout << nt[i].str;
        }
        cout << endl;
    }

    return (0);
}
