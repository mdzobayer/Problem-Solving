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

int main() {
    //FastRead
    //fRead("in.txt");
    //fWrite("out.txt");

    string s1, s2;
    int i, j, arr[130], arr1[130], x;
    while(getline(cin,s1)) {
        getline(cin, s2);

        //cout << s1 << " " << s2 << endl;

        memset(arr, 0, sizeof(arr));
        memset(arr1, 0, sizeof(arr1));
        for (i = 0; i < s1.size(); ++i) {
            ++arr[s1[i]];
        }

        for (i = 0; i < s2.size(); ++i) {
            ++arr1[s2[i]];
        }
        //cout << "Debug 2" << endl;
        for (i = 90; i < 130; ++i) {
            x = min(arr1[i], arr[i]);
            //printf("Comp %d %d\n", arr1[i], arr[i]);
            if ( x > 0) {

                for (j = 0; j < x; ++j)
                    printf("%c", i);
            }
        }
        printf("\n");
    }

    return (0);
}
