#include <cstdio>
#include <vector>
#define Size 10
using namespace std;

int preProcess[Size][2];

void print(int arr[], vector<int> vt) {
    for (int i = 0; i < vt.size(); ++i) {
        printf("%d ", arr[vt[i]]);
    }
    printf("\n");
}

int sumOfSubset(int arr[], int n, int index, vector<int> vt, int currentSum, int sum) {
    if (currentSum == sum) {
        print(arr, vt);
        return sum;
    }
    if (index > n || currentSum > sum) {
        return;
    }
    vt.push_back(index);
    //currentSum += arr[index];
    sumOfSubset(arr, n, index + 1, vt, currentSum + arr[index], sum);

    vt.pop_back();
    //currentSum -= arr[index];
    sumOfSubset(arr, n, index + 1, vt, currentSum, sum);
}

int main() {
    vector<int> vt;
    int arr[Size] = { 2, 3, 4, 6, 7, 8, 10, 12, 15, 17};
    for (int i = 0; i < Size; ++i) {
        preProcess[i][0] = -1;
        preProcess[i][1] = -1;
    }
    sumOfSubset(arr, 9, 0, vt, 0, 14);

    return (0);
}
