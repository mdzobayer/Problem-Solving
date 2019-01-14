#include <bits/stdc++.h>
#define SIZE 1000+5
using namespace std;

vector < int > ajlist[SIZE];
bool visit[SIZE];
int n, m, arr[SIZE], x;

bool bfs(int extra, int cNode) {

    memset(visit, true, sizeof(visit));
    int nNode, i;

    visit[cNode] = false;
    queue < int > q;
    q.push(cNode);

    while(!q.empty()) {
        cNode = q.front();
        q.pop();
        for (i = 0; i < ajlist[cNode].size(); ++i) {
            nNode = ajlist[cNode][i];
            if(visit[nNode]) {
                visit[nNode] = false;
                if(arr[nNode] < x) {
                    arr[nNode] += extra;
                    extra = arr[nNode] - x;
                    if(extra <= 0) return true;
                }
                q.push(nNode);
            }
        }
    }
    if(extra > 0) return false;

    return true;
}

int main() {

    freopen("in.txt", "r" ,stdin);

    int test, t, i, u, v;
    long long int sum;
    bool res;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);

        // Clear ajlist


        sum = 0;
        for (i = 1; i <= n; ++i) {
            ajlist[i].clear();
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        ajlist[n].clear();
        ajlist[n + 1].clear();

        for (i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            ajlist[u].push_back(v);
            ajlist[v].push_back(u);
        }
        x = sum / n;
        if(x * n == sum) {
            //printf("Case %d: %s\n", t, (bfs() ? "Yes" : "No"));
            res = true;
            for (i = 1; i <= n && res; ++i) {
                //cout << "Grader check = " << arr[i] << " " << x << endl;
                if(arr[i] > x) {
                    cout << "Node i = " << i << " is called" << endl;
                    res = bfs(arr[i] - x, i);
                    arr[i] = x;
                }
            }
            cout << "Debug 2 res = " << res << endl;
            for (i = 1; i <= n && res; ++i) {
                if(arr[i] != x) {
                    //cout << x << " " << arr[i] << endl;
                    //cout << "Debug 3 res = " << res << " i = " << i << endl;
                    res = false;
                    break;
                }
            }
            //cout << "Debug 1 here" << endl;
            if(res) printf("Case %d: Yes\n", t);
            else printf("Case %d: No\n", t);
        }
        else {
            printf("Case %d: No\n", t);
        }

    }

    return (0);
}
