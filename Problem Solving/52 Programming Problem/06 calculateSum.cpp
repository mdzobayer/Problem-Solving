#include <cstdio>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int sum = 0, item;
        scanf("%d", &item);
        for (int j = 5; j > 0; j--)
        {
            if (j == 5)
            {
                sum += item % 10;
            }
            if (j == 1)
            {
                sum += item % 10;
            }
            item /= 10;
        }
        printf("Sum = %d\n", sum);
    }

    return (0);
}
