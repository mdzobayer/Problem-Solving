#include <bits/stdc++.h>

using namespace std;

int arr[200000+5];
set<int> st;

int main() {

    //freopen("in.txt", "r", stdin);

    int test, n, i, oldSize;
    cin >> test;
    while(test--) {
        cin >> n;

        for (i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        st.clear();
        
        for (i = n-1; i >= 0; --i) {
            oldSize = st.size();

            st.insert(arr[i]);

            if (oldSize == st.size()) break;
        }

        cout << i + 1 << endl;
    }

    return (0);
}