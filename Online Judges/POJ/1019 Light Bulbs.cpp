#include <bits/stdc++.h>

using namespace std;

int st_d[512] = {}, ed_d[512] = {};
int path[512] = {};
int ret[512] = {}, has = 0;

void trans(char s[], int d[]) {
    int n = strlen(s);
    int v[512] = {};

    for (int i = 0; i < n; ++i) {
        v[i] = s[n-1-i] - '0';
    }

    cout << "V = ";
    for (int i = 0; i < n; ++i) {
            cout <<v[i] << " ";
    }
    cout << endl;

    memset(d, 0, sizeof(v));

    for (int i = 0; ; ++i) {
        int m = 0, zero = 1;
        for(int j = n -1; j >= 0; --j) {
            m = m*10 + v[j];
            zero &= v[j] == 0;
            v[j] = m >>1, m &= 1;
        }
        if (zero) break;

        d[i] = m;
    }
}

int len(int d1[], int d2[]) {
    for (int i = 512-1; i >= 0; --i) {
        if (d1[i] || d2[i])
            return i + 1;
    }
    return 1;
}

int main() {

    freopen("in.txt", "r", stdin);

    char start[128], ed[128];
    while(cin >> start >> ed) {
        if (!strcmp(start, "0") && !strcmp(ed, "0")) break;
        cout << start << " " << ed << endl;

        trans(start, st_d);
        trans(ed, ed_d);

        int n = len(st_d, ed_d);
        cout << "MaxLenth = " << n << endl;

        for (int i = 0; i < n; ++i) {
            cout << st_d[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; ++i) {
            cout << ed_d[i] << " ";
        }
        cout << endl;
    }


    return (0);
}