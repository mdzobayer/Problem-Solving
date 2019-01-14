#include <cstdio>

int main() {

    char start, desti, icon[12];
    int n, x, i;
    icon[0] = '^';
    icon[1] = '>';
    icon[2] = 'v';
    icon[3] = '<';

    icon[4] = '^';
    icon[5] = '>';
    icon[6] = 'v';
    icon[7] = '<';

    icon[8] = '^';
    icon[9] = '>';
    icon[10] = 'v';
    icon[11] = '<';

    start = getchar();
    getchar();
    desti = getchar();
    scanf("%d", &n);

    x = n % 4;
    for (i = 4; i <= 7; ++i) {
        if (icon[i] == start) {
           break;
        }
    }
    if ((icon[i + x] == desti) && (icon[i - x] == desti)) {
        printf("undefined\n");
    }
    else if (icon[i + x] == desti) {
        printf("cw\n");
    }
    else if (icon[i - x] == desti) {
        printf("ccw\n");
    }



    return (0);
}
