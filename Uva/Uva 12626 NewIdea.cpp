#include <cstdio>
#include <cstring>
int main() {
    freopen("input.txt", "r", stdin);
    int arr[7], test, len, i, min;
    char str[610];
    scanf("%d", &test);
    getchar();
    while(test--) {
        memset(arr, 0, sizeof(arr));
        gets(str);
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
        arr[4] /= 2;
        arr[5] /= 3;
        min = arr[0];
        for (i = 1; i < 6; ++i) {
            if (arr[i] < min) {
                min = arr[i];
            }
        }
        printf("%d\n", min);
    }
    return (0);
}
