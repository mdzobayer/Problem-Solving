#include <cstdio>

int main() {
    freopen("input.txt", "r", stdin);
    char song[16][10] = {
        "Happy", "birthday", "to", "you", "Happy", "birthday", "to",
        "you", "Happy", "birthday", "to", "you", "Happy", "birthday",
        "to", "you"
    };
    char person[120][120];
    int n, i, j;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; ++i) {
        gets(person[i]);
    }
    if (n <= 16)
        for (i = 0, j = 0; j < 16; ) {
            printf("%s: %s\n", person[i], song[j]);
            ++i; ++j;
            if (i == n)
                i = 0;
        }
    else {
        for (i = 0, j = 0; ; ) {
            printf("%s: %s\n", person[i], song[j]);
            ++i; ++j;
            if (j == 16 && i >= n) {
                break;
            }
            else if (j == 16) {
                j = 0;
            }
        }
    }


    return (0);
}
