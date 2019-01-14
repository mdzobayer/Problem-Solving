#include <bits/stdc++.h>
using namespace std;

bool visit[20000+2], noCycle;
vector < int > ajlist[20000+2];

void dfs(int x) {

    if (noCycle == false) {
        return;
    }
    //printf("In %d\n", x);
    visit[x] = true;
    int i, newWay;
    if (ajlist[x].size() == 0) {
        //noCycle = true;
        return ;
    }
    for (i = 0; i < ajlist[x].size(); ++i) {
        newWay = ajlist[x][i];
        if (visit[newWay] == false) {
            dfs(newWay);
        }
        else noCycle = false;
        if (noCycle == false) break;
    }

    return ;
}



int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, m, i, node;
    map < string , int > dic;

    string a, b;
    bool result;
    bool t1, t2;

    cin >> test;
    for (t = 1; t <= test; ++t) {
        node = 1;
        dic.clear();
        for (i = 0; i < 20000+2; ++i) {
            ajlist[i].clear();
        }
        cin >> m;
        cin.ignore();
        for (i = 0; i < m; ++i) {
            cin >> a >> b;
            //t1 = t2 = true;
            if (dic.find(a) == dic.end()) {
                dic[a] = node++;
            }

            if (dic.find(b) == dic.end()) {
                dic[b] = node++;
            }
            ajlist[dic[a]].push_back(dic[b]);
        }

        noCycle = true;
        for (i = 1; i < node; ++i) {
            memset(visit, 0, sizeof(visit));
            dfs(i);

            if (noCycle == false) {
                break;
            }
        }


        if (noCycle == false) {
            printf("Case %d: No\n", t);
        }
        else {
            printf("Case %d: Yes\n", t);
        }
    }

    return (0);
}
