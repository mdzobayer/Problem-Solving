#include <bits/stdc++.h>
#define LLI long long int
using namespace std;

LLI kth[10000+10];

bool is10(LLI k) {
    int sum = 0;
    while(k > 0) {
        sum += (k % 10);
        if(sum > 10) return false;
        k /= 10;
    }
    if (sum == 10) return true;
    return false;
}

int main() {

    LLI sum, i, k = 1;

    for (i = 1; i < 10000+10; ++i) {
        while(!is10(k)) {
            ++k;
        }
        //printf("%lld %lld\n", i, k);
        kth[i] = k;
        ++k;
    }
    scanf("%lld", &sum);
    printf("%lld\n", kth[sum]);


    return (0);
}
