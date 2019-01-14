
#include <bits/stdc++.h>

using namespace std;

int findLevel(int x) {
    if (x < 100 || x > 14000) return -1;
    freopen("data.dat", "r", stdin);
    int n, maxi = 0, level = -1;

    while(scanf("%d", &n) == 1) {
        if (n <= 10) level = n;
        if (n == x) return level;
    }

    return -1;
}

int main()
{

    int n, level, check;

    label1:
    printf("Enter a problem number: ");
    scanf("%d", &n);
    getchar();
    level = findLevel(n);
    if (level == -1) {
        printf("Sorry ! No record found.\n");
    }
    else {
        printf("\t   Yes, got it\n\n");
        printf("\tProblem %d = Level %d\n", n, level);
    }
    label2:
    printf("\nDo you want to find again (Y = 1/N = 2): ");
    scanf("%d", &check);
    if (check == 1) goto label1;
    else if (check == 2) return (0);
    else {
        printf("\a\n\tWrong input.\n\tTry again\n");
        goto label2;
    }

    return (0);
}
