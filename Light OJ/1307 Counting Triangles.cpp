#include <cstdio>
#include <algorithm>

unsigned long long int binarySearch(unsigned long long int arr[], unsigned long long int key, unsigned long long int low, unsigned long long int high) {
    unsigned long long int mid, sMax = arr[low] - 1, sIndex = low;
    if (key < arr[low]) {
        return  (low);
    }
    while(low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            if (arr[mid] == arr[mid - 1]) {
                high = mid - 1;
            }
            else {
                return mid;
            }
        }
        else if (arr[mid] > key) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
            if (arr[mid] >= sMax) {
                sMax = arr[mid];
                sIndex = mid;
            }
        }
    }
    return sIndex + 1;
}

int main() {

    unsigned long long int t, test, n, arr[2010], i, x, y, count, range, j;
    scanf("%llu", &test);
    for (t = 1; t <= test; ++t) {
        scanf("%llu", &n);
        for (i = 0; i < n; ++i) {
            scanf("%llu", &arr[i]);
        }
        std::sort(arr, arr+n);
        count = 0;
        range = n - 2;
        for (i = 0; i <= range; ++i) {
            for (j = i + 1; j <= range; ++j) {
                y = arr[i] + arr[j];
                x = binarySearch(arr, y, j + 1, n - 1);
                count += (x - (j+1));
                //prunsigned long long intf(" %llu %llu = %llu\n", arr[i], arr[j], y);
            }
        }
        printf("Case %llu: %llu\n", t, count);
    }
    return (0);
}
