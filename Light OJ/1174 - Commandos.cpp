#include <bits/stdc++.h>
#define SIZE 105

using namespace std;

vector < int > ajlist[SIZE];
int n, r;

void bfs(int source, int * cost) {

    cost[source] = 0;

    queue < int > q;
    q.push(source);

    int cNode, nNode, i;

    while(!q.empty()) {
        cNode = q.front();
        q.pop();

        for (i = 0; i < ajlist[cNode].size(); ++i) {
            nNode = ajlist[cNode][i];

            if (cost[nNode] == -1) {
                cost[nNode] = cost[cNode] + 1;
                q.push(nNode);
            }
        }
    }

    // for (int x = 0; x < n; ++x) {
    //     cout << cost[x] << " ";
    // }
    // cout << endl;

}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, u, v, i, source, destination, totalTime, cost1[SIZE], cost2[SIZE];
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &r);

        for (i = 0; i < SIZE; ++i) {
            ajlist[i].clear();
        }

        for (i = 0; i < r; ++i) {
            scanf("%d %d", &u, &v);
            ajlist[u].push_back(v);
            ajlist[v].push_back(u);
        }

        scanf("%d %d", &source, &destination);
        memset(cost1, -1, sizeof(cost1));
        bfs(source, cost1);

        memset(cost2, -1, sizeof(cost2));
        bfs(destination, cost2);

        totalTime = 0;

        for (i = 0; i < n; ++i) {
            totalTime = max(totalTime, cost1[i] + cost2[i]);
        }

        printf("Case %d: %d\n", t, totalTime);
    }

    return (0);
}
