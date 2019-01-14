#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int graph[1004][1004];
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

        for (i = 0; i < node; ++i) {
            if (graph[currentNode][i] == 1 && visited[i] == 0) {
                bredthQueue.push(i);
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

    bfs(start, totalNode);

    return (0);
}

