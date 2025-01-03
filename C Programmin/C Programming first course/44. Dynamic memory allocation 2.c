
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *a;
    //memory is allocated dynamically
    a = calloc(20, sizeof(char));
    if(a==NULL)
    {
        printf("couldn't able to allocate requested memory\n");
    }
    else
    {
        strcpy(a,"dynamic memory allocation");
    }
    printf("Dynamically allocated memory content : %s\n",a);


    a = realloc(a,100 * sizeof(char));
    if(a==NULL)
    {
        printf("couldn't able to allocate requested memory\n");
    }
    else
    {
        strcpy(a,"dynamic memory allocation");
    }
    printf("Dynamically reallocated memory content : %s\n",a);

    free(a);

    return 0;
}
