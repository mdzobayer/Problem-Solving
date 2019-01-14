#include <bits/stdc++.h>
using namespace std;

int sTime, start[50], End[50], baseTime[50];
bool visited[50], isPoint[50];

vector <int> graph[50];

bool isDirect(int x, int y) {
    for (int i = 0; i < graph[x].size(); ++i) {
        if (graph[x][i] == y) return true;
    }
    return false;
}

int dfs(int node, int preNode) {

    start[node] = ++sTime;
    baseTime[node] = start[node];
    //printf("Entering %d time %d\n", node, start[node]);
    visited[node] = false;
    int newNode, i, grandParent, range = graph[node].size();

    int cnt = 0 ;
    for (i = 0; i < range; ++i) {
        newNode = graph[node][i];
        if (visited[newNode]) {
            cnt ++ ;
            grandParent = dfs(newNode, node);
            printf("i am here %d > %d\n", grandParent, start[node]);
            if(grandParent >= start[node] && node != 1) {
                isPoint[node] = false; /// Is a articulation Point
            }
            else if(grandParent < start[node]) {
                baseTime[node] = min(grandParent, baseTime[node]);
                //isPoint[newNode] = true;
            }

        }
        else if(visited[newNode] == false && newNode != preNode) {
            grandParent = baseTime[newNode];
            if(grandParent <= baseTime[node]) {
                baseTime[node] = min(grandParent, baseTime[node]);
                //isPoint[newNode] = true;
            }
        }
    }

    End[node] = ++sTime;

    if( node == 1 && cnt > 1 ) {
        isPoint[ node ] = false ;
    }
    //printf("Exiting is %d time %d\n", node, start[node]);
    return baseTime[node];
}

int main() {

    //freopen("out.txt", "r", stdin);

    int node, edges, x, y;

    cin >> node >> edges;
    while(edges--) {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    sTime = 0;
    memset(start, 0, sizeof(start));
    memset(End, 0, sizeof(End));
    memset(visited, true, sizeof(visited));
    memset(isPoint, true, sizeof(isPoint));
    memset(baseTime, 0, sizeof(baseTime));

    dfs(1, 1);
    for(x = 1; x <= node; ++x) {
        //cout << x << " " << start[ x ] << " " << End[ x ] << " " << baseTime[ x ] << endl ;
        if (isPoint[x] == false) {
            printf("%d ", x);
        }
    }

    return (0);
}
