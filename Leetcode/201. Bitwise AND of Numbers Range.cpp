class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount = 0;

        while(left < right) {
            ++shiftCount;

            left >>= 1;
            right >>= 1;
        }

        return right << shiftCount;
    }
};