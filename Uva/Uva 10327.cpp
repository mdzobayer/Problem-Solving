
#include <cstdio>

int main ()
{
    int n, a[1000], cnt;

    while ( scanf ("%d", &n) != EOF ) {

        for ( int i = 0; i < n; ++i ) {
            scanf ("%d", &a [i]);
        }

        cnt = 0;

        for ( int i = 0; i < n; ++i ) {
            for ( int j = i + 1; j < n; ++j )
                if ( a [i] > a [j] )
                    ++cnt;
        }

        printf ("Minimum exchange operations : %d\n", cnt);
    }

    return 0;
}
