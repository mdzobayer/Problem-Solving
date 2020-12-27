#include <bits/stdc++.h>

#define pb push_back

using namespace std;

class Node {
public:
    int factorCount, position;

    Node() {
        factorCount = 0;
        position = 0;
    }

    Node(int fac, int pos) {
        factorCount = fac;
        position = pos;
    }

    bool operator < (Node b) {
        if (this->factorCount < b.factorCount) {
            return true;
        }
        else if (this->factorCount > b.factorCount) {
            return false;
        }
        else {
            return this->position < b.position;
        }
    }

    void operator = (Node b) {
        this->factorCount = b.factorCount;
        this->position = b.position;
    }
};

vector < Node > data;
int processedData[2000000 + 5][2];
bool prime [2000000 + 5];

void solve(int n) {

    int len, i, j;
    memset(prime, true, sizeof(prime));

    for (i = 2; i <= n; ++i) {
        processedData[i][0] = i;
        processedData[i][1] = 0;
    }

    len = sqrt(n + 5);

    for (i = 4; i <= n; i += 2) {
        prime[i] = false;

        while(processedData[i][0] % 2 == 0) {
            processedData[i][0] /=2;
            ++processedData[i][1];
        }
    }

    for (i = 3; i <= n; i += 2) {
        if (prime[i]) {
            for (j = i * 2; j <= n; j += i) {
                prime[j] = false;

                while(processedData[j][0] % i == 0) {
                    processedData[j][0] /= i;
                    ++processedData[j][1];
                }
            }
        }
    }

    data.clear();

    Node aNode;
    aNode.factorCount = 1;
    aNode.position = 1;
    data.pb(aNode);
    data.pb(aNode);

    for (i = 2; i <= n; ++i) {
        if (prime[i]) {
            aNode.factorCount = 1;
            aNode.position = i;
            data.pb(aNode);
        }
        else {
            if (processedData[i][0] > 0) {
                ++processedData[i][1];
            }
            aNode.factorCount = processedData[i][1];
            aNode.position = i;
            data.pb(aNode);
        }
    }
}

int main () {
    int n, t = 1;
    solve(2000000);
    sort(data.begin(), data.end());

    // for (int i = 1; i < data.size(); ++i) {
    //     printf("factor = %d n = %d\n", data[i].factorCount, data[i].position);
    // }

    while(scanf("%d", &n) == 1) {
        if (n == 0) break;

        printf("Case %d: %d\n", t, data[n].position);
        ++t;
    }

    return (0);
}
