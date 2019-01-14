#include <cstdio>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char input[1000000];
        int numbers = 0;
        gets(input);
        for (int j = 0; input[j] != '\0'; j++)
        {
            if(input[j] == ' ')
            {
                numbers += 1;
            }
        }
        printf("%d\n", numbers + 1);
    }

    return (0);
}
