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

bool comp(const int &a,const int &b) {
    return a > b;
}
int main() {
    //FastRead
    bool isUse1[60], isUse2[60];
    int arr1[55], arr2[55], n, test, t, i, j, score;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);

        memset(isUse1, true, sizeof(isUse1));
        memset(isUse2, true, sizeof(isUse2));
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr1[i]);
        }
        for (i = 0; i < n; ++i) {
            scanf("%d", &arr2[i]);
        }
        sort (arr1, arr1+n);
        sort (arr2, arr2+n, comp);

        score = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                if (isUse1[j] && arr1[j] > arr2[i]) {
                    score += 2;
                    isUse1[j] = false;
                    isUse2[i] = false;
                    break;
                }
            }
        }
//        cout << score << endl;
//        for (i = 0; i < n; ++i) {
//            printf("%d ", isUse1[i]);
//        }
//        printf("\n");
//        for (i = 0; i < n; ++i) {
//            printf("%d ", isUse2[i]);
//        }
//        printf("\n");
        for (i = 0; i < n; ++i) {
            if(isUse2[i]) {
                for (j = 0; j < n; ++j) {
                    if (isUse1[j] && arr1[j] == arr2[i]) {
                        score += 1;
                        isUse1[j] = false;
                        isUse2[i] = false;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n", t, score);

    }

    return (0);
}
