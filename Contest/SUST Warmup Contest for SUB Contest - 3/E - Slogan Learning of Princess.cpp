#include <cstdio>
#include <iostream>

using namespace std;

int main() {

    int n, q, i, j;
    string firstS[25], secondS[25], s;
    while(scanf("%d", &n) == 1) {
        getchar();
        for (i = 0; i < n; ++i) {
            getline(cin, firstS[i]);
            getline(cin, secondS[i]);
        }
        scanf("%d", &q);
        getchar();
        for (i = 0; i < q; ++i) {
            getline(cin, s);
            for (j = 0; j < n; ++j) {
                if (s == firstS[j]) {
                    printf("%s\n", secondS[j].c_str());
                }
            }
        }
    }

    return (0);
}
