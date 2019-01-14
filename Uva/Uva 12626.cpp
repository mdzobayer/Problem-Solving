#include <cstdio>
#include <cstring>
int main() {
    freopen("input.txt", "r", stdin);
    bool flag;
    int arr[7], test, len, i, min;
    char str[610];
    scanf("%d", &test);
    getchar();
    while(test--) {
        memset(arr, 0, sizeof(arr));
        gets(str);
        flag = true;
        len = strlen(str);
        for (i = 0; i < len; ++i) {
            if (str[i] == 'M')
                arr[0] += 1;
            else if (str[i] == 'G')
                arr[1] += 1;
            else if (str[i] == 'I')
                arr[2] += 1;
            else if (str[i] == 'T')
                arr[3] += 1;
            else if (str[i] == 'R')
                arr[4] += 1;
            else if (str[i] == 'A')
                arr[5] += 1;
        }
        if (arr[5] < 3 || arr[4] < 2) {
            printf("0\n");
            continue;
        }
        min = arr[0];
        for (i = 0; i < 5; ++i) {
            if (arr[i] < 1) {
                printf("0\n");
                flag = false;
            }
            else if (min > arr[i])
                min = arr[i];
        }
        if (!flag) {
            continue;
        }
        for (i = min; i > 0; --i) {
            if (i * 2 <= arr[4]) {
                if (i * 3 <= arr[5]) {
                    printf("%d\n", i);
                    flag = false;
                    break;
                    i = 0;
                }
            }
        }
        if (flag)
            printf("0\n");
    }

    return (0);
}
