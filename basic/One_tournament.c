#include <stdio.h>
#include <stdlib.h>

int main()
{
    int match,x,result,MNumber=0,win_MNumber=0,los_MNumber=0;
    char w,l,t,result;
    printf("Enter how many match: ");
    scanf("%d",&match);
    printf("Type w for win.\nType l for lose.\nType t for tie.\nAll input character must be lowercase\n");
    for(x=0,x<match;x++){
        printf("Enter match result: ");
        scanf("%c",&result);
        MNumber+=1;
        if(MNumber==match){}
        switch(result){
            case 'w':
                win_MNumber+=1;
                break;

            case 'l':
                los_MNumber+=1;
                printf("Enter match result: ");
                scanf("%c",&result);
                MNumber+=1;
                if(MNumber==match){}
                if(result=='l'){
                    los_MNumber+=1;
                    printf("Enter match result: ");
                    scanf("%c",&result);
                    MNumber+=1;
                    if(MNumber==match){}
                    if(result=='l'){
                        printf("Enter match result: ");
                        scanf("%c",&result);
                    }
                }
                if else(result=='t'){
                    tie
                }
        }
    }

}
