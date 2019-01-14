#include <bits/stdc++.h>

using namespace std;
#define SIZE 100000+1

vector < pair < int, int > > v [SIZE];

int dist [SIZE];
bool vis [SIZE];

void dijkstra(int src) {

    memset(vis, false, sizeof(vis));
    dist[src] = 0;

    int i, x, wei, e, w;
    multiset < pair < int, int > > s;

    s.insert({0, src});

    while(!s.empty()) {
        pair < int, int > p = *s.begin();

        s.erase(s.begin());
        x = p.s;
        wei = p.f;
        if(vis[x]) continue;

        vis[x] = true;

        for (i = 0; i < v[x].size(); ++i) {
            e = v[x][i].f;
            w = v[x][i].s;

            if(dist[x] + w < dist[e]) {
                dist[e] = dist[x] + w;
                s.insert({dist[e], e});
            }
        }
    }
}

int main() {



    return (0);
}
