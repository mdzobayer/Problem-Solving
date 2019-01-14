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

struct Node {
    LLI num;
    string position;

    bool operator < (const Node & other) const {
        if (position.size() != other.position.size()) {
            return position.size() < other.position.size();
        }
        return position < other.position;
    }

};

Node nodes[300];

bool allPosValid(const set < string > &allPositions) {

    auto iter = allPositions.begin();
    for (iter; iter != allPositions.end(); ++iter) {
        if (*iter != "") {
            string wantedString = iter->substr(0, iter->size() - 1) ;
            if (allPositions.find(wantedString) == allPositions.end()) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    //FastRead
    //fRead("in.txt");

    set < string > allPositions;
    char firstBracket, comma;
    int pos, i;
    bool valid;
    while(cin >> firstBracket >> nodes[0].num >> comma >> nodes[0].position) {
        allPositions.clear();

        nodes[0].position = nodes[0].position.substr(0, nodes[0].position.size() - 1);

        allPositions.insert(nodes[0].position);
        pos = 1;
        valid = true;

        while(cin >> firstBracket, cin.peek() != ')') {
            cin >> nodes[pos].num >> comma >> nodes[pos].position;
            nodes[pos].position = nodes[pos].position.substr(0, nodes[pos].position.size() - 1);

            if (allPositions.find(nodes[pos].position) != allPositions.end()) {
                valid = false;
            }

            allPositions.insert (nodes[pos].position);
            ++pos;
        }

        cin.ignore();

        if (valid && allPosValid(allPositions)) {
            sort (nodes, nodes + pos);

            printf("%d",nodes[0].num);

            for (i = 1; i < pos; ++i) {
                printf(" %d", nodes[i].num);
            }
            printf("\n");
        }
        else {
            printf("not complete\n");
        }
    }


    return (0);
}
