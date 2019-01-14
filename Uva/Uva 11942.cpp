#include <cstdio>

int bread[15];

int main() {
    bool flag, isTrue;
    int test, i;
    scanf("%d", &test);
    printf("Lumberjacks:\n");
    while(test--) {
        flag = true;
        isTrue = true;
        for (i = 0; i < 10; ++i) {
            scanf("%d", &bread[i]);
        }
        if (bread[0] > bread[1])
            flag = false;
        if (flag) {
            for (i = 2; i < 10; ++i) {
                if (bread[i-1] > bread[i])
                    isTrue = false;
            }
        }
        else {
            for (i = 2; i < 10; ++i) {
                if (bread[i-1] < bread[i])
                    isTrue = false;
            }
        }

        if (isTrue)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return (0);
}
/**
3
13 25 39 40 55 62 68 77 88 95
88 62 77 20 40 10 99 56 45 36
91 78 61 59 54 49 43 33 26 18
**/
