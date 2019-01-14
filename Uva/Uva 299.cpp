#include <cstdio>

int main()
{
    long long int t, n, count, line[52],i, j, temp;
    scanf("%lld", &t);

    while ( t ) {
        scanf("%lld", &n);
        for ( j = 0; j < n; j++) {
            scanf("%lld", &line[j]);
        }
        count = 0;

        for ( int i = 0; i < n; ++i ) {
            for ( int j = i + 1; j < n; ++j )
                if ( line [i] > line [j] )
                    ++count;
        }

        printf("Optimal train swapping takes %lld swaps.\n", count);
        --t;
    }

    return (0);
}
