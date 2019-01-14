#include <stdio.h>

int main(void){
    int k;
    FILE *fp;
    /*fp= fopen("C:/Users/Zobayer/Desktop/output.dat","w");
    for(k=65;k<=90;k++){
        fprintf(fp,"%c\n",k);
    }*/
    fp= fopen("c:/Users/Zobayer/Desktop/output.dat","r");
    k=getc(fp);
    while(k != EOF){
        putchar(k);
        k=getc(fp);
    }
    fclose(fp);

    return 0;
}
