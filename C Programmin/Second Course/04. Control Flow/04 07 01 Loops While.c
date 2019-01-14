#include <stdio.h>

int main()
{
    char i = 0;
    printf("Bet you can't type in a 7\n");
    while(1){       /*while(1) means always true*/
        i=getchar();
        getchar();
        if(i == '7'){
            break;
        }
        printf("Ha! You typed %4c.\n",i);
    }
    printf("I'm done\n");
    return 0;
}
