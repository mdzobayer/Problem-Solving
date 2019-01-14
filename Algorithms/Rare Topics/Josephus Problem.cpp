#include <cstdio>

int josephus(int n, int k) {
    if (n == 1) {
        return 1;
    }
    else{
        int x = (josephus(n - 1, k) + k - 1) % n + 1;
        printf("x is %d\n", x);
        return x;
    }
}

int main() {

    int n = 5;
    int k = 2;

    printf("The chosen place is %d\n", josephus(n, k));

    return (0);
}
