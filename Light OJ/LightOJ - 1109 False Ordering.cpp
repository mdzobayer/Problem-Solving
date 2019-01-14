#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    vector<int> vt;
    vt.push_back(0);
    vt.push_back(1);
    int i, n = 995, div, j, arr[1010], sol[1010] = {0}, Max;
    for (j = 1; j <= 1005; ++j) {
        div = 0;
        for (i = 1; i <= j / 2;  ++i) {
            if (j % i == 0) {
                div++;
            }
        }
        arr[j] = ++div;
        if (sol[div] < j)
            sol[div] = j;
    }
    Max = 0;
    for (i = 1; i <= 1000; ++i) {
        if (arr[i] > Max)
            Max = arr[i];
    }
    for (j = 2; j <= Max; ++j) {
        for (i = 1000; i >= 1; --i) {
            if (arr[i] == j) {
                vt.push_back(i);
            }
        }
    }
    int test,input;
    scanf("%d", &test);
    for(int t = 1; t <= test; ++t) {
        scanf("%d", &input);
        printf("Case %d: %d\n", t, vt[input]);
    }

    return (0);
}
