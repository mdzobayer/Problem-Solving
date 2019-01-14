#include <stdio.h>
int main()
{
    int i,x=0,m;
    char ch;
    printf("Enter how many match: ");
    scanf("%d",m);
    getchar();                  //getchar(); for enter character
    for(i=1;i<=10;i++){
    scanf("%c",&ch);
    getchar();
    printf("%d\n",i);
    switch(ch){
            case 'w':
            x=0;
            printf("Success\n");
            break;
            case 'l':
            x++;
            if(x==3){
                printf("You loss the tournament in match N0: %d",i);
            }
            break;
            case 't':
            x++;
            if(x==3){
                printf("You loss the tournament in match N0: %d",i);
            }
            break;
        }
       // printf("%d",i);
    }
    return 0;
}
