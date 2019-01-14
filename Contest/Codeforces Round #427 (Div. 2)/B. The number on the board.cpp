#include <cstdio>
#include <iostream>

#define ull unsigned long long int
using namespace std;
ull t, k, n, x, y, sum, countDigit[10] = {0};
string s;
ull sumOfDigits() {
    sum = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        sum += s[i] - '0';
        countDigit[s[i] - '0'] += 1;
    }
    return sum;
}
ull digitCount(ull a) {
    ull count = 0;
    while(a > 0) {
        count++;
        a /= 10;
    }
    return count;
}
int main() {

    scanf("%llu", &k);
    getchar();
    getline(cin, s);
    y = sumOfDigits();
    if (y >= k) {
        printf("0\n");
    }
    else {
        n = 0;
        for (x = 0; x <= 9; ++x) {
            for (y = 0; y < countDigit[x]; ++y) {
                if (sum < k) {
                    sum += 9 - x;
                    ++n;
                }
                else {
                    break;
                }
            }
        }
        printf("%llu\n", n);
    }

    return (0);
}
