#include <cstdio>

int main() {
    freopen("input.txt", "r", stdin);
    int i;
    int data[5], temp;
    bool flag;
    while(scanf("%d", &data[0]) == 1) {
        flag = true;
        for (i = 1; i < 5; ++i) {
            scanf("%d", &data[i]);
        }
        for (i = 0; i < 5; ++i) {
            scanf("%d", &temp);
            if (temp == data[i])
                flag = false;
        }
        if (flag)
            printf("Y\n");
        else
            printf("N\n");
    }

    return (0);
}
