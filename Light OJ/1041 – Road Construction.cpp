#include <bits/stdc++.h>

using namespace std;

int test, t, m;

vector < pair < int, int > > ajlist[100+5];
bool vis[100+5];

void prims(int nodes) {
    pair < int, int > curr, New;
    int i, cost = 0, newNode, cNode, tmpCost, n = nodes;
    memset(vis, true, sizeof(vis));

    curr.first = 0;
    curr.second = 1;
    priority_queue < pair<int,int>, vector< pair<int,int> >, greater < pair<int,int> > > pq;

    pq.push(curr);
    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();

        cNode = curr.second;
        if (vis[cNode]) {
            cost += curr.first;
            --nodes;
        }
        vis[cNode] = false;

        if(nodes <= 0) break;

        //cout << "Poped " << cNode << " Cost " << curr.first << endl;
        for (i = 0; i < ajlist[cNode].size(); ++i) {
            newNode = ajlist[cNode][i].first;
            if(vis[newNode]) {
                tmpCost = ajlist[cNode][i].second;
                pq.push(make_pair(tmpCost, newNode));
                //printf("\tPushed %d Cost %d\n", newNode, tmpCost);
            }
        }

    }
    for (i = 1; i < n; ++i) {
        if (vis[i]) {
            printf("Impossible\n");
            return;
        }
    }
    printf("%d\n", cost);
}

int main () {

    //freopen("in.txt", "r", stdin);

    string xs, ys;
    int i, cost, x, y, w, index;
    map < string, int > mp;

    scanf("%d", &test);
    index = 0;
    for (t = 1; t <= test; ++t) {
        for (i = 0; i <= index; ++i) {
            ajlist[i].clear();
        }
        index = 1;
        mp.clear();
        scanf("%d", &w);
        getchar();
        for ( i = 0; i < w; ++i) {
            cin >> xs >> ys >> cost;
            if(mp.find(xs) != mp.end()) {
                x = mp[xs];
            }
            else {
                x = index++;
                mp[xs] = x;
            }
            if(mp.find(ys) != mp.end()) {
                y = mp[ys];
            }
            else {
                y = index++;
                mp[ys] = y;
            }
            ajlist[x].push_back(make_pair(y, cost));
            ajlist[y].push_back(make_pair(x, cost));
        }
        printf("Case %d: ", t);
        prims(index);
    }

    return (0);
}
