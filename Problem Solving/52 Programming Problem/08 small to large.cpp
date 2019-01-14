#include <cstdio>

void Swap (int &num1, int &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int num1, num2, num3, temp;
        scanf("%d%d%d", &num1, &num2, &num3);
        if (num1 > num2)
        {
            Swap(num1, num2);
        }
        if (num1 > num3)
        {
            Swap(num1, num3);
        }
        if (num2 > num3)
        {
            Swap(num2, num3);
        }
        printf("Case %d: %d %d %d\n",i + 1, num1, num2, num3);
    }

    return (0);
}
