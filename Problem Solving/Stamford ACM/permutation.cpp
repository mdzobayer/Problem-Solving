#include <cstdio>

void swap (char * x, char * y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permutation (char * str, int start, int end) {
    if (start == end) {
        printf("%s\n", str);
        return;
    }
    for (int j = start; j <= end; ++j) {
        swap((str + start), (str + j));
        permutation(str, start + 1, end);
        swap((str + start), (str + j));
    }
}


int main() {
    char str[] = "ABC";
    permutation(str, 0, 2);

    return (0);
}
