#include <cstdio>
#include <cstring>
int main() {
    int len, i, max, value[150];
    char line[1024];
    while(scanf("%[^\n]", &line) != EOF) {
        getchar();
        for (i = 0; i < 150; ++i) {
            value[i] = 0;
        }
        len = strlen(line);
        for (i = 0; i < len; ++i) {
            if (line[i] >= 'A' && line[i] <= 'Z') {
                value[line[i]] += 1;
            }
            else if(line[i] >= 'a' && line[i] <= 'z'){
                value[line[i]] += 1;
            }
        }
        max = value[65];
        for (i = 66; i < 91; ++i) {
            if (value[i] > max)
                max = value[i];
        }
        for (i = 97; i < 123; ++i) {
            if (value[i] > max)
                max = value[i];
        }
        for (i = 65; i < 91; i++) {
            if (value[i] == max){
                printf("%c", i);
            }
        }
        for (i = 97; i < 123; i++) {
            if (value[i] == max){
                printf("%c", i);
            }
        }
        printf(" %d\n", max);
    }
    return (0);
}
