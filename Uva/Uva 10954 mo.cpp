#include <bits/stdc++.h>

int main() {

    int n, x;
    while(scanf("%d", &n) && n > 0) {
        std::priority_queue<int, std::vector<int>, std::greater<int> > q;

        while(n--) {
            scanf("%d", &x);
            q.push(x);
        }

        int total = 0, cost = 0;
        while(q.size() > 1) {
            total = q.top();
            q.pop();
            total += q.top();
            q.pop();
            cost += total;
            q.push(total);
        }
        printf("%d\n", cost);
    }

    return (0);
}
