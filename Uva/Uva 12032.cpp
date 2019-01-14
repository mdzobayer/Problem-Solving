#include <cstdio>
#include <cstdlib>
#include <cmath>

long long int arr[100010];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    long long int test, i, t, n, Max, MaxCount, k;

    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld", &n);
        for (i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
        }
        Max = arr[0];
        k = Max;
        --k;
        MaxCount = 0;
        //printf(" ");
        for (i = 0; i < n - 1; ++i) {
            if (abs(arr[i] - arr[i + 1]) > Max) {
                Max = abs(arr[i] - arr[i + 1]);
                k = Max;
                --k;
            }
            else if (abs(arr[i] - arr[i + 1]) == k) {
                k--;
            }
            else if (abs(arr[i] - arr[i + 1]) == Max && k < Max) {
                ++Max;
                k = Max;
                //--k;
            }
            else if (abs(arr[i] - arr[i + 1]) > k) {
                ++Max;
                k = Max;
            }
            //printf("%lld ", arr[i+1] - arr[i]);
        }
        printf("Case %lld: %lld\n", t, Max);
    }

    return (0);
}
