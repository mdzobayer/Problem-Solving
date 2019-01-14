/*program to display total marks using array*/
#include <stdio.h>

int main(){
    int marks[10],i,n,sum = 0;
    printf("Enter Number of subjects: \t");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter marks of subject NO %d:\t",i+1);
        scanf("%d",&marks[i]);
        sum+=marks[i];
    }
    printf("Total Marks = %d",sum);
    return 0;

}
