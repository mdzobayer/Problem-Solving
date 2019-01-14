#include <bits/stdc++.h>


using namespace std;

int arr[100000+5];

int maxVal(int x, int y) {
    return (x > y) ? x : y;
}

int minVal(int x, int y) {
    return (x < y) ? x : y;
}

int getMid(int s, int e) {
    return s + (e - s) / 2;
}

/// Max Value
int RMQUtil(int *st, int ss, int se, int qs, int qe, int si) {

    /// Node is a part of given range
    if (qs <= ss && qe >= se) {
        return st[si];
    }

    /// If query goes outside from index
    if (se < qs || ss > qe) return INT_MAX;

    /// Segment overlap with given range
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2 * si + 1),
                  RMQUtil(st, mid + 1, se, qs, qe, 2 * si + 2));

}

int RMQ(int *st, int n, int qs, int qe) {

    if (qs < 0 || qe > n - 1 | qs > qe) {
        return -1;  /// Invalid
    }
    return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil (int ss, int se, int *st, int si) {
    /// If there is one element
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    /// If there are more then one element
    int mid = getMid(ss, se);
    st[si] = minVal(constructSTUtil( ss, mid, st, si * 2 + 1),
             constructSTUtil( mid + 1, se, st, si * 2 + 2));
    return st[si];
}
/// Allocate memory for segment tree
int *constructST(int n){

    /// Height of segment tree
    int x = (int) (ceil(log2(n)));

    /// Maximum size of segment tree
    int max_size = 2 * (int) pow(2, x) - 1;

    /// Allocate memory
    int *st = new int[max_size];

    /// Fill the allocate memory st
    constructSTUtil(0, n - 1, st, 0);
    return st;
}


/// Max Value

int RMQUtilM(int *st, int ss, int se, int qs, int qe, int si) {

    /// Node is a part of given range
    if (qs <= ss && qe >= se) {
        return st[si];
    }

    /// If query goes outside from index
    if (se < qs || ss > qe) return INT_MIN;

    /// Segment overlap with given range
    int mid = getMid(ss, se);
    return maxVal(RMQUtilM(st, ss, mid, qs, qe, 2 * si + 1),
                  RMQUtilM(st, mid + 1, se, qs, qe, 2 * si + 2));

}

int RMQM(int *st, int n, int qs, int qe) {

    if (qs < 0 || qe > n - 1 | qs > qe) {
        return -1;  /// Invalid
    }
    return RMQUtilM(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtilM ( int ss, int se, int *st, int si) {
    /// If there is one element
    if (ss == se) {
        st[si] = arr[ss];
        return arr[ss];
    }
    /// If there are more then one element
    int mid = getMid(ss, se);
    st[si] = maxVal(constructSTUtilM( ss, mid, st, si * 2 + 1),
             constructSTUtilM( mid + 1, se, st, si * 2 + 2));
    return st[si];
}
/// Allocate memory for segment tree
int *constructSTM( int n){

    /// Height of segment tree
    int x = (int) (ceil(log2(n)));

    /// Maximum size of segment tree
    int max_size = 2 * (int) pow(2, x) - 1;

    /// Allocate memory
    int *st = new int[max_size];

    /// Fill the allocate memory st
    constructSTUtilM( 0, n - 1, st, 0);
    return st;
}

int main() {

    //freopen("in.txt", "r", stdin);

    int test, t, n, d, i, mn, dis, x, y;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &n, &d);

        for (i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        int * st = constructST(n);
        int * stm = constructSTM(n);
        x = RMQ(st, n, 0, d-1);
        y = RMQM(stm, n, 0, d-1);
        //cout << x << " " << y << endl;
        dis = abs(x - y);
        //cout << RMQ(st, n, 0, d-1) << endl;
        //cout << RMQM(stm, n, 0, d-1) << endl;
        for (i = d; i < n; ++i) {
            x = RMQ(st, n, i-d+1, i);
            y = RMQM(stm, n, i-d+1, i);
            //cout << x << " " << y << endl;
            dis = max(dis, abs(x - y));
        }
        printf("Case %d: %d\n", t, dis);
        delete [] st;
        delete [] stm;
    }

    return (0);
}
