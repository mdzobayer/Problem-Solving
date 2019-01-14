#include <stdio.h>

int main()
{
    int i=0;
    do{
        i=getchar();
        getchar();
        printf("ASII %d.\n",i);
    }while(i != 'Q');
    printf("\nI'm done\n");
    return 0;
}
