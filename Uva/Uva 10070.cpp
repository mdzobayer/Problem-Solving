#include <cstdio>

int main() {

    long long int year;
    while(scanf("%lld", &year) == 1) {
        if ((year % 4 == 0) && (year % 100 != 0)) {
            printf("This is leap year.\n\n");
        }
        else if (year % 400 == 0) {
            printf("This is leap year.\n\n");
        }
        else if (year % 15 == 0) {
            printf("This is huluculu festival year.\n\n");
        }
        else if (year % 55 == 0) {
            printf("This is bulukulu festival year.\n\n");
        }
        else
            printf("This is an ordinary year.\n\n");
    }

    return (0);
}
