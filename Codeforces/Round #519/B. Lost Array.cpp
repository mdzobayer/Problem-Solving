#include <bits/stdc++.h>

using namespace std;

int main () {

    int i, n, arr[1000+5], tmp;
    vector < int > vt;

    scanf("%d", &n);
    arr[0] = 0;
    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    //for (k = 1; k <= n; ++k) {
    set < int > st;
        for (i = 1; i <= n; ++i) {
            tmp = arr[i] - arr[i-1];
            st.insert(tmp);
        }
    //}
    printf("%d\n", st.size());
    set < int >::iterator it;
    it = st.begin();
    for ( ; it != st.end(); ++it) {
        printf("%d ", *it);
    }
    printf("\n");

    return (0);
}
