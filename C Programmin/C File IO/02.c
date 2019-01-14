#include <stdio.h>

int main(void){
    char k;
    FILE *ptr;
    ptr=fopen("c:/Users/Zobayer/Desktop/C File IO/01.txt","r");

    k = getc(ptr);
    while(k != -1){
        putchar(k);
        k=getc(ptr);
    }
    fclose(ptr);
    printf("\n\n");
    return 0;
}
