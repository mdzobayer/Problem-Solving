#include <cstdio>

int arr[10] = { 5, 2, 7, 11, 2, 3, 6, 8, 10, 1};
int add(int k, int sum) {

    if (k > 9) return sum;
    sum += arr[k];
    add(k+1, sum);

}
int bdd(int k) {
    if (k == 0) return arr[k];
    return arr[k] + bdd(k-1);

}
int Max(int k) {
    if (k == 1) return (arr[k] > arr[k - 1] ) ? arr[k] : arr[k - 1];

    return (arr[k] > Max(k-1) ) ? arr[k] : Max(k-1);
}


int divide(int k) {
    if (k == 0) return 0;
    return 1 + divide(k / 2);
}

int main() {

    printf("%d\n", add(0, 0));
    printf("%d\n", Max(9));
    printf("%d\n", divide(50));

    return (0);
}
