/*program to display two dimensional array and values taken from keyboard*/
#include <stdio.h>

int main()
{
    int a[2][2];
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
            printf("Enter Array Number a[%d][%d]=\n",i,j);
            scanf("%d",&a[i][j]);
        }
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
            printf("a[%d][%d] = %d\n",i,j,a[i][j]);
    return 0;
}
