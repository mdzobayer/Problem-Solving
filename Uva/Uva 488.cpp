#include <cstdio>

const char *a[] = {"", "1", "22", "333", "4444", "55555",
                    "666666", "7777777", "88888888", "999999999"};

int main() {

    register unsigned test, amp, fre, i, j, k;

    scanf("%u", &test);
    while(test--) {

        scanf("%u%u", &amp, &fre);

        while(fre--) {
            for (i = 1; i < amp; ++i)
                printf("%s\n", a[i]);
            for ( ; i; --i)
                printf("%s\n", a[i]);

            if (fre || test)
                putchar('\n');
        }
    }


    return (0);
}
