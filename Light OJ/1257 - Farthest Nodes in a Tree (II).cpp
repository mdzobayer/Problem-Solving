#include <bits/stdc++.h>

#define lli long long int
using namespace std;
int nodes;
vector < pair <int, int> > graph[30010];
int distan1[30010], distan2[30010];
bool flag;

void bfs(int currNode) {
    int newNode, newWeight, i;

    if (flag)
        distan1[currNode] = 0;
    else
        distan2[currNode] = 0;

    queue < int > q;
    q.push(currNode);
    while(!q.empty()) {
        currNode = q.front();
        q.pop();

        for (i = 0; i < graph[currNode].size(); ++i) {
            newNode = graph[currNode][i].first;
            newWeight = graph[currNode][i].second;
            if (flag) {
                if (distan1[newNode] == -1) {
                    distan1[newNode] = distan1[currNode] + newWeight;
                    q.push(newNode);
                }
            }
            else {
                if(distan2[newNode] == -1) {
                    distan2[newNode] = distan2[currNode] + newWeight;
                    q.push(newNode);
                }
            }
        }
    }
}

int main() {

    //freopen("in.txt", "r" ,stdin);
    int test, st, en, maxi, w, i, t = 0;

    cin >> test;
    for (t = 1; t <= test; ++t) {

        cin >> nodes;

        /// Clear Graph
        for (i = 0; i <= nodes+2; ++i) {
            graph[i].clear();
        }

        for (i = 1; i < nodes; ++i) {
            cin >> st >> en >> w;
            graph[st].push_back(make_pair(en, w));
            graph[en].push_back(make_pair(st, w));
        }

        /// Case print
        printf("Case %d:\n", t);

        memset(distan1, -1, sizeof(distan1));
        flag = true;
        bfs(0);

        maxi = -1;
        for (i = 0; i < nodes; ++i) {
            if (distan1[i] > maxi) {
                st = i;
                maxi = distan1[i];
            }
        }

        memset(distan1, -1, sizeof(distan1));
        flag = true;
        bfs(st);

        maxi = -1;
        for (i = 0; i < nodes; ++i) {
            if (distan1[i] > maxi) {
                en = i;
                maxi = distan1[i];
            }
        }

        memset(distan2, -1, sizeof(distan2));
        flag = false;
        bfs(en);

        for (i = 0; i < nodes; ++i) {
            printf("%d\n", max(distan1[i], distan2[i]));
        }
    }

    return (0);
}
