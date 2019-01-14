#include <cstdio>
long long int a, b, c, d, l, count, temp;

bool isDivisible (const long long int & x) {
    temp = (a * (x * x)) + (b * x) + c;
    if (temp % d == 0) return true;
    else return false;
}

int main() {

    while(scanf("%lld %lld %lld %lld %lld", &a, &b, &c, &d, &l) == 5) {
        if ( a == 0 && b == 0 && c == 0 && d == 0 && l == 0)
            break;
        count = 0;
        for (size_t i = 0; i <= l; ++i) {
            if (isDivisible(i))
                ++count;
        }
        printf("%lld\n", count);
    }

    return (0);
}
/**
0 0 10 5 100
0 0 10 6 100
1 2 3 4 5
1 2 3 3 5
0 0 0 0 0
**/
