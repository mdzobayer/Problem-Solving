//Program to show to system date
#include <stdio.h>
#include <conio.h>
#include <dos.h>

int main()
{

    struct time t;

    gettime(&t);

    printf("Current system date is %d/%d/%d",
           t.ti_hour,t.ti_min,t.ti_sec);

    return (0);
}
