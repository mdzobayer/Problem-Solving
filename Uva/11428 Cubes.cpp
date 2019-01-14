#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll cubes[10000+5];

void genCubes() {
    int i;
    cubes[0] = 0;
    cubes[1] = 1;
    for (i = 1; i <= 10000; ++i) {
        cubes[i] = (i*i)*i;
    }
}

bool findPrint(int x, int key) {
    int low = 1, high = x - 1, mid;

    while (low <= high) {
        mid = (low + high) / 2;
        if (cubes[mid] == key) {
            printf("%d %d\n", x, mid);
            return true;
        }
        else if (cubes[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return false;
}

int main() {

    //freopen("in.txt", "r", stdin);

    genCubes();
    int i, n, x;
    bool flag;

    while(scanf("%d", &n) == 1) {
        if (n == 0) break;
        flag = true;
        for (i = 1; i <= n; ++i) {
            x = cubes[i] - n;
            if (x < 1) continue;

            if(findPrint(i, x)) {
                flag = false;
                break;
            }
        }
        if (flag) {
            printf("No solution\n");
        }
    }

    return (0);
}
