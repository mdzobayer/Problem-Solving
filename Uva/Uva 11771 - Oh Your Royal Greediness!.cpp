#include <cstdio>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

vector< pair<int, int> > vt;

int main() {

    int n, i, s, e, t = 1, a, b, maximum, j;
    while(scanf("%d", &n) && n != -1) {
        vt.clear();
        for (i = 0; i < n; ++i) {
            scanf("%d %d", &s, &e);
            vt.push_back(make_pair(s, e));
        }
        maximum = 0;
        for (i = 0; i < vt.size(); ++i) {
            a = b = 0;
            for (j = 0; j < vt.size(); ++j) {
                if (vt[i].first >= vt[j].first && vt[j].second >= vt[i].first)
                    ++a;
                if (vt[i].second >= vt[j].first && vt[j].second >= vt[i].second)
                    ++b;
            }
            maximum = max (a, maximum);
            maximum = max (b, maximum);
        }

        printf("Case %d: %d\n", t++, maximum);
    }


    return (0);
}
