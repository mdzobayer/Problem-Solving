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

struct position {
    int x, y;

    bool operator == (position p) {
        if (this->x != p.x) return false;
        if (this->y != p.y) return false;
        return true;
    }

    void operator = (position p) {
        this->x = p.x;
        this->y = p.y;
    }

    bool operator != (position p) {
        if (*this == p) return false;
        return true;
    }
};

int board[10][10];
bool isPossible(position p) {
    if (p.x < 1 || p.x > 8 || p.y < 1 || p.y > 8) return false;
    if (board[p.x][p.y] != 0) return false;

    return true;
}
void mark(position p, int n) {
    board[p.x][p.y] = n;
}

void makeMove(position &p, int xx, int yy) {
    p.x = xx;
    p.y = yy;
}
int main() {
    FastRead

    //fRead("in.txt");

    position Start, End, temp;
    char str[6];
    while(gets(str)) {
        memset(board, 0, sizeof(board));
        queue<position> q;
        Start.x = str[0] - 'a' + 1;
        Start.y = str[1] - '0';
        End.x = str[3] - 'a' + 1;
        End.y = str[4] - '0';

        mark(Start, 0);
        q.push(Start);
        while (Start != End) {
            Start = q.front();
            q.pop();
            /// Move 1;
            makeMove(temp, Start.x - 2, Start.y + 1);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
            /// Move 2;
            makeMove(temp, Start.x - 2, Start.y - 1);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
            /// Move 3;
            makeMove(temp, Start.x + 2, Start.y + 1);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
            /// Move 4;
            makeMove(temp, Start.x + 2, Start.y - 1);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
            /// Move 5;
            makeMove(temp, Start.x + 1, Start.y + 2);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
            /// Move 6;
            makeMove(temp, Start.x - 1, Start.y + 2);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
            /// Move 7;
            makeMove(temp, Start.x + 1, Start.y - 2);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
            /// Move 8;
            makeMove(temp, Start.x - 1, Start.y - 2);
            if (isPossible(temp)) {
                if (End == temp){
                    mark(temp, board[Start.x][Start.y] + 1);
                    break;
                }
                else {
                    mark(temp, board[Start.x][Start.y] + 1);
                    q.push(temp);
                }
            }
        }
        printf("To get from %c%c ", str[0], str[1]);
        printf("to %c%c ", str[3], str[4]);
        printf("takes %d knight moves.\n", board[End.x][End.y]);
    }

    return (0);
}
