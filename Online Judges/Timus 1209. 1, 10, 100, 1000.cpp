#include <bits/stdc++.h>

using namespace std;

int main() {

    map <int, bool> m;
    m[1] = true;
    int last = 1, gap, test, n;
    gap = 1;
    while(true) {
        last += gap;
        if (last < 0) break;
        m[last] = true;
        ++gap;
    }

    bool first = false;
    cin >> test;
    while(test--) {
        cin >> n;
        if (first) printf(" ");
        first = true;
        if (m[n]) printf("1");
        else printf("0");
    }
    printf("\n");

    return (0);
}
