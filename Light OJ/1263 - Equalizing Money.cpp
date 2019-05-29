#include <bits/stdc++.h>
#define SIZE 1000+5
using namespace std;

vector < int > ajlist[SIZE];
bool visit[SIZE];
int n, m, arr[SIZE], sum, equalMoney;

bool bfs(int cNode) {

    int nNode, i, sz, amount = 0, person = 0;
    queue <int> q;
    q.push(cNode);
    visit[cNode] = false;
    // printf("Current Nodes: ");
    while(!q.empty()) {
        cNode = q.front();
        q.pop();
        // printf(" %d", cNode);
        ++person;
        amount += arr[cNode];

        sz = ajlist[cNode].size();
        for (i = 0; i < sz; ++i) {
            nNode = ajlist[cNode][i];
            if (visit[nNode]) {
                visit[nNode] = false;
                q.push(nNode);
            }
        }
    }
    // puts("");
    // printf("check %d %d\n", equalMoney * person, amount);

    if (equalMoney * person == amount)
        return true;
    else return false;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, u, v;
    bool ans;
    scanf("%d", &test);

    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &m);
        sum = 0;
        
        for (i = 1; i <= n; ++i) {
            scanf("%d", &arr[i]);
            sum += arr[i];
            ajlist[i].clear();
        }
        ajlist[i].clear();
        // printf("Sum is %d\n", sum);

        for (i = 0; i < m; ++i) {
            scanf("%d %d", &u, &v);
            ajlist[u].push_back(v);
            ajlist[v].push_back(u);
        }
        printf("Case %d: ", t);
        if (sum % n) {
            puts("No");
        }
        else {
            memset(visit, true, sizeof(visit));
            equalMoney = sum / n;
            ans = true;
            for (i = 1; i <= n; ++i) {
                if (visit[i]) {
                    ans = bfs(i);
                    
                }
                if (ans == false) {
                    puts("No");
                    break;
                }
            }
            if (ans) {
                puts("Yes");
            } 
        }
    }
    
    return (0);
}
