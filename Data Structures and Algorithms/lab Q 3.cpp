#include <cstdio>

int main()
{
    char st[1024];

    gets(st);
    int a = 0, b = 0, c = 0;
    int i = 0;
    while(st[i])
    {
        while(st[i] == 'a')
        {
            i++;
            a += 1;
            //continue;
        }
        if (a > 0)
        {
            printf("a%d", a);
            a = 0;
        }
        while(st[i] == 'b')
        {
            i++;
            b += 1;
            //continue;
        }
        if (b > 0)
        {
            printf("b%d", b);
            b = 0;
        }
        while(st[i] == 'c')
        {
            i++;
            c += 1;
            //continue;
        }
        if (c > 0)
        {
            printf("c%d", c);
            c = 0;
        }
        //i++;

    }


    return (0);
}
