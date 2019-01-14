/*
 ============================================================================
 Name        : Uva 371.cpp
 Author      : Md. Zobayer Mahmud Khan
 Copyright   : 
 Description : 3n + 1
 ============================================================================
 */
#include <cstdio>

int main() {

    long long int l, h, v, s, max, i, j, count;
    while(scanf("%lld %lld", &l, &h)) {
        if ((l == 0) || (h == 0))
            break;
        v = s = 0;
        if (l > h) {
            l ^= h;
            h ^= l;
            l ^= h;
        }

        for (i = l; i <= h; i++) {
            j = i;
            count = 0;
            do {
                if (j % 2 == 0)
                    //j /= 2;
                    j = j >> 1;
                else
                    //(j *= 3)++;
                    j = ((j << 2) + 1) - j;
                ++count;
            } while(j != 1);

            if (s < count) {
                s = count;
                v = i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", l, h, v, s);
    }

    return (0);
}
