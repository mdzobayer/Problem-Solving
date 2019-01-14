#include <cstdio>

int findMin(int arr[]) {
    int min = arr[0];
    for (int i = 1; i < 3; ++i) {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int main() {

    int test, num[3] = { 0 }, i, a, b, c;
    scanf("%d", &test);

    for (i = 0; i < test; ++i) {

        scanf("%d %d %d", &a, &b, &c);
        num[0] += a;
        num[1] += b;
        num[2] += c;
        a = findMin(num);
        if (a > 29) {
            printf("%d\n", a);
            num[0] -= a;
            num[1] -= a;
            num[2] -= a;
        }
        else
            printf("NO\n");
    }

    return (0);
}
