#include <stdio.h>
int main()
{
    int m,i,x;
    char ch,c;
    printf("Enter how many match: ");
    scanf("%d",&m);
    getchar();
    //printf("%d",m);
    for(i=0;i<m;i++){
        printf("Enter result: ");
        scanf("%c",&ch);
        getchar();
        printf("You type %c\n",ch);
  //putchar(ch);

    }
    return 0;
}
