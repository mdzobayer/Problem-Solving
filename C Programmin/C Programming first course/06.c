/*program for adding two array */
#include <stdio.h>

int main()
{
    int a[2][2],b[2][2],c[2][2];
    int i,j;
    for(i=0;i<2;i++)
        for(j=0;j<2;j++)
        {
            printf("Enter Array Number a[%d][%d]=\n",i,j);
            scanf("%d",&a[i][j]);
        }
    for(i=0;i<2;i++)
        for(j=0;j<2;j++){
            printf("Enter Array number b[%d][%d]=\n",i,j);
            scanf("%d",&b[i][j]);
        }
        for(i=0;i<2;i++){
            for(j=0;j<2;j++){
                c[i][j] = a[i][j] + b[i][j];
            }
        }
    printf("Matrix:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%4d",c[i][j]);
            if(j==1){
                printf("\n");
            }
        }
    }
    return 0;
}
