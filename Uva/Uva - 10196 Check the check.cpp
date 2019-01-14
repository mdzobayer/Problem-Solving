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

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x > 7 || y > 7) return false;
    return true;
}

bool isNull(string str[]) {
    if (str[0] == "........" &&
        str[1] == "........" &&
        str[2] == "........" &&
        str[3] == "........" &&
        str[4] == "........" &&
        str[5] == "........" &&
        str[6] == "........" &&
        str[7] == "........" ) return true;
    return false;
}

bool isKnight (string & str[], int x, int y, bool king) {
    if (isValid(x - 2, y - 1)) {
        if (king) {
            if (str[x - 2][y - 1] == 'n') {
                return true;
            }
        }
        else {
            if (str[x - 2][y - 1] == 'n') {
                return true;
            }
        }
    }
    if (isValid(x - 2, y + 1)) {
        if (king) {
            if (str[x - 2][y + 1] == 'n') {
                return true;
            }
        }
        else {
            if (str[x - 2][y + 1] == 'N') {
                return true;
            }
        }
    }
    if (isValid(x + 2, y - 1)) {
        if (king) {
            if (str[x + 2][y - 1] == 'n') {
                return true;
            }
        }
        else {
            if (str[x + 2][y - 1] == 'N') {
                return true;
            }
        }
    }
    if (isValid(x + 2, y + 1)) {
        if (king) {
            if (str[x + 2][y + 1] == 'n') {
                return true;
            }
        }
        else {
            if (str[x + 2][y + 1] == 'N') {
                return true;
            }
        }
    }
    if (isValid(x - 1, y - 2)) {
        if (king) {
            if (str[x - 1][y - 2] == 'n') {
                return true;
            }
        }
        else {
            if (str[x - 1][y - 2] == 'N') {
                return true;
            }
        }
    }
    if (isValid(x + 1, y - 2)) {
        if (king) {
            if (str[x + 1][y - 2] == 'n') {
                return true;
            }
        }
        else {
            if (str[x + 1][y - 2] == 'N') {
                return true;
            }
        }
    }
    if (isValid(x + 1, y + 2)) {
        if (king) {
            if (str[x + 1][y + 2] == 'n') {
                return true;
            }
        }
        else {
            if (str[x + 1][y + 2] == 'N') {
                return true;
            }
        }
    }
    if (isValid(x - 1, y + 2)) {
        if (king) {
            if (str[x - 1][y + 2] == 'n') {
                return true;
            }
        }
        else {
            if (str[x - 1][y + 2] == 'N') {
                return true;
            }
        }
    }

    return false;
}

bool isRook(string & str[], int x, int y, bool king) {
    int i;
    char ch;
    if (king) {
        ch = 'r';
    }
    else {
        ch = 'R';
    }
    for (i = y + 1; i < 8; ++i) {
        if (str[x][i] == ch) return true;
        else if (str[x][i] != '.') break;
    }
    for (i = y - 1; i >= 0; --i) {
        if (str[x][i] == ch) return true;
        else if (str[x][i] != '.') break;
    }
    for (i = x + 1; i < 8; ++i) {
        if (str[i][y] == ch) return true;
        else if (str[i][y] != '.') break;
    }
    for (i = x - 1; i >= 0; --i) {
        if (str[i][y] == ch) return true;
        else if (str[i][y] != '.') break;
    }

    return false;
}

bool isBishop(string & str[], int x, int y, bool king) {
    char ch;
    if (king) {
        ch = 'b';
    }
    else {
        ch = 'B';
    }
    int i;
    for (i = 1; x - i >= 0 && y - i >= 0; ++i) {
        if (str[x - i][y - i] == ch) {
            return true;
        }
        else if (str[x - i][y - i] != '.')
            return false;
    }
    for (i = 1; x - i >= 0 && y + i < 8; ++i) {
        if (str[x - i][y + i] == ch) {
            return true;
        }
        else if (str[x - i][y + i] != '.')
            return false;
    }
    for (i = 1; x + i < 8 && y - i >= 0; ++i) {
        if (str[x + i][y - i] == ch) {
            return true;
        }
        else if (str[x + i][y - i] != '.')
            return false;
    }
    for (i = 1; (x + i < 8) && (y + i < 8); ++i) {
        if (str[x + i][y + i] == ch) {
            return true;
        }
        else if (str[x + i][y + i] != '.')
            return false;
    }

    return false;
}

