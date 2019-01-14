#include <cstdio>

int main() {
    int i;
    char str;
    long long int count = 0;

    while(scanf("%c", &str) == 1) {
        if(str == '"') {
            count++;
            if (count % 2 == 1) {
                printf("``");
            }
            else if (count % 2 == 0) {
                printf("''");
            }
        }
        else
            printf("%c", str);
    }

    return (0);
}
