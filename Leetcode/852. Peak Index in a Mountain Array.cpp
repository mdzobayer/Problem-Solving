class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, mid, right = arr.size() - 1;
        int i;

        int peakIndex = 0, peakElement = arr[0];

        while(left <= right) {
            mid = left + right;
            mid >>= 1;

            if (arr[mid] > peakElement) {
                peakElement = arr[mid];
                peakIndex = mid;
            }

            if(arr[mid + 1] > arr[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return peakIndex;
    }
};