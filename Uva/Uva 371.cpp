/*
#include <cstdio>

long long int count = 0;

long long int ackermann(long long int x) {
    if (x == 1)
        return 1;
    else if ( x % 2 == 0 ) {
        ackermann(x / 2);
    }
    else {
        ackermann((3 * x) + 1);
    }
    count++;
}
void swap(long long int & l, long long int & h) {
    long long int t = l;
    l = h;
    h = t;
}
int main() {
    long long int i, l, h, v, s;
    while(scanf("%lld %lld", &l, &h)) {
        if (h == 0 || l == 0)
            break;
        v = l; s = 0;
        //printf("Between %d and %d, ", l, h);
        if (h < l)
            swap(l,h);
        for ( i = l; i <= h; ++i) {
            ackermann(i);
            if (s < count) {
                v = i;
                s = count;
            }
            count = 0;
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", l, h, v, s);
    }

    return (0);
}
*/
#include <stdio.h>
long long int num1, num2, i, j, k, n, count, res, tem, highest_value;
int main(){

    while(scanf("%lld %lld", &num1, &num2)==2)
    {
        if(num1==0 || num2==0) break;

        if(num1>num2)
        {
            tem=num1;
            num1=num2;
            num2=tem;
        }

        if(num1==1 && num2<=2)
            printf("Between %lld and %lld, 1 generates the longest sequence of 3 values.\n", num1, num2);
        else
        {
            count=0;
            highest_value=0;
            for(i=num1; i<=num2; i=i+1)
            {
                n=i;
                for(j=0; n!=1; j++)
                {
                    res=(n%2);
                    switch(res)
                    {
                    case 1:
                        n=((n<<2)+1)-n;
                        break;
                    case 0:
                        n=n>>1;
                        break;
                    }
                }
                if(j>count)
                {
                    count=j;
                    highest_value=i;
                }
            }
            printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",num1, num2, highest_value, count);
        }

    }
    return 0;
}
#include <stdio.h>

int main ()
{
    long int F, S, I, Count, Value, Max, J;

    while (scanf("%ld %ld", &F, &S)){

        if (F==0 && S==0)
            break;

        if (F>S){
            F ^= S;
            S ^= F;
            F ^= S;
        }

        Max = 0;

        for (I=F; I<=S; I++){
            Count = 0;
            J = I;

            do {
                if (J%2==0)
                    J/=2;
                else
                    (J*=3)++;
                Count++;
            } while (J!=1);

            if (Count > Max){
                Value = I;
                Max = Count;
            }

        }
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n", F, S, Value, Max);
    }
    return 0;
}



