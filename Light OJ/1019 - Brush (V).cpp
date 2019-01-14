#include <bits/stdc++.h>

using namespace std;
#define SIZE 100+5
#define f first
#define s second

vector < pair < int, int > > ajlist[SIZE];

int dist [SIZE], n;
bool vis [SIZE];

void dijkstra(int src, int desti) {

    memset(vis, false, sizeof(vis));
    dist[src] = 0;

    int i, x, wei, e, w;
    multiset < pair < int, int > > s;

    s.insert(make_pair(0, src));

    while(!s.empty()) {
        pair < int, int > p = *s.begin();

        s.erase(s.begin());
        x = p.s;
        if(x == n) return;

        wei = p.f;
        if(vis[x]) continue;

        vis[x] = true;

        for (i = 0; i < ajlist[x].size(); ++i) {
            e = ajlist[x][i].f;
            w = ajlist[x][i].s;

            if(dist[x] + w < dist[e]) {
                dist[e] = dist[x] + w;
                s.insert(make_pair(dist[e], e));
            }
        }
    }
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, u, v, w, m, src, desti, i;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);
        /// Clear adjacency list v
        for (i = 0; i <= n; ++i) {
            dist[i] = INT_MAX;
            ajlist[i].clear();
        }

        for (i = 0; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            ajlist[u].push_back(make_pair(v, w));
            ajlist[v].push_back(make_pair(u, w));
        }
        dijkstra(1, n);
        printf("Case %d: ", t);
        if(dist[n] == INT_MAX)
            puts("Impossible");
        else printf("%d\n", dist[n]);
    }

    return (0);
}
