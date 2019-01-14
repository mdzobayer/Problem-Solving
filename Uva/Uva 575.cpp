#include <cstdio>
#include <cstring>
#include <cmath>

int main() {

    unsigned long long int len, sum, remind, power;
    char number[50];
    while(scanf("%s", &number) == 1) {
        getchar();
        if (strcmp(number, "0") == 0)
            break;
        len = strlen(number);
        power = 1;
        sum = 0;
        while(len) {
            --len;
            remind = number[len] - '0';
            sum += (remind * (pow(2, power) - 1));
            ++power;
        }
        printf("%llu\n", sum);
    }

    return (0);
}
