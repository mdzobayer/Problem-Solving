#include <cstdio>

int main() {
    freopen("input.txt", "r", stdin);
    int data[3];
    while(scanf("%d %d %d", &data[0], &data[1], &data[2]) == 3) {
        if (data[0] == data[1] && data[1] == data[2])
            printf("*\n");
        else if (data[0] == data[1] && data[1] != data[2])
            printf("C\n");
        else if (data[0] == data[2] && data[1] != data[2])
            printf("B\n");
        else
            printf("A\n");
    }

    return (0);
}
