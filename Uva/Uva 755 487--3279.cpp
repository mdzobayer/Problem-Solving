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

char mapping(char ch) {
    if (ch == 'A' || ch == 'B' || ch == 'C') {
        return '2';
    }
    else if (ch == 'D' || ch == 'E' || ch == 'F') {
        return '3';
    }
    else if (ch == 'G' || ch == 'H' || ch == 'I') {
        return '4';
    }
    else if (ch == 'J' || ch == 'K' || ch == 'L') {
        return '5';
    }
    else if (ch == 'M' || ch == 'N' || ch == 'O') {
        return '6';
    }
    else if (ch == 'P' || ch == 'R' || ch == 'S') {
        return '7';
    }
    else if (ch == 'T' || ch == 'U' || ch == 'V') {
        return '8';
    }
    else if (ch == 'W' || ch == 'X' || ch == 'Y') {
        return '9';
    }
    else return ch;
}


int main() {
    FastRead
    //fRead("in.txt");

    LLI test, t = 0, i, j, n;
    bool isDuplicate;
    string s, processing;
    map<string, int> numbers;
    cin >> test;
    while(test--) {
        if (t > 0) cout << endl;
        ++t;
        numbers.clear();
        cin >> n;
        cin.ignore();
        for (j = 0; j < n; ++j) {
            processing = "";
            getline(cin, s);
            for (i = 0; i < s.size(); ++i) {
                if (processing.size() == 3) processing += '-';
                if (s[i] != '-'){
                    processing += mapping(s[i]);
                }
            }
            isDuplicate = false;
            //cout << processing << endl;
            if (numbers.find(processing) != numbers.end()) {
                numbers[processing] += 1;
            }
            else {
                numbers[processing] = 1;
            }

        }
        for (map<string, int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
            if (it->ss > 1) {
                cout << it->ff << " " << it->ss << endl;
                isDuplicate = true;
            }
        }
        if (isDuplicate == false) {
            cout << "No duplicates." << endl;
        }
    }

    return (0);
}