bool isQueen(string & str[], int x, int y, bool king) {
    int i;
    char ch;
    if (king) {
        ch = 'q';
    }
    else {
        ch = 'Q';
    }
    /// Check like as Rock
    for (i = y + 1; i < 8; ++i) {
        if (str[x][i] == ch) return true;
        else if (str[x][i] != '.') break;
    }
    for (i = y - 1; i >= 0; --i) {
        if (str[x][i] == ch) return true;
        else if (str[x][i] != '.') break;
    }
    for (i = x + 1; i < 8; ++i) {
        if (str[i][y] == ch) return true;
        else if (str[i][y] != '.') break;
    }
    for (i = x - 1; i >= 0; --i) {
        if (str[i][y] == ch) return true;
        else if (str[i][y] != '.') break;
    }

    /// Check like Bisop
    for (i = 1; x - i >= 0 && y - i >= 0; ++i) {
        if (str[x - i][y - i] == ch) {
            return true;
        }
        else if (str[x - i][y - i] != '.')
            return false;
    }
    for (i = 1; x - i >= 0 && y + i < 8; ++i) {
        if (str[x - i][y + i] == ch) {
            return true;
        }
        else if (str[x - i][y + i] != '.')
            return false;
    }
    for (i = 1; x + i < 8 && y - i >= 0; ++i) {
        if (str[x + i][y - i] == ch) {
            return true;
        }
        else if (str[x + i][y - i] != '.')
            return false;
    }
    for (i = 1; (x + i < 8) && (y + i < 8); ++i) {
        if (str[x + i][y + i] == ch) {
            return true;
        }
        else if (str[x + i][y + i] != '.')
            return false;
    }

    return false;
}

bool isKing(string & str[], int x, int y) {
    if (isValid(x - 1, y - 1)) {
        if (str[x - 1][y - 1] == 'k' || str[x - 1][y - 1] == 'K')
            return true;
    }
    if (isValid(x - 1, y)) {
        if (str[x - 1][y] == 'k' || str[x - 1][y] == 'K')
            return true;
    }
    if (isValid(x - 1, y + 1)) {
        if (str[x - 1][y + 1] == 'k' || str[x - 1][y + 1] == 'K')
            return true;
    }
    if (isValid(x, y - 1)) {
        if (str[x][y - 1] == 'k' || str[x][y - 1] == 'K')
            return true;
    }
    if (isValid(x, y + 1)) {
        if (str[x][y + 1] == 'k' || str[x][y + 1] == 'K')
            return true;
    }
    if (isValid(x + 1, y + 1)) {
        if (str[x + 1][y + 1] == 'k' || str[x + 1][y + 1] == 'K')
            return true;
    }
    if (isValid(x + 1, y)) {
        if (str[x + 1][y] == 'k' || str[x + 1][y] == 'K')
            return true;
    }
    if (isValid(x + 1, y - 1)) {
        if (str[x + 1][y - 1] == 'k' || str[x + 1][y - 1] == 'K')
            return true;
    }

    return false;
}

bool isPawn(string & str[], int x, int y, bool king) {
    char ch;
    if (king) {
        ch = 'p';
        if (isValid(x - 1, y - 1)) {
            if (str[x - 1][y - 1] == ch) return true;
        }
        if (isValid(x - 1, y + 1)) {
            if (str[x - 1][y + 1] == ch) return true;
        }
    }
    else {
        ch = 'P';
        if (isValid(x + 1, y - 1)) {
            if (str[x + 1][y - 1] == ch) return true;
        }
        if (isValid(x + 1, y + 1)) {
            if (str[x + 1][y + 1] == ch) return true;
        }
    }
    return false;
}

int main() {
    FastRead

    string str[10];

    while(cin >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> str[5] >> str[6] >> str[7]) {
        if (isNull(str)) break;
        cin >> str[8];

    }


    return (0);
}
