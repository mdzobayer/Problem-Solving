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
//bool sevenSegment[8][10] =
//{
//    {0,0,0,0,0,0,0,0,0,0}, ///Segment 0
//    {1,0,1,1,0,1,1,1,1,1}, ///Segment 1
//    {1,1,1,1,1,0,0,1,1,1}, ///Segment 2
//    {1,1,0,1,1,1,1,1,1,1}, ///Segment 3
//    {1,0,1,1,0,1,1,0,1,1}, ///Segment 4
//    {1,0,1,0,0,0,1,0,1,0}, ///Segment 5
//    {1,0,0,0,1,1,1,0,1,1}, ///Segment 6
//    {0,0,1,1,1,1,1,0,1,1}  ///Segment 7
//};
/// Fast Read and de-active buffer flash for C++
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(NULL);

///======================== Let's GO ========================

string intRev(int x) {
    string s = "";
    while(x > 0) {
        s += (x % 10) + '0';
        x /= 10;
    }
    return s;
}

int main() {
    //FastRead
    //fRead("in.txt");
    //fWrite("out.txt");
    char ch;
    int i, x;
    string str, output;
    while(getline(cin, str)) {
        output = "";
        ch = str[0];
        if (ch >= '0' && ch <= '9') {
            for (i = str.size() - 1; i >= 0; i -= 2) {
                x = str[i] - '0';
                x *= 10;
                x += str[i - 1] - '0';
                if (x < 32 && i > 1) {
                    x *= 10;
                    x += str[i - 2] - '0';
                    --i;
                }
                printf("%c", x);
            }
            printf("\n");
        }
        else {
            for (i = str.size() - 1; i >= 0; --i) {
                x = (int) str[i];
                output += intRev(x);
            }
            cout << output << endl;
        }

    }

    return (0);
}
