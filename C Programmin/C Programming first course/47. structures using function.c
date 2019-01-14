#include <stdio.h>
struct student
{
    char name[50];
    int roll;
};

void Display(struct student sr);

int main()
{
    struct student s1;
    printf("Enter student's name: ");
    scanf("%s",&s1.name);
    printf("Enter student's roll: ");
    scanf("%d",&s1.roll);
    Display(s1);
    return 0;
}

void Display(struct student sr)
{
    printf("%s\n",sr.name);
    printf("%d\n",sr.roll);
}
