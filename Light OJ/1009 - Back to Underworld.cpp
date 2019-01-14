
#include <bits/stdc++.h>
using namespace std;
int test, t, u, v, n;

vector < int > ajlist[20000+5];
bool visited[20000+5];

struct node {
    int level, no;
};

int bfs(int mx) {
    //cout << "Maximum Node : " << mx << endl;
    int i, nNode, cNode, Count = 0, even, odd, j, tmpC;

    for (i = 0; i <= mx; ++i) {
        //cout << "Debug 1" << endl;
        if (visited[i]) {
            visited[i] = false;
            even = odd = 0;

            node curr, newNode;

            curr.level = 1;
            curr.no = i;
            queue < node > q;
            q.push(curr);
            while(!q.empty()) {
                curr = q.front();
                tmpC = ajlist[curr.no].size();
                //cout << "Poped : " << curr.no << endl;

                q.pop();
                //cout << "Debug 2" << endl;
                (curr.level % 2) ? ++odd : ++even;

                for (j = 0; j < tmpC; ++j) {
                    nNode = ajlist[curr.no][j];
                    if (visited[nNode]) {
                        visited[nNode] = false;
                        newNode.no = nNode;
                        newNode.level = curr.level + 1;
                        q.push(newNode);
                        //cout << "Pushed : " << newNode.no << endl;
                    }
                }

            }
            //cout << max(odd, even) << endl;
            Count += max(odd, even);
            //cout << "Count is : " << Count << endl;
        }
    }
    return Count;
}


int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int i, mx;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        memset(visited, false, sizeof(visited));
        mx = 0;
        // Clear ajlist
        for (i = 1; i < 20002; ++i) {
            ajlist[i].clear();
        }
        // Now input
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &u, &v);
            visited[u] = true;
            visited[v] = true;
            ajlist[v].push_back(u);
            ajlist[u].push_back(v);

            mx = max(mx, u);
            mx = max(mx, v);
        }
        printf("Case %d: %d\n", t, bfs(mx));
    }

    return (0);
}

