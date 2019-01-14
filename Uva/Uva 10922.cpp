#include <cstdio>
#include <cstring>

int main() {

    char num[1010];
    long long int sum, i, range, deg, s;
    while(scanf("%[^\n]", &num) == 1) {
        getchar();
        if (strcmp(num, "0") == 0)
            break;
        deg = sum = 0;
        range = strlen(num);
        for (i = 0; i < range; ++i) {
            sum += (num[i] - '0');
        }
        if (sum % 9 != 0){
            printf("%s is not a multiple of 9.\n", num);
        }
        else {
            deg = 1;
            while (sum > 9) {
                s = 0;
                while(sum > 0) {
                    s += (sum % 10);
                    sum /= 10;
                }
                sum = s;
                ++deg;
            }
            printf("%s is a multiple of 9 and has 9-degree %lld.\n", num, deg);

        }

    }

    return (0);
}
