#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n, i, arr[210], m;

    scanf("%d", &n);
    m = n * 2;
    for (i = 0; i < m; ++i) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + m);

    if (arr[n - 1] < arr[n]) {
        printf("YES\n");
    }
    else printf("NO\n");


    return (0);
}
