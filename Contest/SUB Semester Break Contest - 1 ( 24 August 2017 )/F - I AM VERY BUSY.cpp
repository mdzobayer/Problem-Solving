#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector < pair <int, int> > vt;

int main() {

    int test, t, i, n, s, e, count;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        vt.clear();
        scanf("%d", &n);
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &s, &e);
            vt.push_back(make_pair(e, s));
        }
        sort(vt.begin(), vt.end());
        count = 0;
        int ending = 0;
        for (i = 0; i < vt.size(); ++i) {
            if (vt[i].second >= ending) {
                ++count;
                ending = vt[i].first;
            }
        }
        printf("%d\n", count);
    }

    return (0);
}
