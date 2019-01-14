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
#define SWAP(a, b) a = a ^ b, b = a ^ b, a = a ^ b;
#define SQR(x) ((x) * (x))
#define PI acos(-1.0)
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================

/// Converting to standard form
string convert(string & random) {
    string standard = "";
    int i;
    for (i = 0; i < random.size(); ++i) {
        if (random[i] >= 'a' && random[i] <= 'z') {
            standard += random[i];
        }
        else if (random[i] >= 'A' && random[i] <= 'Z') {
            standard += (random[i] + 32);
        }
    }
    return standard;
}

int main() {
    FastRead

    //fRead("in.txt");

    set<string> dictonary;
    int i;
    string line, word, standard;
    while(getline(cin, line)) {
        for ( i = 0; i < line.size(); ++i) {
            if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')){
                continue;
            }
            else line[i] = ' ';
        }
        stringstream wordExtractor(line);
        while(wordExtractor >> word) {
            standard = convert(word);
            dictonary.insert(standard);
        }
    }
    set<string>::iterator it;
    for (it = dictonary.begin(); it != dictonary.end(); ++it) {
        cout << *it << endl;
    }

    return (0);
}
