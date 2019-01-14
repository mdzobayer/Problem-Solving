#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Seed rand() with the system time
and display first 10 numbers.
*/

int main(void)
{
    int i,stime;
    long ltime;
    //get the current calendar time

    ltime = time(NULL);
    stime = (unsigned) ltime/2;
    srand(stime);

    for(i=0;i<10;i++)
        printf("%d\n",rand);

    return 0;
}
