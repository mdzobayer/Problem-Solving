#include <bits/stdc++.h>
#define ull unsigned long long int

using namespace std;

ull num[25], tmp, n;

int main() {

    //freopen("in.txt", "r", stdin);

    tmp = 1;
    num[0] = num [1] = 1;
    int i;
    for (i = 2; i < 22; ++i) {
        tmp *= i;
        num[i] = tmp;
        //cout << i << " " << num[i] << endl;
    }
    vector < int > order;
    ull test, t;
    scanf("%llu", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%llu", &n);
        printf("Case %llu: ", t);

        order.clear();

        for (i = 20; i >= 0; --i) {
            if (n >= num[i]) {
                n -= num[i];
                order.push_back(i);
            }
        }

        if (n != 0) {
            printf("impossible\n");
        }
        else {
            i = order.size() - 1;
            printf("%d!", order[i]);
            for (--i; i >= 0; --i) {
                printf("+%d!", order[i]);
            }
            puts("");
        }
    }

    return (0);
}
