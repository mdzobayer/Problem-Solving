#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

#define pb push_back

using namespace std;
vector< vector<int> > graph;
bool visited[1004];

void dfs(int start, int node) {
    int i, j, currentNode;
    stack<int> depthStack;

    depthStack.push(start);
    visited[start] = 1;

    while(!depthStack.empty()) {
        currentNode = depthStack.top();
        printf("%d ", currentNode);
        depthStack.pop();

        for (i = 0; i < graph[currentNode].size(); ++i) {
            if (visited[graph[currentNode][i]] == 0) {
                depthStack.push(graph[currentNode][i]);
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

    dfs(start, totalNode); /// 2 3 0 1

    return (0);
}
