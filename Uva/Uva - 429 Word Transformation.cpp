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


vector < string > dic;
int dicLength;
bool visited[200+10];

struct node {
    string str;
    int level;

    node (string s, int l) {
        str = s;
        level = l;
    }
    node(){
    };
};

queue < node > q;

bool isOneDiff(string a, string b) {
    if (a.length() != b.length()) return false;
    int cnt = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) ++cnt;
        if (cnt > 1) return false;
    }
    if (cnt = 0) return false;
    return true;
}
void pushValue (node p) {
    for (int i = 0; i < dicLength; ++i) {
        if (!visited[i]) {
            if (isOneDiff(p.str, dic[i])){
                visited[i] = true;
                q.push(node(dic[i], p.level+1));
            }
        }
    }
}

int bfs(string a, string b) {
    node tmp;

    while(!q.empty())
        q.pop();

    q.push(node(a, 0));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < dicLength; ++i) {
        if (a == dic[i]) {
            visited[i];
            break;
        }
    }

    while(!q.empty()) {
        tmp = q.front();
        q.pop();
        //cout << "tmpStr = " << tmp.str << endl;
        if (tmp.str == b) return tmp.level;
        pushValue(tmp);
    }
}

int main() {
    //FastRead

    //fRead("in.txt");

    string s, st, en;
    int test, result, bLink = 0;
    cin >> test;
    cin.ignore();
    getline(cin, s);
    while(test--) {
        dic.clear();
        while(getline(cin, s)) {
            if (s == "*") break;
            dic.push_back(s);
        }
        dicLength = dic.size();

        if (bLink > 0) printf("\n");
        ++bLink;

        while(getline(cin, s)) {
            if (s == "") break;
            stringstream ss(s);
            ss >> st;
            ss >> en;
            //cout << "Debug " << dicLength << endl;
            result = bfs(st, en);

            printf("%s %s %d\n", st.c_str(), en.c_str(), result);
        }

    }


    return (0);
}
