#include <bits/stdc++.h>
#define PAIR pair < int, int >

using namespace std;

vector < PAIR > ajlist[5000+5];
vector < int > minPaths;
int visit[5000+5];
int n, r;

void dijkstra() {

    PAIR curr;
    int cNode, nNode, cost, i, nCost;
    priority_queue < PAIR, vector < PAIR >, greater<PAIR> > pq;
    minPaths.clear();
    pq.push(make_pair(0, 1));

    ++visit[1];

    while(!pq.empty()) {
        curr = pq.top();
        pq.pop();
        cNode = curr.second;
        cost = curr.first;
        //printf("Popped --- node = %d cost = %d\n", cNode, cost);
        if (cNode == n) {
            minPaths.push_back(cost);
            //printf("Found a ans = %d\n", cost);
            if(minPaths.size() > 1) {
                if(minPaths[minPaths.size() - 2] != minPaths.back()) {
                    printf("%d\n", minPaths.back());
                    return ;
                }
            }
        }

        for (i = 0; i < ajlist[cNode].size(); ++i) {
            nNode = ajlist[cNode][i].first;
            nCost = ajlist[cNode][i].second;
            //printf("New node = %d cost = %d\n", nNode, nCost);
            if (visit[nNode] < 100) {
                ++visit[nNode];
                pq.push(make_pair(cost+nCost, nNode));
            }
        }
    }


}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, u, v, w;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &r);
        // Clear ajlist
        for (i = 0; i < n + 3; ++i){
            ajlist[i].clear();
            visit[i] = 0;
        }
        for (i = 0; i < r; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            ajlist[u].push_back(make_pair(v, w));
            ajlist[v].push_back(make_pair(u, w));
        }

        printf("Case %d: ", t);
        dijkstra();

    }

    return (0);
}
