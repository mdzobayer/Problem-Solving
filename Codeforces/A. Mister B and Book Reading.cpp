#include <bits/stdc++.h>

using namespace std;

int main() {

    int c, l, v0, v1, a, days = 0, cap;

    scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);

    while(c > 0) {
        ++days;
        if (days > 1) {
            cap = (v0 + (a*(days-1)));
            if (cap > v1) {
                cap = v1;
            }
            c -= (cap - l);
        }
        else
            c -= v0;
    }
    printf("%d\n", days);

    return (0);
}
