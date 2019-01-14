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

//int dir [2][8] = {{-1,0,0,1,-1,-1,1,1},
//                  {0,-1,1,0,-1,1,1,-1}};

//int knight[2][8] = {{-2,-2,-1,1,2,2,1,-1},
//                    {-1,1,2,2,1,-1,-2,-2}};

/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================
bool sevenSegment[8][10] =
{
    {0,0,0,0,0,0,0,0,0,0}, ///Segment 0
    {1,0,1,1,0,1,1,1,1,1}, ///Segment 1
    {1,1,1,1,1,0,0,1,1,1}, ///Segment 2
    {1,1,0,1,1,1,1,1,1,1}, ///Segment 3
    {1,0,1,1,0,1,1,0,1,1}, ///Segment 4
    {1,0,1,0,0,0,1,0,1,0}, ///Segment 5
    {1,0,0,0,1,1,1,0,1,1}, ///Segment 6
    {0,0,1,1,1,1,1,0,1,1}  ///Segment 7
};
void printChar(int n, char ch) {
    for (int i = 0; i < n; ++i) {
        putchar(ch);
    }
}
int main() {
    FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    int n, i, j, digit;
    string s;
    while(cin >> n) {
        cin >> s;
        if (n == 0 && s == "0") break;
        /// Part 1
        for (i = 0; i < s.size(); ++i) {
            digit = s[i] - '0';
            if (i > 0) printChar(3, ' ');
            else putchar(' ');
            if (sevenSegment[1][digit])
                printChar(n,'-');
            else printChar(n, ' ');
        }
        putchar(' ');
        putchar('\n');
        /// Part 2
        for (j = 0; j < n; ++j) {
            for (i = 0; i < s.size(); ++i) {
                digit = s[i] - '0';
                if (i > 0) putchar(' ');
                if (sevenSegment[6][digit])
                    putchar('|');
                else
                    putchar(' ');

                printChar(n, ' ');

                if (sevenSegment[2][digit])
                    putchar('|');
                else
                    putchar(' ');
            }
            putchar('\n');
        }
        ///Part 3
        for (i = 0; i < s.size(); ++i) {
            digit = s[i] - '0';
            if (i > 0) printChar(3, ' ');
            else putchar(' ');
            if (sevenSegment[7][digit])
                printChar(n,'-');
            else printChar(n, ' ');
        }
        putchar(' ');
        putchar('\n');
        ///Part 4
        for (j = 0; j < n; ++j) {
            for (i = 0; i < s.size(); ++i) {
                digit = s[i] - '0';
                if (i > 0) printChar(1, ' ');
                if (sevenSegment[5][digit])
                    putchar('|');
                else
                    putchar(' ');

                printChar(n, ' ');

                if (sevenSegment[3][digit])
                    putchar('|');
                else
                    putchar(' ');
            }
            putchar('\n');
        }
        /// Part 5
        for (i = 0; i < s.size(); ++i) {
            digit = s[i] - '0';
            if (i > 0) printChar(3, ' ');
            else putchar(' ');
            if (sevenSegment[4][digit])
                printChar(n,'-');
            else printChar(n, ' ');
        }
        putchar(' ');
        putchar('\n'); putchar('\n');
    }

    return (0);
}

