#include <bits/stdc++.h>
using namespace std;

int sTime, start[110], End[110], baseTime[110];
bool visited[110], isPoint[110];

vector <int> graph[110];

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
            //printf("i am here %d > %d\n", grandParent, start[node]);
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

    freopen("out.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int node, edges, x, y;
    string s;

    //cin >> node >> edges;
    while(cin >> node) {
        if(node == 0) break;
        cin.ignore();
        //x = 1;
        for (x = 0; x < 110; ++x) {
            graph[x].clear();
        }
        while(getline(cin, s)) {
            //cout << s << endl;
            if (s == "0") break;
            stringstream ss(s);
            ss >> x;
            while(ss >> y) {
                //cout << x << " " << y << endl;
                graph[x].push_back(y);
                graph[y].push_back(x);
            }
        }
        /// Reset Memory
        sTime = 0;
        memset(start, 0, sizeof(start));
        memset(End, 0, sizeof(End));
        memset(visited, true, sizeof(visited));
        memset(isPoint, true, sizeof(isPoint));
        memset(baseTime, 0, sizeof(baseTime));
        /// Call dfs with start time and end time
        dfs(1, 0);
        y = 0;
        for(x = 1; x <= node; ++x) {
            //cout << x << " " << start[ x ] << " " << End[ x ] << " " << baseTime[ x ] << endl ;
            if (isPoint[x] == false) {
                //printf("%d ", x);
                ++y;
            }
        }
        cout << y << endl;
    }

    return (0);
}
