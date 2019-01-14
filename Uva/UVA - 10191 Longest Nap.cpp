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

using namespace std;

class appointment {
public:
    int Start, End;
    bool operator < (appointment a) {
        if (this->Start < a.Start) {
            return true;
        }
        return false;
    }
    appointment() {
        Start = 0;
        End = 0;
    }
    void modify(int s, int e) {
        Start = s;
        End = e;
    }
    void setStart(int s) {
        Start = s;
    }
    void setEnd(int e) {
        End = e;
    }
    void operator = (appointment a) {
        this->Start = a.Start;
        this->End = a.End;
    }
};

class Nap{
public:
    int Start, duration;
    Nap() {
        Start = 0;
        duration = 0;
    }
    void modify(int s, int d) {
        Start = s;
        duration = d;
    }
    bool operator < (Nap n) {
        if (this->duration > n.duration) {
            return true;
        }
        else if (this->duration < n.duration)
            return false;
        if (this->Start <= n.Start)
            return true;
        return false;
    }
    void operator = (Nap a) {
        this->Start = a.Start;
        this->duration = a.duration;
    }
};

int main() {

    //fRead("in.txt");

    appointment temp;
    Nap tempN;
    vector<appointment> ap;
    vector<Nap> np;

    int task, i, hour, minit, preEnd, day = 0, result, remain;
    string s;
    while(cin >> task) {
        ap.clear();
        np.clear();
        for (i = 0; i < task; ++i) {
            scanf("%d:%d", &hour, &minit);
            hour *= 60;
            hour += minit;
            temp.setStart(hour);
            scanf("%d:%d", &hour, &minit);
            hour *= 60;
            hour += minit;
            temp.setEnd(hour);
            getline(cin, s);
            ap.push_back(temp);
        }
        sort(ap.begin(), ap.end());
        preEnd = 600;
        for (i = 0; i < ap.size(); ++i) {
            if (ap[i].Start - preEnd > 0) {
                tempN.modify(preEnd, ap[i].Start - preEnd);
                np.phb(tempN);

            }
            preEnd = ap[i].End;
        }
        if (1080 - preEnd > 0) {
            tempN.modify(preEnd, 1080 - preEnd);
            np.phb(tempN);
        }
        sort(np.begin(), np.end());
        printf("Day #%d: the longest nap starts at ", ++day);
        remain = np[0].Start % 60;
        result = np[0].Start / 60;
        printf("%d:", result);
        if (remain < 10)
            printf("0%d",remain);
        else
            printf("%d", remain);
        printf(" and will last for ", result, remain);
        remain = np[0].duration % 60;
        result = np[0].duration / 60;
        if (result == 0) {
            printf("%d minutes.\n", remain);
        }
        else {
            printf("%d hours and %d minutes.\n", result, remain);
        }

    }

    return (0);
}
