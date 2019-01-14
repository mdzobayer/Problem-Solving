#include <cstdio>

int main() {

    int n, i, count; char str[100];

    scanf("%d", &n);
    getchar();
    gets(str);
    count = 0;
    for (i = 0; i < n; ++i) {
        if (str[i] == '1') {
            ++count;
        }
        else if (str[i] == '0' && i > 0) {
            printf("%d", count);
            count = 0;
        }
    }
    printf("%d\n", count);

    return (0);
}
