#include <stdio.h>

int main()
{
    int i = 0;
    do{
        i=getchar();
        getchar();
        if(i == 'X')
            continue;
        printf("ASCII %d.\n",i);
    }while(i !='Q');
    printf("\nI'm done\n");
    return 0;
}
