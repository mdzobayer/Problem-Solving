#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i=0,x,tu,h,match;
    char ch;
    printf("Enter how many tournament: ");
    scanf("%d",&tu);
    getchar();

    for(h=0;h<tu;h++){

    printf("\n----- Tournament NO:%d -----\n\n",h+1);
    printf("Enter how many match: ");
    scanf("%d",&match);
    getchar();
    lebel:
    printf("\n\t-----Read Carefully-----\n\n");
    printf("Win a match type: w\n");
    printf("Lose a match type: l\n");
    printf("Tie a match type: t\n");
    printf("All the character must be lowercase. \n\n");
    x=0;
    for(i=1;i<=match;i++){
        printf("Match Result: ");
        scanf("%c",&ch);
        getchar();
        switch(ch){
            case 'w':
            x=0;
            break;

            case 'l':

                x++;
                if(x==3){
                    printf("\n\nYou loss the tournament in match N0: %d\n",i);
                    break;
                }
                break;

            case 't':
                x++;
                if(x==3){
                    printf("\n\nYou loss the tournament in match N0: %d\n",i);
                    break;
                }
                break;

            default:
                printf("\t-----Wrong Input-----\n\tPlease Try Again\n\n");
                goto lebel;

        }

        if(x==3){
            break;
        }
    }
    if(x==3){
        continue;
    }
    printf("\nYou Pass the tournament No:%d \n",h+1);
    }
    return 0;
}
