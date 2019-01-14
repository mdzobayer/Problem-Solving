#include <bits/stdc++.h>
#define SIZE 100000+5
using namespace std;

int n;
long long int notFriend, pairInvite;
vector < int > ajlist[SIZE];
bool node[SIZE];

void dfs(int cNode) {
    node[cNode] = false;

        ++notFriend;

    int i, nNode, len;
    len = ajlist[cNode].size();
    for (i = 0; i < len; ++i) {
        nNode = ajlist[cNode][i];
        if(node[nNode]) {
            dfs(nNode);
        }
    }
    //cout << cNode << " " << notFriend << endl;
    pairInvite += (n - notFriend);
    //cout << pairInvite << endl;
}
//int binarySearch(int cNode, int key) {
//    int mid, low, high;
//    low = 0;
//    high = ajlist[cNode].size() - 1;
//
//    while(low <= high) {
//        mid = (low + high) / 2;
//        if(ajlist[cNode][mid] < key) {
//            low = mid + 1;
//        }
//        else if(ajlist[cNode][mid] > key) {
//            high = mid - 1;
//        }
//        else {
//            low = mid + 1;
//        }
//    }
//    return low;
//}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, i, u, v;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);

        /// Reset memory
        memset(node, 1, sizeof(node));
        for (i = 0; i < n+2; ++i) {
            ajlist[i].clear();
        }

        for (i = 1; i < n; ++i) {
            scanf("%d %d", &u, &v);
            ajlist[u].push_back(v);
        }

        /// Sort ajlist for binary Search
        for (i = 1; i <= n; ++i) {
            sort(ajlist[i].begin(), ajlist[i].end());
        }
        // Invite Process
        pairInvite = notFriend = 0;
        dfs(1);


        printf("Case %d: %d %lld\n", t, n - 1, pairInvite);

    }

    return (0);
}
