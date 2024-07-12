/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     // Compares the sum of arr[l..r] with the sum of arr[x..y] 
 *     // return 1 if sum(arr[l..r]) > sum(arr[x..y])
 *     // return 0 if sum(arr[l..r]) == sum(arr[x..y])
 *     // return -1 if sum(arr[l..r]) < sum(arr[x..y])
 *     int compareSub(int l, int r, int x, int y);
 *
 *     // Returns the length of the array
 *     int length();
 * };
 */

class Solution {
public:
    int getIndex(ArrayReader &reader) {
        int len = reader.length();

        int left = 0;

        while(len > 1) {
            len /= 2;

            int comp = reader.compareSub(left, left + len - 1, left + len, left + len + len - 1);

            if (comp == 0) {
                left = left + len + len;
                break;
            }
            else if (comp < 0) {
                left = left + len;
            }
        }

        return left;
    }
};