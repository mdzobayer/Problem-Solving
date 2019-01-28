
#include <bits/stdc++.h>

using namespace std;

int digitSum(int x) {
    int sum = 0;
    while(x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int digitalRoot(int x) {

    while(x > 9) {
        x = digitSum(x);
    }
    return x;
}


int main() {

    long long int i, n, x, k, c;

    cin >> n;
    while(n--) {
        cin >> k >> x;
        c = 0;
        for (i = 1; i <= 1000000000000; ++i) {
            if(digitalRoot(i) == x) {
                ++c;
            }
            if(c >= k) {
                cout << i << endl;
                break;
            }
        }

    }

    return (0);
}
