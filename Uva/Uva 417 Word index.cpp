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

map<string, int> wordIndex;
int position = 0;
void createwordIndex(string s, int len) {
    if (s.size() == len) {
        wordIndex[s] = ++position;
        return;
    }
    char lastCharacter;
    if (s == "") {
        lastCharacter = 'a';
    }
    else {
        lastCharacter = s[s.size() - 1] + 1;
    }
    char a;
    for (a = lastCharacter; a <= 'z'; ++a) {
        createwordIndex(s+a, len);
    }
}

int main() {
    FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    int i;
    string str;
    for (i = 1; i < 6; ++i) {
        //cout << "i here" << endl;
        createwordIndex("", i);
        //cout << "i am here" << endl;
    }

    while(cin >> str) {
        if (wordIndex.find(str) != wordIndex.end()) {
            cout << wordIndex[str] << endl;
        }
        else {
            cout << '0' << endl;
        }
    }

    return (0);
}
