#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

#define pb push_back

using namespace std;
vector< vector<int> > graph;
bool visited[1004];

void bfs(int start, int node) {
    int i, j, currentNode;
    queue<int> bredthQueue;

    bredthQueue.push(start);
    visited[start] = 1;

    while(!bredthQueue.empty()) {
        currentNode = bredthQueue.front();
        printf("%d ", currentNode);
        bredthQueue.pop();

        for (i = 0; i < graph[currentNode].size(); ++i) {
            if (visited[graph[currentNode][i]] == 0) {
                bredthQueue.push(graph[currentNode][i]);
                visited[graph[currentNode][i]] = 1;
            }
        }
    }
}


int main() {

    int start = 2, totalNode = 4;
    vector<int> v;
    for (int i = 0; i <= totalNode; ++i) {
        graph.pb(v);
    }

    graph[0].pb(1);
    graph[0].pb(2);
    graph[1].pb(2);
    graph[2].pb(0);
    graph[2].pb(3);
    graph[3].pb(3);

    bfs(start, totalNode);  /// 2 0 3 1

    return (0);
}

