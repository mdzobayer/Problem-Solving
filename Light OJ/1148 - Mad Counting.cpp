#include <bits/stdc++.h>

using namespace std;

int main() {

    // freopen("in.txt", "r", stdin);

    map<int, int> st;

    int n, i,test, t, x, y, cn;
    long long int ans;

    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d", &n);
        st.clear();
        ans = 0;

        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            ++st[x];
            if (st[x] == x + 1) {
                ans += x + 1;
                st[x] = 0;
            }
        }
        

        map<int, int>::iterator it;
        for (it = st.begin(); it != st.end(); ++it) {
            if (it->second > 0) {
                ans += it->first + 1;
            }
        }
        printf("Case %d: %lld\n", t, ans);
    }


    return (0);
}