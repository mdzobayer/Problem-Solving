#include <cstdio>
#include <list>
#include <cstring>
#define EOF -1
int main() {

    char str[100010];
    int len, i;
    while(scanf("%s", &str) != EOF) {
        len = strlen(str);
        std::list<char> text;
        std::list<char>::iterator it = text.begin();
        for (i = 0; i < len; ++i) {
            if (str[i] == '[')
                it = text.begin();
            else if (str[i] == ']')
                it = text.end();
            else
                text.insert(it, str[i]);
        }
        for (it = text.begin(); it != text.end(); ++it)
            printf("%c", *it);
        putchar('\n');
    }

    return (0);
}
