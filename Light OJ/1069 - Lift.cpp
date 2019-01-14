#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {

    ll time = 0;
    int test, t, lift, person;
    scanf("%d", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%d %d", &person, &lift);
        time = 0;
        time += abs(person - lift) * 4;
        time += 11;
        time += abs(person - 0) * 4;
        time += 8;
        printf("Case %d: %lld\n", t, time);
    }

    return (0);
}
