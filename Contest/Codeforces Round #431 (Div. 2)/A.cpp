#include <cstdio>

int main() {
    bool flag = false;
    int n, arr[110], segment = 0, evenNum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
    if ((arr[0] % 2 == 0) || ( arr[n-1] % 2 == 0) ) {
        printf("No\n");
    }
    else if (n % 2 != 0) {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }

    return (0);
}
