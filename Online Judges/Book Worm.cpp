#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int

using namespace std;

struct segment {
    ll left, right;
    bool operator < (segment s) {
        if (this->left )
    }
};
int main() {

    ll n, m, i;

    segment tmp;

    vector < segment > vt;

    scanf("%lld %lld", &n, &m);
    vt.clear();
    for (i = 0; i < m; ++i) {
        scanf("%lld", &tmp.left);
        scanf("%lld", &tmp.right);
        vt.push_back(tmp);
    }

    return (0);
}
