#include <cstdio>

int main()
{
    long long int num;
    //long long int sum;

    while(scanf("%lld", &num) != EOF)  {

        //sumOfCube(sum, num);
        //sum = (long long int)(num * num * (num + 1) * (num + 1)) / 4;
        printf("%lld\n", ((num * num) * ((num + 1) * (num + 1))) / 4);
    }

    return (0);
}
