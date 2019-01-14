#include <cstdio>

int main() {

    int n, i, r, part1 = 0, part2 = 0;
    char str[55];
    scanf("%d ", &n);
    scanf("%s", &str);
    r = n / 2;
    bool flag = false;
    for (i = 0; i < n; ++i) {
        if (i < r) {
            part1 += str[i] - '0';
        }
        else {
            part2 += str[i] - '0';
        }
        if (str[i] == '4' || str[i] == '7'){
            flag = true;
        }
        else {
            flag = false;
            break;
        }
    }
    //printf("%d %d %d\n", flag, part1, part2);
    if (flag == false || part1 != part2) {
        printf("NO\n");
    }
    else {
        printf("YES\n");
    }

    return (0);
}
