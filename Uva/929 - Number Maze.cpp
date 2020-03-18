#include <bits/stdc++.h>
#define SIZE 1000+5

using namespace std;

int N, M, cost[SIZE][SIZE], reachCost[SIZE][SIZE];

struct Node {
    int x, y, weight;


    Node() {
        x = 0;
        y = 0;
        weight = 0;
    }

    bool operator < (const Node & n) {
        if (this->weight <= n.weight) {
            return true;
        }
        else {
            return false;
        }
    }

    void operator = ( const Node & n) {
        this->x = n.x;
        this->y = n.y;
        this->weight = n.weight;
    }
};

bool operator < (const Node & x, const Node & n) {
    if (x.weight <= n.weight) return true;
    else {
        return false;
    }
}

bool isValid(const Node & aNode) {
    if (aNode.x < 0 || aNode.y < 0 || aNode.x >= N || aNode.y >= M) {
        return false;
    }

    return true;
};

bool isTarget(const Node & aNode) {
    if (aNode.x == (N - 1) && aNode.y == (M - 1)) {
        return true;
    } 
    return false;
}


int dijkstra(Node start) {

    int i, j;
    Node cNode, nNode;

    priority_queue<Node> pq;

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            reachCost[i][j] = INT_MAX;
        }
    }

    start.weight = cost[0][0];
    pq.push(start);

    while(!pq.empty()) {
        cNode = pq.top();
        pq.pop();

        //printf("Poped %d\n", cNode.weight);


        if (reachCost[cNode.x][cNode.y] > (cNode.weight + cost[cNode.x][cNode.y])) {
            reachCost[cNode.x][cNode.y] = (cNode.weight + cost[cNode.x][cNode.y]);

            nNode.weight = reachCost[cNode.x][cNode.y];
            nNode.x = cNode.x + 1;
            nNode.y = cNode.y;
           

            if (isValid(nNode)) {
                if (reachCost[nNode.x][nNode.y] > (nNode.weight + cost[nNode.x][nNode.y])) {
                     pq.push(nNode);
                }
            }

            nNode.x = cNode.x;
            nNode.y = cNode.y + 1;

            if (isValid(nNode)) {
                if (reachCost[nNode.x][nNode.y] > (nNode.weight + cost[nNode.x][nNode.y])) {
                     pq.push(nNode);
                }
            }

        }


    }

    return reachCost[N-1][M-1];

}


int main() {

//    freopen("in.txt", "r", stdin);

    int test, t, i, j;
    scanf("%d", &test);
    for (t = 0; t < test; ++t) {
        scanf("%d %d", &N, &M);

        for (i = 0; i < N; ++i) {
            for (j = 0; j < M; ++j) {
                scanf("%d", &cost[i][j]);
            }
        }
        Node aNode;

        printf("%d\n", dijkstra(aNode));

    }

    return (0);
};
