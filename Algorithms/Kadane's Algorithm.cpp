/// Kadane's Algorithm

#include <cstdio>
#include <climits>

int maxSubArraySum(int arr[], int size) {

    int maxSoFar = INT_MIN, maxEndingHere = 0;

    for (int i = 0; i < size; ++i) {
        maxEndingHere += arr[i];
        if (maxEndingHere > maxSoFar) {
            maxSoFar = maxEndingHere;
        }
        if (maxEndingHere < 0) {
            maxEndingHere = 0;
        }
    }
    return maxSoFar;
}

int main(int argc, char ** argv) {

    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int maxSum = maxSubArraySum(arr, 8);
    printf("Largest Sub array Sum is %d\n", maxSum);

    return (0);
}
