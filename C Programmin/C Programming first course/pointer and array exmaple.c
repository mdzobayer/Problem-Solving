
#include <stdio.h>

int main()
{
    int i;
    int a[5] = {1,2,3,4,5};
    int *p;
    p = a;        //p=&a;

    for(i=0;i<5;i++){
        printf("%4d\n",p);
        p++;
    }
    return 0;
}
