#include <bits/stdc++.h>

using namespace std;

int main() {

    int test, a, b;
    float ans1, ans2;
    cin >> test;
    while(test--) {
        cin >> a >> b;

        ans1 = sqrt((b*b) - (a*a));
        ans2 = sqrt((b*b) + (a*a));

        printf("%0.5f %0.5f\n", ans1, ans2);
    }

    return (0);
}
