#include <cstdio>
#include <cstring>

int main()
{
    char a[107];
    int n, sum, j,t,i;
    scanf("%d", &t);
    getchar();
    for(i = 1;i <= t; i++)
    {
        gets(a);
        sum = 0;
        for(j = 0; a[j]; j++)
        {
            if((a[j]=='a')||(a[j]=='d')||(a[j]=='g')||(a[j]=='j')||(a[j]=='m')||(a[j]=='p')||(a[j]=='t')||(a[j]=='w')||(a[j]==' '))
                sum += 1;
            else if((a[j]=='b')||(a[j]=='e')||(a[j]=='h')||(a[j]=='k')||(a[j]=='n')||(a[j]=='q')||(a[j]=='u')||(a[j]=='x'))
                sum += 2;
            else if((a[j]=='c')||(a[j]=='f')||(a[j]=='i')||(a[j]=='l')||(a[j]=='o')||(a[j]=='r')||(a[j]=='v')||(a[j]=='y'))
                sum += 3;
            else if((a[j]=='s')||(a[j]=='z'))
                sum += 4;
        }
        printf("Case #%d: %d\n", i, sum);
    }

    return 0;
}
