

#include<stdio.h>

int main()
{
   int n, i = 3, count, c;

   printf("Enter the number of prime numbers required\n");
   scanf("%d",&n);

   if ( n >= 1 )
   {
      printf("First %d prime numbers are :\n",n);
      printf("2\n");
   }

   for ( count = 2 ; count <= n ;  )
   {
      for ( c = 2 ; c <= i - 1 ; c++ )
      {
         if ( i%c == 0 )
            break;
      }
      if ( c == i )
      {
         printf("%d\n",i);
         count++;
      }
      i++;
   }

   return 0;
}



#include<stdio.h>

main()
{
   int n, c = 2;

   printf("Enter a number to check if it is prime\n");
   scanf("%d",&n);

   for ( c = 2 ; c <= n - 1 ; c++ )
   {
      if ( n%c == 0 )
      {
         printf("%d is not prime.\n", n);
	 break;
      }
   }
   if ( c == n )
      printf("%d is prime.\n", n);

   return 0;
}

#include <stdio.h>
#include <math.h>

int isPrime(int n){
    int i;

    if (n==2)
        return 1;

    if (n%2==0)
        return 0;

    for (i=3;i<=sqrt(n);i+=2)
        if (n%i==0)
            return 0;

    return 1;
}

int main(){
    int i;
    int count = 0;

    for (i=2;i<10000000;i++){
        if(isPrime(i))
            count++;
    }

    printf("count=%dn",count);

return 0;
}
