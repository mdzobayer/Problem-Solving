#include <stdio.h>

int main()
{
    int i = 1;

    for(i;i<=10;i++){
        if(i == 5){
            continue;
        }
        printf("I am Number %d\n",i);
    }
    printf("\nI'm done\n");

    return 0.00;
}
