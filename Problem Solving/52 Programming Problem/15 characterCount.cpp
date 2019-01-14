#include <cstdio>
#include <cstring>

bool duplicate (char s[], int loc, char ch)
{
    for (int k = loc - 1; k >= 0; k--)
    {
        if (s[k] == ch)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    char s[12];
    gets(s);
    int len = strlen(s);

    for (int i = 0; i < len; i++)
    {
        bool findDupli = duplicate( s, i, s[i]);
        if (findDupli)
        {
            continue;
        }
        int number = 1;
        for (int j = i + 1; j < len; j++)
        {

            if (s[i] == s[j])
            {
                number++;
            }
        }
        printf("%c = %d\n", s[i], number);

    }

    return (0);
}
