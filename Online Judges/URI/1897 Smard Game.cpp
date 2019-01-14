#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll n, m;
struct node {

    ll value;
    int step;
};
int bfs() {
    node newN, currN;
    currN.value = n;
    currN.step = 0;

    queue < node > q;
    q.push(currN);

    while(!q.empty()) {
        currN = q.front();
        q.pop();

        if (currN.value == m) return currN.step;

        newN.step = currN.step + 1;

        newN.value = currN.value << 1;
        q.push(newN);
        newN.value = currN.value * 3;
        q.push(newN);
        newN.value = currN.value >> 1;
        q.push(newN);
        newN.value = currN.value / 3;
        q.push(newN);
        newN.value = currN.value + 7;
        q.push(newN);
        newN.value = currN.value - 7;
        q.push(newN);
    }

}

int main() {

    while(scanf("%lld %lld", &n, &m) == 2)
        printf("%d\n", bfs());

    return (0);
}
