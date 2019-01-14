#include <bits/stdc++.h>

using namespace std;
set < int > st;
int main() {

    int time = 0, i, n, x;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        if (x)
            st.insert(x);
    }
    time = st.size();
    cout << time << endl;

    return (0);
}
