#include <cstdio>

int main()
{
    int n;
    unsigned long long int number, result;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        result = 1;
        scanf("%llu", &number);
            while ( number > 1) {
            result *= number;
            --number;
        }
        printf("%llu\n", result);
    }

    return (0);
}
