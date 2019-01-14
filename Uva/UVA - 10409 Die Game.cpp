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
#define FastRead std::cin.sync_with_stdio(false);std::cin.tie(nullptr);

///======================== Let's GO ========================


struct die{
    int top, north, east, west, south, bottom;
    void operator = (die x) {
        this->top = x.top;
        this->west = x.west;
        this->north = x.north;
        this->east = x.east;
        this->south = x.south;
        this->bottom = x.bottom;
    }
};
void setIni(struct die & x) {
    x.top = 1;
    x.west = 3;
    x.north = 2;
    x.east = 4;
    x.south = 5;
    x.bottom = 6;
}
struct die North(struct die x) {
    struct die temp = x;
    temp.top = x.south;
    temp.south = x.bottom;
    temp.north = x.top;
    temp.bottom = x.north;
    return temp;
}
struct die South(struct die x) {
    struct die temp = x;

    temp.top = x.north;
    temp.south = x.top;
    temp.bottom = x.south;
    temp.north = x.bottom;
    return temp;
}
struct die West(struct die x) {
    struct die temp = x;

    temp.top = x.east;
    temp.east = x.bottom;
    temp.bottom = x.west;
    temp.west = x.top;
    return temp;
}
struct die East(struct die x) {
    struct die temp = x;

    temp.top = x.west;
    temp.west = x.bottom;
    temp.bottom = x.east;
    temp.east = x.top;
    return temp;
}

int main() {
    FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    string s;

    struct die dice;
    int n, i;
    while(cin >> n) {
        if (n == 0) break;
        cin.ignore();
        setIni(dice);
        for (i = 0; i < n; ++i) {
            cin >> s;
            if (s == "north") {
                dice = North(dice);
            }
            else if (s == "east") {
                dice = East(dice);
            }
            else if (s == "south") {
                dice = South(dice);
            }
            else if (s == "west") {
                dice = West(dice);
            }
        }
        cout << dice.top << endl;
    }

    return (0);
}
