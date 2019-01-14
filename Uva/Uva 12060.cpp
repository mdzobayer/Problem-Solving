#include <cstdio>

int lengthOfInteger(int i) {
    int len = 0;
    while(i > 0) {
        i /= 10;
        ++len;
    }
    return len;
}

int gcd (int n1, int n2) {
    int d, i;
    for (i = 1; i <= n1 && i <= n2; ++i) {
        if ((n1 % i == 0) && (n2 % i == 0))
            d = i;
    }
    return d;
}
int max (int i, int j) {
    if ( i < j) return j;
    else return i;
}

int main() {

    int sum, number, length, i, cas = 1, d, tab;
    while(scanf("%d", &length) == 1) {
        if (length == 0)
            break;
        sum = 0;
        for (i = 0; i < length; ++i) {
            scanf("%d", &number);
            sum += number;
        }
        printf("Case %d:\n", cas++);
        if ((sum / length) < 1 && ((sum % length) != 0)) {
            bool flag = true;
            d = gcd(sum % length, length);
            if (sum < 0) {
                flag = false;
            }
            tab = max (lengthOfInteger((sum % length) / d), lengthOfInteger(length / d));
            if (flag)
                printf("%d\n", (sum % length) / d);
            else {
                printf("  ");
                int l = lengthOfInteger((sum % length) / d);

            }

            for (i = 0; i < tab; ++i) {
                printf("-");
            }
            printf("\n%d\n", length / d);
        }
        else if (sum % length == 0){
            if (sum < 0) {
                printf("- ");
                sum *= -1;
            }
            printf("%d\n", sum / length);
        }
    }

    return (0);
}
