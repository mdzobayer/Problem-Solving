#include <cstdio>


int strlen(char arr[])
{
    int i = 0;
    while (arr[i] != '\0')
    {
        ++i;
    }
    return ++i;
}

int patternMatch(char p[], char t[])
{
    int r = strlen(p) - 1;
    int s = strlen(t) - 1;
    int k = 1;
    int Max = s - r + 1;
    while( k <= Max)
    {
        for (int l = 0; l <= r; l++)
        {
            if (p[l] != t[(k + l - 1)])
            {
                k++;
                break;
            }
            return k;
        }
    }
    return (0);
}

int main ()
{
    int result = patternMatch("love", "I love my country Bangladesh");
    if (result == 0)
    {
        printf("Not Found\n");
    }
    else
    {
        printf("Found on location %d\n", result);
    }

    return (0);
}
