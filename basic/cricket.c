#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tn,m,match,won_nu=0,los_nu=0,match_result;

    label:printf("\t-----Read Carefully-----\n");
    printf("When you win a match Type :\t1\n");
    printf("When you loses a match Type :\t2\n\n");

    printf("Enter How Many match: ");
    scanf("%d",&match);
    tn=0;
    for(m=0;m<match;m++){

        printf("Enter Match Result: ");
        scanf("%d",&match_result);

        switch(match_result)
        {
            case 1:
            won_nu+=1;
            break;

            case 2:
            los_nu+=1;
            if(los_nu==3){
                printf("\n\n\t----Summary----");
                printf("\nYou loses the tornament No: %d in Match No: %d match\n\n",tn+1,m+1);
                exit(0);
            }
            break;

            default:

                printf("\n\t---Wrong input try again---\n\n");
                goto label;


        }
    }
    printf("\n\n\t---- No:%d Turnament Summary----",tn+1);
    printf("\nYou won %d Match and loses %d Match\n\n",won_nu,los_nu);


    printf("\n\n\t-----Congratulation------");
    printf("\n\nYou pass the turnament \n\n");
    return 0;

}
