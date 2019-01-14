#include <cstdio>
#include <cstring>

bool isPalin(char arr[]) {
    int len = strlen(arr);
    int i = 0, j = len - 1;
    while (i <= j) {
        if (arr[i] != arr[j]) return false;
        ++i;
        --j;
    }
    return true;
}

bool recursivePalin(char arr[], int i, int j) {
    if (arr[i] != arr[j]) return false;
    else if (i > j) return true;
    else return recursivePalin(arr, i + 1, j - 1);
}

int main() {
    char str[30];
    int len, i, j, count = 0;
    /*if (isPalin(str)) {
        printf("I am from repeating loop\n");
    }
    int len = strlen(str);
    if (recursivePalin(str, 0, len - 1)) {
        printf("I am from recursive loop\n");
    }*/
    gets(str);
    len = strlen(str);
    i = 0;
    j = len - 1;
    while (i <= j) {
        if (str[i] != str[j]) ++count;
        ++i;
        --j;
    }
    if (count == 1 || count == 0) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }

    return (0);
}
