/* Program to display fibonacci Series */
#include <stdio.h>
int main() {
    int i = 0, j = 0, k = 1, l = 0;
    while (i <= 10) {
        printf("%d ",l);
        j = k;
        k = l;
        l = j + k;
        ++i;
    }
    putchar('\n');
    return (0);
}
