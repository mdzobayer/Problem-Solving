#include <stdio.h>
#include <string.h>

struct student
{
    int id;
    char name[20];
    float percentage;
};

int main()
{
    struct student record = {1,"john",85.5};
    struct student *ptr;
    ptr = &record;

    printf("ID is : %d\n", ptr->id);
    printf("Name is : %s\n", ptr->name);
    printf("Percentage is : %0.2f\n", ptr->percentage);

    return 0;
}
