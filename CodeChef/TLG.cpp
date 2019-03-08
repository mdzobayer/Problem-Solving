#include <bits/stdc++.h>

using namespace std;

vector < pair < int, int > > res;
pair < int, int > r;

int main() {

    int test, t, a, b, p1, p2;
    p1 = p2 = 0;
    scanf("%d", &test);
    for (t = 0; t < test; ++t) {
        scanf("%d %d", &a, &b);
        p1 += a;
        p2 += b;

        if (p1 > p2) {
            res.push_back(make_pair(p1 - p2, 1));
        }
        else 
            res.push_back(make_pair(p2 - p1, 2));
    }
    sort(res.begin(), res.end());
    r = res.back();

    cout << r.second << " " << r.first << endl;


    return (0);
}