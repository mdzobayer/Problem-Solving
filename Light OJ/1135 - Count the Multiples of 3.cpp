#include <bits/stdc++.h>

using namespace std;
int n;
struct pos {
    int zeros, ones, twos;
}BITree[100000+10];

int getSum(int BITree[], int index) {
    int sum = 0;

    index = index + 1;

    while (index > 0) {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}


void updateBIT(int n, int index) {
    index = index + 1;
    int tmp;
    while (index <= n) {
        tmp = BITree[index].twos;
        BITree[index].twos = BITree[index].ones;
        BITree[index].ones = BITree[index].zeros;
        BITree[index].zeros = tmp;

        index += index & (-index);
    }
}

int main() {

    return (0);
}
