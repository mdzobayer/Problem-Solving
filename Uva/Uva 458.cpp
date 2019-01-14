#include <cstdio>

int main() {

    char ch;
    while(scanf("%c", &ch) == 1) {
        if (ch == '\n'){
            putchar('\n');
            continue;
        }
        putchar(ch - 7);
    }

    return (0);
}
