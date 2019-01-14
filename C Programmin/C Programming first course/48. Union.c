/*program for union*/
#include <stdio.h>

union job
{
    char name[5];
    //float salary;
    int worker_no;
}u;

struct job1
{
    char name;
    double text;
    int salary;
    float worker_no;
    char example[4];
    float test;
}s;

int main()
{
    //union job u;
    //struct job1 s;
    printf("Size of Union is : %d\n",sizeof(u));
    printf("Size of Structure is : %d\n\n",sizeof(s));
    printf("Size of float is : %d\n",sizeof(float));
    printf("Size of int is : %d\n",sizeof(int));
    printf("Size of double is : %d\n",sizeof(double));
    printf("Size of char is : %d\n",sizeof(s.name));
    printf("Size of Structure is : %d\n",sizeof(s));
    printf("");
    return 0;
}
