#include <bits/stdc++.h>
#define SIZE 105
using namespace std;

struct Mice {
    int remainTime, miceNumber, maze;


    Mice() {
        remainTime = 0;
        miceNumber = 0;
        maze = 0;
    }

    void operator = (const Mice &x) {
        this->miceNumber = x.miceNumber;
        this->remainTime = x.remainTime;
        this->maze = x.maze;
    }
};

bool operator < (const Mice & x, const Mice & n) {
    if (x.remainTime <= n.remainTime) {
        return false;
    }
    else {
        return true;
    }
}

vector < pair <int, int> > ajlist[SIZE];
int N, E, T;
bool passedMice[SIZE];

int dijkstra() {

    int i, a, b, c, miceCount = N;
    Mice nMice, cMice;

    bool Ignore;

    priority_queue < Mice > pq;

    for (i = 1; i <= N; ++i) {
        cMice.remainTime = T;
        cMice.miceNumber = i;
        cMice.maze = i;
        pq.push(cMice);
    }

    while(!pq.empty()) {
        cMice = pq.top();
        pq.pop();


        if (cMice.maze == E) {

            if (passedMice[cMice.miceNumber] == false) {
                passedMice[cMice.miceNumber] = true;
                -- miceCount;
            }
        }

        // break for time end
        if (miceCount <= 0) {
            return N;
            break;
        }

        if (passedMice[cMice.miceNumber] == true) {
            continue;
        }

        for (i = 0; i < ajlist[cMice.maze].size(); ++i) {
            b = ajlist[cMice.maze][i].first;
            c = ajlist[cMice.maze][i].second;

            // Move other position
            nMice = cMice;

            nMice.maze = b;
            nMice.remainTime -= c;

            if (nMice.remainTime >= 0 && passedMice[nMice.miceNumber] == false) {
                pq.push(nMice);
            }

        }

    }

    int cnt = 0;
    for (i = 1; i <= N; ++i) {
        if (passedMice[i]) {
            ++cnt;
        }
    }

    return cnt;
}


int main() {

    // freopen("in.txt", "r", stdin);

    int test, t, Edges, i, a, b, c;

    scanf("%d", &test);

    for (t = 0; t < test; ++t) {
        scanf("%d %d %d %d", &N, &E, &T, &Edges);

        // Clear adjecency list
        for (i = 0; i <= N; ++i) {
            ajlist[i].clear();
            passedMice[i] = false;
        }

        for (i = 0; i < Edges; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            ajlist[a].push_back(make_pair(b, c));
        }

        if (t > 0) {
            puts("");
        }

        printf("%d\n", dijkstra());
    }

    return (0);
}
