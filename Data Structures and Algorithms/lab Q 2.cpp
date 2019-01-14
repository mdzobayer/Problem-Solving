#include <cstdio>

int main()
{

    const char s[] = "CSEDEPT%";

    char st[1024];

    gets(st);
    int i = 0;
    while(st[i] != '\0')
    {
        if (st[i] == ' ')
        {
            printf("%s",s);
            i++;
            continue;
        }
        else
        {
            putchar(st[i]);
        }
        i++;
    }

    return (0);
}
