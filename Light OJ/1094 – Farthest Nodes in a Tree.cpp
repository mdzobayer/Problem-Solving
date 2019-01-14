#include <bits/stdc++.h>

using namespace std;

int n;

vector < pair < int, int > > ajlist[30000+5];
bool vis[30000+5];
int cost[30000+5];

int dfs(int cNode, int co) {
    vis[cNode] = false;
    int i, newNode, farNode = cNode, returnNode;
    cost[farNode] = co;
    //printf("Enter %d Cost %d\n", cNode, co);

    for (i = 0; i < ajlist[cNode].size(); ++i) {
        newNode = ajlist[cNode][i].first;
        if (vis[newNode]) {

            returnNode = dfs(newNode, (co + ajlist[cNode][i].second));
            if(cost[farNode] < cost[returnNode]){
                farNode = returnNode;
            }
        }
    }
    return farNode;
}

int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, u, v, c, i, firstFar;
    scanf("%d", &test);
    for ( t = 1; t <= test; ++t) {
        scanf("%d", &n);
        ///
        for (i = 0; i <= n; ++i) {
            ajlist[i].clear();
        }

        for (i = 1; i < n; ++i) {
            scanf("%d %d %d", &u, &v, &c);
            ajlist[u].push_back(make_pair(v, c));
            ajlist[v].push_back(make_pair(u, c));
        }
        memset(vis, true, sizeof(vis));
        memset(cost, 0, sizeof(cost));
        firstFar = dfs(0, 0);

        memset(vis, true, sizeof(vis));
        memset(cost, 0, sizeof(cost));
        firstFar = dfs(firstFar, 0);

        printf("Case %d: %d\n",t, cost[firstFar]);

    }

    return (0);
}
