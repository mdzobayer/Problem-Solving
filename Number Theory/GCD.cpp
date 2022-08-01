#include <bits/stdc++.h>

using namespace std;

int gcdNaive(int a, int b) {
    int m = min(a,b);
    for (int i = m; i > 0; --i) {
        if (a % i == 0 && b % i == 0) {
            return 1;
        }
    }
}

int gcdEuclid(int a, int b) {
    if (b == 0) return a;

    return gcdEuclid(b, a % b);
}


int main() {



    return (0);
}