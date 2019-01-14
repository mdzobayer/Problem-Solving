/*program to display single dimensional array*/
#include <stdio.h>

int main()
{
    int i;
    int age[5] = {2,3,4,5,6};

    for(i=0;i<5;i++)
        printf("Value in age[%d] is %d\n",i,age[i]);
    return 0;
}
