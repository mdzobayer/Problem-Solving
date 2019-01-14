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

class contestant{
public:
    int id, penalty, solved, tempP, prob[12];
    contestant() {
        id = 0;
        penalty = 0;
        solved = 0;
        tempP = 0;
        memset(prob, 0, sizeof(prob));
    }
    void modify(int i, int p, int s, int tp) {
        id = i;
        penalty = p;
        solved = s;
        tempP = tp;
        memset(prob, 0, sizeof(prob));
    }
    void addTemp(int pId) {
        penalty += prob[pId];
        prob[pId] = -1;
    }
    void operator = (contestant c) {
        this->id = c.id;
        this->penalty = c.penalty;
        this->solved = c.solved;
        this->tempP = c.tempP;
    }
    bool operator < (contestant p) {
        if (this->solved > p.solved) return true;
        else if (this->solved < p.solved) return false;

        if (this->penalty < p.penalty) return true;
        else if (this->penalty > p.penalty) return false;

        return (this->id < p.id);
    }
};

int main() {
    FastRead

    fRead("in.txt");
    fWrite("out.txt");

    int test, x, y, z,i, id, tempInt, alreadyHave[110], t = 0;
    char ch;
    contestant temp;
    vector<contestant> vt;
    string s;
    cin >> test;
    cin.ignore();
    getline(cin, s);
    while(test--) {
        if (t > 0) printf("\n");
        ++t;
        vt.clear();
        memset(alreadyHave, -1, sizeof(alreadyHave));
        id = 0;
        while(getline(cin, s)) {
            if (s == "") break;
            stringstream ss(s);
            ss >> x >> y >> z;
            ss >> ch;
            if (alreadyHave[x] == -1) {
                alreadyHave[x] = id;
                ++id;
                temp.modify(x, 0, 0, 0);
                vt.phb(temp);
                //cerr << "I am here" << endl;
            }
            tempInt = alreadyHave[x];
            if (ch == 'C'){
                vt[tempInt].solved += 1;
                vt[tempInt].penalty += z;

                if (vt[tempInt].prob[y] != -1)
                    vt[tempInt].addTemp(y);
            }
            else if (ch == 'I') {
                if (vt[tempInt].prob[y] != -1)
                    vt[tempInt].prob[y] += 20;
            }
        }
        /// Output the test result
        sort(vt.begin(), vt.end());
        for (i = 0; i < vt.size(); ++i) {
            printf("%d %d %d\n",vt[i].id, vt[i].solved,
                   vt[i].penalty);
        }
    }


    return (0);
}
