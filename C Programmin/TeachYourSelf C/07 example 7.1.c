#include <stdio.h>

int count;
int *init(int x)
{
    count = x;

    return &count;
}

int main() {

    int* p;
    p = init(110);
    *p = 12;
    printf("Count (through p) is %d\n", *p);

    return (0);
}
