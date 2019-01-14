#include <cstdio>

long long int pow(int x, int y) {
    long long int result = x;
    for (int i = 1; i < y; ++i) {
        result *= x;
    }
    return result;
}
int length(long long int n) {
    int len = 0;
    if (n < 0) n *= (-1);
    while(n > 0) {
        ++len;
        n /= 10;
    }
    return len;
}
bool isArm(long long n) {
    if (n < 0) n *= (-1);
    int len = length(n), num;
    long long int sum = 0, temp = n;
    while(n > 0) {
        num = n % 10;
        n /= 10;
        sum += pow(num, len);
    }
    return (temp == sum ) ? true : false;
}
int main() {
    int test;
    long long int n, len;
    scanf("%d", &test);
    while(test--) {
        scanf("%lld", &n);
        if (isArm(n)) {
            puts("Armstrong");
        }
        else {
            puts("Not Armstrong");
        }
    }

    return (0);
}
