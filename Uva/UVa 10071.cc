/// Back to High School Physics

#include<stdio.h>

int main()
{
    int velocity, time;
    while (scanf("%d %d",&velocity, &time) == 2)
    {
        if ((velocity >= -100) && (velocity <= 100) && (time >= 0) && (time <= 200)){
            printf("%ld\n",2 * velocity * time);
        }
    }

    return 0;
}
