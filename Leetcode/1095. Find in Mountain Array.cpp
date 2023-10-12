/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int len = mountainArr.length();
        int peakIndex = 0, peakElement;
        int left = 0, right = len - 1;
        bool direction = 0;

        peakIndex = peakIndexInMountainArray(mountainArr, len, peakElement);

        if (target == peakElement) return peakIndex;

        // check on left part
        left = 0, right = peakIndex;
        
        int ans = binarySearch(mountainArr, 0, peakIndex - 1, target, true);
        if (ans != -1) return ans;

        ans = binarySearch(mountainArr, peakIndex + 1, len - 1, target, false);

        return ans;
    }

    int binarySearch(MountainArray & mountainArr, int left, int right, int target, bool isleft) {
        int mid, result = -1;

        while(left <= right) {
            mid = left + right;
            mid >>= 1;

            int midElement = mountainArr.get(mid);

            if (target == midElement) return mid;

            if (isleft) {
                if (midElement > target) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            else {
                if (midElement > target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }

        return result;
    }

    int peakIndexInMountainArray(MountainArray & mountainArr, int & len, int & peak) {
        int left = 0, mid, right = len - 1;

        int peakIndex = 0, peakElement = mountainArr.get(0);
        int midElement, midAfterElement;

        while(left <= right) {
            mid = left + right;
            mid >>= 1;

            midElement = mountainArr.get(mid);
            midAfterElement = mountainArr.get(mid + 1);

            if (midElement > peakElement) {
                peakElement = midElement;
                peakIndex = mid;
            }

            if(midAfterElement > midElement) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        peak = peakElement;

        return peakIndex;
    }
};