#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int graph[1004][1004];
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

        for (i = 0; i < node; ++i) {
            if (graph[currentNode][i] == 1 && visited[i] == 0) {
                depthStack.push(i);
                visited[i] = 1;
            }
        }
    }
}


int main() {

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[1][2] = 1;
    graph[2][0] = 1;
    graph[2][3] = 1;
    graph[3][3] = 1;

    int start = 2, totalNode = 4;

    dfs(start, totalNode); /// 2 3 0 1

    return (0);
}
