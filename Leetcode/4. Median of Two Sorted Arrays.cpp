class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, len1 = nums1.size(), len2 = nums2.size();
        int mergedLen = len1 + len2, indexOfNums1 = 0, indexOfNums2 = 0, indexOfMerged = 0;

        vector<int> mergedArray(mergedLen);

        while(indexOfNums1 < len1 && indexOfNums2 < len2) {
            if (nums1[indexOfNums1] <= nums2[indexOfNums2]) {
                mergedArray[indexOfMerged] = nums1[indexOfNums1];
                ++indexOfNums1;
            }
            else {
                mergedArray[indexOfMerged] = nums2[indexOfNums2];
                ++indexOfNums2;
            }

            ++ indexOfMerged;
        }

        while(indexOfNums1 < len1) {
            mergedArray[indexOfMerged] = nums1[indexOfNums1];
            ++indexOfNums1;
            ++ indexOfMerged;
        }

        while(indexOfNums2 < len2) {
            mergedArray[indexOfMerged] = nums2[indexOfNums2];
            ++indexOfNums2;
            ++ indexOfMerged;
        }

        int index = mergedLen / 2;
        if (mergedLen % 2 == 0) {
            
            return (mergedArray[index] + mergedArray[index - 1]) / 2.0;
        }

        return mergedArray[index];
    }
};