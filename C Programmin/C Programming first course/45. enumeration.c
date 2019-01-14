#include <stdio.h>
enum week{saturday,sunday,monday,tuesday,wednesday,thuesday,friday};

int main()
{
    enum week today;
    today = wednesday;
    printf("Today is %d day of the week",today+1);
    return 0;
}
