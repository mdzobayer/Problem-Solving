#include <cstdio>
#include <cstring>

#define N 30000

int parent[N], Rank[N], maxGroup[N];

int getParent(int x) {
    if (x != parent[x]) {
        parent[x] = getParent(parent[x]);
    }
    return parent[x];
}

void join(int x, int y) {
    if (Rank[x] > Rank[y]) {
        parent[y] = x;
    }
    else {
        parent[x] = y;
    }
    if (Rank[x] == Rank[y]) {
        Rank[y]++;
    }
}

int main() {

    int test, n, m, i, a, b, j, maxG;
    scanf("%d", &test);
    for (i = 0; i < test; ++i) {
        scanf("%d %d", &n, &m);
        memset(Rank, 0, sizeof(Rank));
        memset(maxGroup, 0, sizeof(maxGroup));
        for (j = 0; j <= n; ++j) {
            parent[j] = j;
        }
        for (j = 0; j < m; ++j) {
            scanf("%d %d", &a, &b);
            if (getParent(a) != getParent(b)) {
                join(getParent(a), getParent(b));
            }
        }
        for (j = 0; j <= n; ++j) {
            if(getParent(parent[j]) <= n) {
                //printf("Parent %d\n", parent[j]);
                maxGroup[getParent(parent[j])] += 1;
            }
        }
        maxG = maxGroup[0];

        for (j = 1; j <= n; ++j) {
            if (maxG < maxGroup[j])
                maxG = maxGroup[j];
        }
        printf("%d\n", maxG);
    }

    return (0);
}
