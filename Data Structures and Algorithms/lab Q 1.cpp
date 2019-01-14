#include <cstdio>

int main()
{
    int matrix[4][4];
    int element;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nEnter an element for search : ");
    scanf("%d", &element);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matrix[i][j] == element)
            {
                printf("Found at row = %d, column = %d", i + 1, j + 1);
                return (0);
            }
        }
    }

    printf("Element not found on given matrix\n");


    return (0);
}
