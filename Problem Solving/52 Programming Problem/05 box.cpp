#include <cstdio>

int main()
{
    int n, item;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &item);
        for(int j = 1; j <= item; j++)
        {
            for(int k = 1; k <= item; k++)
            {
                printf("*");
            }
            putchar('\n');
        }
    }

    return (0);
}
