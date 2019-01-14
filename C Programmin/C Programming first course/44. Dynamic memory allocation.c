
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *a;
    //memory is allocated dynamically
    a = malloc(20 * sizeof(char));
    if(a==NULL)
    {
        printf("couldn't able to allocate requested memory\n");
    }
    else
    {
        strcpy(a,"dynamic memory allocation");
    }
    printf("Dynamically allocated memory content : %s\n",a);
    free(a);

    return 0;
}
