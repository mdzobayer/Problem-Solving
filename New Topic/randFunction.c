#include <stdio.h>
#include <stdlib.h>
int rand(void);

int main(void){
    int i;
    for(i=0;i<10;i++)
        printf("%d\n",rand() % 100);
    return EXIT_SUCCESS;
}
