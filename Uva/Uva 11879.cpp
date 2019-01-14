#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <cmath>

#define MAX 1010

long long int division(char * number, long div) {
    int len = strlen(number);
    int now;
    long long int extra;
    //char Res[MAX];
    for (now = 0, extra = 0; now < len; ++now) {
        extra = extra * 10 + (number[now] - '0');
        //Res[now] = extra / div + '0';
        extra %= div;
    }
    //Res[now] = '\0';
    return extra;
}

int main() {

    char num[MAX];
    long long int remainder;
    while(scanf("%s", &num)) {
        getchar();
        if (strcmp(num, "0") == 0)
            break;
        remainder = division(num, 17);
        if (remainder == 0)
            printf("1\n");
        else
            printf("0\n");
    }

    return (0);
}
