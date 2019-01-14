#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

bool node[1005][1005];
bool visited[1005];
int level[1005];
bool flag;

void bfs(int nodes, int start, vector < vector <int> > &vt) {
    int i;

    /// If Start is already visited then return
    if (visited[start] == 1) {
        return;
    }
    /// Insert Some Empty vector
    if (flag){
        vector<int> v;
        for (i = 0; i < nodes; ++i) {
            vt.push_back(v);
        }
    }

    queue<int> qt;
    int currentNode = start;
    level[currentNode] = 0;         /// Current Node level is 0
    vt[0].push_back(currentNode);   /// Store current node in level 0
    qt.push(currentNode);
    visited[currentNode] = 1;
    while(!qt.empty()) {
        /// Find all node that connected with current Node
        for (i = 1; i <= nodes; ++i) {
            if (node[currentNode][i] == 1 && visited[i] == 0) {
                qt.push(i);
                visited[i] = 1;
                /// Level of every Node
                level[i] = level[currentNode] + 1;
                /// Store every node as level
                vt[level[i]].push_back(i);
            }
        }
        qt.pop();
        currentNode = qt.front();
    }
}


int main() {



    return (0);
}
