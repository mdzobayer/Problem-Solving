#include <cstdio>

int main(int argc, char ** argv) {

    int n, copies = 1, temp, i = 1, c;
    while(scanf("%d", &n) && (n >= 0)) {
        copies = 1;
        c = 0;
        while( (copies * 2) <= n ) {
            copies = (copies * 2);
            ++c;
        }
        printf("Case %d: ", i);
        if (c == 0) {
            printf("%d\n", c);
        }
        else if (copies == n) {
            printf("%d\n", c);
        }
        else {
            //temp = n - copies;
            //if (temp % 2 == 0) {
                printf("%d\n", c + 1);
            //}
            //else
                //printf("%d\n", c + 2);
        }
        ++i;

    }

    return (0);
}
