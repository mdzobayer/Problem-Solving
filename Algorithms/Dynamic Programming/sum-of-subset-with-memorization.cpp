/// Include C library for runtime effeciency
#include <cstdio>
#include <cstring>

/// Predefine statements
#define maxSum 100
#define maxIndex 50

/// Sub Set Sum technique/function with memorization
int calculatedResult[maxSum][maxIndex]; /// preprocessed array
int SubSetSum(int arr[], int sum, int index) {
    if (sum == 0) {
        return 1;
    }
    if (sum < 0 || index < 0) return 0;
    if (calculatedResult[sum][index] != -1) {
        return calculatedResult[sum][index];
    }
    calculatedResult[sum][index] = SubSetSum(arr, sum, index - 1) + SubSetSum(arr, sum - arr[index], index - 1);
    return calculatedResult[sum][index];
}

/// Main Function
int main() {

    int arr[10] = {1,3,8,4,15,2,6,7,12,14};
    memset(calculatedResult, -1, sizeof(calculatedResult));
    int count = SubSetSum(arr, 22, 9);      /// Check with and without memorization
    printf("%d\n", count);

    return (0);
}
