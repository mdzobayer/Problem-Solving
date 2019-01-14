#include <cstdio>

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("AC.txt", "w", stdout);
    unsigned long long int t, test, arr[3];
    scanf("%lld", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%lld %lld %lld", &arr[0], &arr[1], &arr[2]);
        printf("Case %lld: ", t);
        if (arr[0] <= 0 || arr[1] <= 0 || arr[2] <= 0)
            printf("Invalid\n");
        else if ((arr[0] + arr[1]) > arr[2] && (arr[0] + arr[2]) > arr[1] && (arr[1] + arr[2]) > arr[0]) {
            if (arr[0] == arr[1] && arr[1] == arr[2]) {
                printf("Equilateral\n");
            }
            else if (arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2]) {
                printf("Isosceles\n");
            }
            else {
                printf("Scalene\n");
            }
        }
        else {
            printf("Invalid\n");
        }
    }


    return (0);
}
