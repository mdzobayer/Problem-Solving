#include <cstdio>
#include <cmath>

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int input;
        scanf("%d", &input);
        double sq_input = sqrt(input);
        if (ceil(sq_input) == floor(sq_input))
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }


    return (0);
}
