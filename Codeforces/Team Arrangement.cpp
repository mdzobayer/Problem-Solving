#include <bits/stdc++.h>

using namespace std;

class player {
public:
    string name;
    string role;
    int number, expe;
    player() {
        name = "";
        role = "";
        number = 0;
        expe = 0;
    }
    void modify(string nu, string ro, int nm, int ex) {
        name = nu;
        role = ro;
        number = nm;
        expe = ex;
    }
    bool operator < (player p) {
        if (this->number != p.number) return this->number < p.number;

        return false;
    }
    void operator = (player p) {
        this->name = p.name;
        this->number = p.number;
        this->role = p.role;
        this->expe = p.expe;
    }
};
int stringtoINT(string s)
{
    int i,j=1,tmp=0;
    for(i=s.size()-1;i<s.size();i++)
    {
        tmp+=(s[i]-'0')*j;
        j*=10;
    }
    return tmp;
}

int exprice_count(string s)
{
    string s1,s2;
    int i,j=0;
    for(i=0;i<s.size();i++)
    {
        if(s[i]=='-')
        {
            j=1;
            continue;
        }
        if(j)
        {
            s1.push_back(s[i]);
        }
        else
            s2.push_back(s[i]);
    }
    return abs(stringtoINT(s1)-stringtoINT(s2));
}
int duration(string str) {
    string s1 = "", s2 = "";
    bool flag = false;
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '-') {
            flag = true;
            continue;
        }
        if (flag == false) {
            s1 += str[i];
        }
        else {
            s2 += str[i];
        }
    }
    int x, y;
    x = atoi(s1.c_str());
    y = atoi(s2.c_str());

    return abs(y - x) + 1;
}

int main() {

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);



    player temP;
    string s, nam, ro, pTime;
    int num, ex, i, strike, midfield, defence, t = 0;
    //cout << "Here 1" << endl;
    while(getline(cin, s)) {
        //cout << "first s= "<<s << endl;
        if (s == "0") break;
        if (s == "") continue;
        if (t > 0) cout << endl;
        ++t;
        /// Clear memory
        vector < player > mid;
        vector < player > defender;
        vector < player > striker;
        vector < player > keeper;
        vector < player > team;
        //cout << "Crash 1" << endl;
        stringstream ss(s);
        ss >> num;
        ss >> nam;
        ss >> ro;
        ex = 0;
        //cout << "Test = " << num << " " << nam << " " << ro << endl;
        while(ss >> pTime) {
            ex += duration(pTime);
        }
        temP.modify(nam, ro, num, ex);
        if (ro == "M") {
            mid.push_back(temP);
        }
        else if (ro == "D") {
            defender.push_back(temP);
        }
        else if (ro == "S") {
            striker.push_back(temP);
        }
        else if (ro == "G") {
            keeper.push_back(temP);
        }
        //cout << "Crash 2" << endl;
        for (i = 0; i < 21; ++i) {
            //cout << "21 input = " << s << endl;
            getline(cin, s);
            stringstream ss(s);
            ss >> num;
            ss >> nam;
            ss >> ro;
            ex = 0;
            //cout << "Test = " << num << " " << nam << " " << ro << endl;
            while(ss >> pTime) {
                //cout << "pTime = " << pTime << endl;
                ex += duration(pTime);
                //cout << "Ex = " << ex << endl;
            }
            temP.modify(nam, ro, num, ex);
            if (ro == "M") {
                mid.push_back(temP);
            }
            else if (ro == "D") {
                defender.push_back(temP);
            }
            else if (ro == "S") {
                //cout << "\t\tStriker pushed " << endl;
                striker.push_back(temP);
            }
            else if (ro == "G") {
                keeper.push_back(temP);
            }
        }
        /// Team format

        getline(cin, s);
        //cout << "Team format = " << s << endl;
        for (i = 0; i < s.size(); ++i) {
            if (s[i] == '-') s[i] = ' ';
        }
        stringstream sss(s);
        sss >> defence;
        sss >> midfield;
        sss >> strike;
        //cout << "Team : " << defence << " " << midfield << " " << strike << endl;
        /// Checking
        if (keeper.size() == 0) {
            cout << "IMPOSSIBLE TO ARRANGE" << endl;
            break;
        }
        else if (defender.size() == 0 || defender.size() < defence) {
            cout << "IMPOSSIBLE TO ARRANGE" << endl;
            break;
        }
        else if (striker.size() == 0 || striker.size() < strike) {
            cout << "IMPOSSIBLE TO ARRANGE" << endl;
            break;
        }
        else if (mid.size() == 0 || mid.size() < midfield) {
            cout << "IMPOSSIBLE TO ARRANGE" << endl;
            break;
        }
        //cout << "Before sort " << endl;
        /// Sort
        sort(mid.begin(), mid.end());
        //cout << "Got crushed" << endl;
        sort(striker.begin(), striker.end());

        sort(defender.begin(), defender.end());
        sort(keeper.begin(), keeper.end());

        //team.clear();

        team.push_back(keeper[0]); /// Push Keeper
        int cIndex = 0, cEx = keeper[0].expe, cNum = keeper[0].number;
        //cout << "Keeper : " << keeper[0].expe << endl;

        for (i = 0; i < defence; ++i) {
            team.push_back(defender[i]);
            //cout << "defender : " << defender[i].expe << endl;
            if (cEx < defender[i].expe) {
                cEx = defender[i].expe;
                cIndex = team.size() - 1;
                cNum = defender[i].number;
            }
            else if (cEx == defender[i].expe) {
                if (cNum < defender[i].number) {
                    cNum = defender[i].number;
                    cIndex = team.size() - 1;
                }
            }
            //cout << "cExp : " << cEx << endl;
        }
        for (i = 0; i < midfield; ++i) {
            team.push_back(mid[i]);
            //cout << "mid : " << mid[i].expe << endl;
            if (cEx < mid[i].expe) {
                cEx = mid[i].expe;
                cIndex = team.size() - 1;
                cNum = mid[i].number;
            }
            else if (cEx == mid[i].expe) {
                if (cNum < mid[i].number) {
                    cNum = mid[i].number;
                    cIndex = team.size() - 1;
                }
            }
        }
        for (i = 0; i < strike; ++i) {
            //cout << "striker : " << striker[i].expe << endl;
            team.push_back(striker[i]);
            if (cEx < striker[i].expe) {
                cEx = striker[i].expe;
                cIndex = team.size() - 1;
                cNum = striker[i].number;
            }
            else if (cEx == striker[i].expe) {
                if (cNum < striker[i].number) {
                    cNum = striker[i].number;
                    cIndex = team.size() - 1;
                }
            }
        }
        //sort(team.begin(), team.end());

        cout << team[cIndex].number << " " << team[cIndex].name << " " << team[cIndex].role << endl;
        //cout << team[cIndex].expe << endl;

        for (i = 0; i < team.size(); ++i) {
            if (i == cIndex) {
                //cout << team[i].number << " " << team[i].name << " " << endl;
                continue;
            }
            cout << team[i].number << " " << team[i].name << " " << team[i].role << endl;
        }
        //cout << endl;

    }


    return (0);
}
