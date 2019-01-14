#include <bits/stdc++.h>

using namespace std;
struct Node {
    int u, cost;
    Node() {};
    Node(int _u, int _cost) {
        u = _u;
        cost = _cost;
    }
};

bool operator < (Node A, Node B) {
    return A.cost > B.cost;
}

priority_queue<Node> PQ;
int cost[100];
int taken[100];

int prim(int n, int s) {


    for (int i = 0; i < n; ++i) {
        cost[i] = INF, taken[i] = 0;
    }

    cost[s] = 0;
    PQ.push(Node(s, 0));
    int ans = 0;

    while(!PQ.empty()) {
        Node x = PQ.top();
        PQ.pop();

        if (taken[x.u]) {
            continue;
        }
        taken[x.u] = 1;
        ans += x.cost;

        for (PII v : V[x.u]) {

        }
    }
}

int main() {



    return (0);
}
