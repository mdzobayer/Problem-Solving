#include <bits/stdc++.h>

using namespace std;

int arr[30000+5], n;
int mark[1000000+5];
int N[30000+5];

vector < pair < int , int > > result;
/// end - start - id
vector < pair < int, pair < int, int > > > vt;

set < int > st;

void update(int x, int value) {
    while(x <= n) {
        N[x] += value;
        x += x & (-x);
    }
}

int getSum(int x) {
    int sum = 0;
    while (x > 0) {
        sum += N[x];
        x -= x & (-x);
    }
    return sum;
}


int main() {

    //freopen("in.txt", "r", stdin);

    int i, q, query, x, y, toReduce;

    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    scanf("%d", &query);
    for (q = 0; q < query; ++q) {
        scanf("%d %d", &x, &y);
        vt.push_back(make_pair(y, make_pair(x, q) ));
    }
    sort(vt.begin(), vt.end());

    memset(mark, -1, sizeof(mark));
    memset(N, 0, sizeof(N));


    int size1, size2, len = vt.size();

    st.clear();

    x = 0, y = vt[0].second.first;

    for (i = 1; i < y; ++i) {
        size1 = st.size();
        st.insert(arr[i]);
        size2 = st.size();

        if(size1 == size2) {
            toReduce = mark[ arr[i] ];
            update(toReduce, -1);
        }
        update(i, 1);
        mark[ arr[i] ] = i;
    }

    x = vt[0].second.first;
    y = vt[0].first;

    for (x ; x <= y; ++x) {
            size1 = st.size();
            st.insert(arr[x]);
            size2 = st.size();

            if(size1 == size2) {
                toReduce = mark[ arr[x] ];
                update(toReduce, -1);
            }
            update(x, 1);
            mark[ arr[x] ] = x;
    }
    //cout << "Q: " << vt[0].second << " " << vt[0].first << " R: ";
    int res = getSum(vt[0].first) - getSum(vt[0].second.first - 1);
    result.push_back(make_pair(vt[0].second.second, res));


    for (i = 1; i < len; ++i) {
        //x = max(vt[i].second, vt[i-1].first);

        x = vt[i-1].first + 1;
        y = vt[i].first;

        for (x ; x <= y; ++x) {
            size1 = st.size();
            st.insert(arr[x]);
            size2 = st.size();

            if(size1 == size2) {
                toReduce = mark[ arr[x] ];
                update(toReduce, -1);
            }
            update(x, 1);
            mark[ arr[x] ] = x;

        }
        //cout << "Q: " << vt[i].second << " " << vt[i].first << " R: ";
        res = getSum(vt[i].first) - getSum(vt[i].second.first - 1 );
        result.push_back(make_pair(vt[i].second.second, res));
    }
    sort(result.begin(), result.end());
    for (i = 0; i < len; ++i) {
        printf("%d\n", result[i].second);
    }

    return (0);
}
