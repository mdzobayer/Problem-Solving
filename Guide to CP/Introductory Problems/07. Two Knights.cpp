#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long int 

ull Permutation(int n) {
    ull ans = 0, totalBlocks = n * n;
    ull sixBlocks, fourBlocks, threeBlocks, twoBlocks, eightBlocks;

    sixBlocks = (n - 4);
    fourBlocks = sixBlocks + 4;
    threeBlocks = 8;
    twoBlocks = 4;

    eightBlocks = totalBlocks - (sixBlocks + fourBlocks + threeBlocks + twoBlocks);

    ans += (twoBlocks * (totalBlocks - twoBlocks - 1));
    ans += (threeBlocks * (totalBlocks - threeBlocks - 1));
    ans += (fourBlocks * (totalBlocks - fourBlocks - 1));
    ans += (sixBlocks * (totalBlocks - sixBlocks - 1));
    ans += (eightBlocks * (totalBlocks - eightBlocks - 1));

    ans *= 2;

    return ans;
}

int main() {

    int n, i;
    scanf("%d", &n);

    for (i = 5; i <= n; ++i) {
        cout << Permutation(i) << endl;
    }

    return (0);
}