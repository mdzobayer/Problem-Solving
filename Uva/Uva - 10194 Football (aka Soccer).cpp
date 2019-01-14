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

bool compName(string & s1, string & s2) {
    int i;
    string temp1 = "", temp2 = "";
    for (i = 0; i < s1.size(); ++i) {
        if (s1[i] >= 97 && s1[i] <= 122) temp1 += s1[i] - 32;
        else if (s1[i] >= 65 && s1[i] <= 90) temp1 += s1[i];
    }
    for (i = 0; i < s2.size(); ++i) {
        if (s2[i] >= 97 && s2[i] <= 122) temp2 += s2[i] - 32;
        else if (s2[i] >= 65 && s2[i] <= 90) temp2 += s2[i];
    }
    if (temp1 <= temp2) return true;
    return false;
}

class team {
public:
    int point, wins, i, goalDiff, goalScore, goalAgainst, played, ties, loss;
    string name, temp1, temp2;
    team() {
        name = "";
        point = wins = goalDiff = goalScore = goalAgainst = played = 0;
    }
    team(int po, int wi, int gd, int gs, int ga, int pl, int ti, int lo) {
        point = po;
        wins = wi;
        goalDiff = gd;
        goalScore = gs;
        goalAgainst = ga;
        played = pl;
        ties = ti;
        loss = lo;
    }
    void modify(string s) {
        name = s;
        ties = loss = point = wins = goalDiff = goalScore = goalAgainst = played = 0;
    }
    bool operator < (team p) {
        if (this->point > p.point) return true;
        else if (this->point < p.point) return false;

        if (this->wins > p.wins) return true;
        else if (this->wins < p.wins) return false;

        if (this->goalDiff > p.goalDiff) return true;
        else if (this->goalDiff < p.goalDiff) return false;

        if (this->goalScore > p.goalScore) return true;
        else if (this->goalScore < p.goalScore) return false;
        if (this->played < p.played) return true;
        else if (this->played > p.played) return false;
        return compName(this->name, p.name);
    }
    void operator = (team p) {
        this->point = p.point;
        this->wins = p.wins;
        this->goalDiff = p.goalDiff;
        this->goalScore = p.goalScore;
        this->goalAgainst = p.goalAgainst;
        this->played = p.played;
        this->ties = p.ties;
        this->loss = p.loss;
        this->name = p.name;
    }
};




void print(team t) {
    printf("%d %d %d %d %d %s\n", t.point, t.wins,
           t.goalDiff, t.goalScore,
           t.played, t.name.c_str());
}
int main() {
    //FastRead

    //fRead("in.txt");
    //fWrite("out.txt");

    team tempTeam;
    map<string , int> identity;
    vector<team> vt;
    bool isSpace;
    int tournament, teams, i, j, matchs, id, result1, result2, t = 1;
    string tournamentName, s, team1, team2;
    cin >> tournament;
    cin.ignore();
    while ( tournament-- ) {

        getline(cin, tournamentName);

        identity.clear();
        vt.clear();

        id = 0;
        cin >> teams;
        cin.ignore();
        for (i = 0; i < teams; ++i) {
            getline(cin, s);
            identity[s] = i;
            tempTeam.modify(s);
            vt.phb(tempTeam);
        }
        cin >> matchs;
        cin.ignore();
        for (i = 0; i < matchs; ++i) {
            getline(cin, s);
            //cout << s << " " << matchs << endl;
            isSpace = false;
            for (j = 0; j < s.size(); ++j) {
                if (s[j] == ' ') {
                    s[j] = '#';
                    isSpace = true;
                }
                else if (s[j] == '#' || s[j] == '@') s[j] = ' ';
            }
            //cout << s << endl;
            stringstream ss(s);

            ss >> team1;
            ss >> result1;
            ss >> result2;
            ss >> team2;

            //cout << team1 << " " << result1 << " " << result2 << " " << team2 << endl;



            if (isSpace) {
                for (j = 0; j < team1.size(); ++j) {
                    if (team1[j] == '#')
                        team1[j] = ' ';
                }
                for (j = 0; j < team2.size(); ++j) {
                    if (team2[j] == '#')
                        team2[j] = ' ';
                }
            }
            if (result1 == result2) {
                id = identity[team1];
                vt[id].played += 1;
                vt[id].goalScore += result1;
                vt[id].goalAgainst += result1;
                vt[id].point += 1;
                vt[id].ties += 1;

                id = identity[team2];
                vt[id].played += 1;
                vt[id].goalScore += result1;
                vt[id].goalAgainst += result1;
                vt[id].point += 1;
                vt[id].ties += 1;
            }
            else if (result1 > result2) {
                id = identity[team1];
                vt[id].played += 1;
                vt[id].goalScore += result1;
                vt[id].goalAgainst += result2;
                vt[id].point += 3;
                vt[id].wins += 1;
                vt[id].goalDiff += result1;
                vt[id].goalDiff -= result2;

                id = identity[team2];
                vt[id].played += 1;
                vt[id].goalScore += result2;
                vt[id].goalAgainst += result1;
                vt[id].goalDiff += result2;
                vt[id].goalDiff -= result1;
                vt[id].loss += 1;
            }
            else {
                id = identity[team2];
                vt[id].played += 1;
                vt[id].goalScore += result2;
                vt[id].goalAgainst += result1;
                vt[id].point += 3;
                vt[id].wins += 1;
                vt[id].goalDiff += result2;
                vt[id].goalDiff -= result1;



                id = identity[team1];
                vt[id].played += 1;
                vt[id].goalScore += result1;
                vt[id].goalAgainst += result2;
                vt[id].goalDiff += result1;
                vt[id].goalDiff -= result2;
                vt[id].loss += 1;
            }

        }
        //cout << "Before Sort" << endl;
        sort(vt.begin(), vt.end());
        if (t > 1) cout << endl;
        ++t;
        cout << tournamentName << endl;
        for (i = 0; i < vt.size(); ++i) {
//              print(vt[i]);
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   i+1, vt[i].name.c_str(), vt[i].point,
                   vt[i].played, vt[i].wins, vt[i].ties,
                   vt[i].loss, vt[i].goalDiff, vt[i].goalScore,
                   vt[i].goalAgainst);
        }
    }


    return (0);
}
