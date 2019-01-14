#include <cstdio>

int main() {

    int pro, sets, i, j;
    bool result;
    scanf("%d", &sets);
    for(i = 1; i <= sets; ++i) {
        result = true;
        printf("Set #%d: ", i);
        for (j = 0; j < 13; ++j) {
            scanf("%d", &pro);
            if (pro < 1)
                result = false;
        }
        printf("%s\n", result ? "Yes" : "No");
    }

    return (0);
}
