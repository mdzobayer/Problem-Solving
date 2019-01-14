#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define lli long long int

using namespace std;

vector<lli> dq;

lli arr[1000000 + 5];
bool isUse[1000000 + 5];

int main() {

    freopen("in.txt", "r", stdin);

    lli test, n, i, j, maxSum, index;
    scanf("%lld", &test);
    while(test--) {
        dq.clear();
        maxSum = 0;
        memset(isUse, 1, sizeof(isUse));
        scanf("%lld", &n);
        for (i = 0; i < n; ++i) {
            scanf("%lld", &arr[i]);
            dq.push_back(arr[i]);
        }

        sort(dq.begin(), dq.end());
        lli Back = n - 1;
        for (i = 0; i < n; ++i) {
            //printf("Dq Back is %lld %lld\n", Back, dq[Back]);
            if (arr[i] < dq[Back]) {
                maxSum += (dq[Back] - arr[i]);
                isUse[i] = 0;
                //printf("Hello\n");
            }
            else {
                //dq.pop_back();
                --Back;
                while(!isUse[Back] && Back >= 0){
                    isUse[dq[Back]] = 0;
                    --Back;
                }
            }
        }
        printf("%lld\n", maxSum);
    }

    return (0);
}
