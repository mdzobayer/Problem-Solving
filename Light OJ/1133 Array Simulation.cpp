#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
    //freopen("in.txt", "r", stdin);

    vector < int > arr;
    string str, s;
    int i, test, t, n, m, x, j, tmp, y;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        arr.clear();
        scanf("%d %d", &n, &m);
        //cout << "n m " << n << " " << m << endl;
        for (i = 0; i < n; ++i) {
            scanf("%d", &x);
            arr.push_back(x);
        }
        getline(cin, s);

        for (i = 0; i < m; ++i) {
            getline(cin, str);
            //cout << "query " << str << endl;
            stringstream ss(str);
            ss >> s;
            if (s == "S") {
                ss >> x;
                for (j = 0; j < n; ++j) {
                    arr[j] += x;
                }
            }
            else if (s == "M") {
                ss >> x;
                for (j = 0; j < n; ++j) {
                    arr[j] *= x;
                }
            }
            else if (s == "D") {
                ss >> x;
                for (j = 0; j < n; ++j) {
                    arr[j] /= x;
                }
            }
            else if (s == "P") {
                ss >> x;
                ss >> y;
                tmp = arr[x];
                arr[x] = arr[y];
                arr[y] = tmp;
            }
            else if (s == "R") {
                reverse(arr.begin(), arr.end());
            }
        }
        printf("Case %d:\n", t);
        for (i = 0; i < n; ++i) {
            if (i > 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    return (0);
}
