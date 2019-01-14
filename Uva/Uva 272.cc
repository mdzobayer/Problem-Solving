#include <stdio.h>
#include <string.h>

int main()
{
    unsigned int i, count = 0, l;
    char str[100000];
    while(gets(str))
    {
        l = strlen(str);
        for(i = 0; i < l; i++)
        {
            if(str[i] == '"')
            {
                count = count + 1;
                if(count % 2 == 1)
                    printf("``");
                else
                    printf("''");
            }
            else
                printf("%c", str[i]);
        }

    printf("\n");
    }

    return 0;
}
