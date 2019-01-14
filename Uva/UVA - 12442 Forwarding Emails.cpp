#include <cstdio>
#include <cstring>

int graph[50000 + 10];
bool visited[50000 + 10];
int dp[50000 + 10];

int dfs(int start) {
    visited[start] = true;
    int total = 0;
    if (graph[start] != -1 && !visited[graph[start]]) {
        total += 1 + dfs(graph[start]);
    }
    visited[start] = false;
    return dp[start] = total;
}



int main() {

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int test, t, i, totalNode, u, v, maxSend, m, minNode;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &totalNode);

        memset(graph, -1, sizeof(graph));
        memset(dp, -1, sizeof(dp));
        memset(visited, 0, sizeof(visited));

        for (i = 1; i <= totalNode; ++i) {
            scanf("%d %d", &u, &v);
            graph[u] = v;
        }

        maxSend = -1;
        minNode = 1;
        for (i = 1; i <= totalNode; ++i) {
                if (dp[i] == -1) {
                    m = dfs(i);
                }
                if (maxSend < dp[i]) {
                    maxSend = dp[i];
                    minNode = i;
                }
        }
        printf("Case %d: %d\n", t, minNode);
    }
    return (0);
}

