#include <stdio.h>

int main() {

    int answer, i;
    for(i = 1; i < 11; i++) {
        printf("What is %d + %d ? : ",i , i);
        scanf("%d",&answer);
        if (answer == i + i){
            printf("Right\n");
        }
        else {
            printf("Sorry, You're wrong.\n");
            printf("The answer is %d\n",i + i);
        }
    }

    return (0);
}
