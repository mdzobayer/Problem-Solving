#include <cstdio>
#include <cstring>

void sReverse(char str[])
{
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        putchar(str[i]);
    }
    putchar(' ');
}

int main()
{

    int n, T, j, k;
    char s[1024], word[1024];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {

        scanf(" %[^\n]", s);
        //printf("%s\n", s); %[^\n] %[^\n]

        int sLen = strlen(s);
        for (j = 0, k = 0; j < sLen; j++)
        {
            if (s[j] != ' ')
            {
                word[k] = s[j];
                k++;
            }
            else if (k > 0)
            {
                word[k] = '\0';
                //printf("%s ", strrev(word));
                sReverse(word);
                k = 0;
            }
        }
        if (k > 0)
        {
            word[k] = '\0';
            //printf("%s", strrev(word));
            sReverse(word);
        }
        putchar('\n');
    }
    return (0);
}
