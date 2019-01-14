#include <stdio.h>
int main(){
    FILE *ptr;
    ptr=fopen("c:/Users/Zobayer/Desktop/C File IO/Zobayer.txt","w");
    char name[10]="Zobayer";
    fprintf(ptr,"The message for you %s\nI am hacked.",name);
    fclose(ptr);

    return 0;
}
