#include <bits/stdc++.h>
using namespace std;
vector< pair<int, int> > vt;

int main() {
    bool flag = true;
    long long int n, s, e, i;
    scanf("%lld", &n);
    for (i = 0; i < n; ++i) {
        scanf("%lld %lld", &s, &e);
        vt.push_back(make_pair(s, 1));
        vt.push_back(make_pair(e, 2));
    }
    sort(vt.begin(), vt.end());
    int count = 0;
    //printf("\n\n");
    for (size_t j = 0; j < vt.size(); ++j) {
        //printf("%d %d\n", vt[i].first, vt[i].second);
        if (vt[j].second == 1) ++count;
        else --count;
        if (count > 2) {
            flag = false;
            break;
        }
    }
    if (flag) printf("YES\n");
    else printf("NO\n");

    return (0);
}
