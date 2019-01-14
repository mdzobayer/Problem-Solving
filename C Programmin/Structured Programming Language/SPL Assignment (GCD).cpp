/* Example to calculate GCD or HCF using recursive function. */
#include <stdio.h>
int hcf(int n1, int n2);

int main()
{
    int n1, n2;
    printf("Enter two positive integers: ");
    scanf("%d%d", &n1, &n2);
    printf("H.C.F of %d and %d = %d", n1, n2, hcf(n1,n2));
    return 0;
}
int hcf(int n1, int n2)
{
    if (n2 != 0)
       return hcf(n2, n1 % n2);
    else
       return n1;
}
