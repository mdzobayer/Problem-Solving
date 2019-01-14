#include <bits/stdc++.h>

using namespace std;

int arr[200000+5];

int main() {
    set < int > st;
    int n, i, x, j;

    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int curr = 0, sz;
    for (i = 0; i < n; ++i) {
        scanf("%d", &x);
        /// find in set
        sz = st.size();
        st.insert(x);
        if(sz == st.size()) {
            //cout << "Here" << endl;
            printf("0 ");
            continue;
        }

        for (j = curr; j < n; ++j) {
            if(arr[j] != x) {
                st.insert(arr[j]);
            }
            else {
                st.insert(arr[j]);
                printf("%d ", j - curr + 1);
                curr = j + 1;
                break;
            }
        }
    }
    printf("\n");


    return (0);
}
