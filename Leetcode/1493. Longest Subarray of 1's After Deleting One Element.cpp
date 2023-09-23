#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left, right, maxPossible = 0, cnt = 0, deleteCount = 0;

        left = 0;
        right = 0;

        while(left < nums.size() && right < nums.size()) {

            while(right < nums.size()) {
                if (nums[right] == 1) {
                    ++cnt;
                    ++right;
                }
                else if (deleteCount < 1) {
                    ++right;
                    ++deleteCount;
                }
                else break;
            }

            maxPossible = max(maxPossible, cnt);

            ++left;
            if (nums[left - 1] == 1) {
                --cnt;
            }
            else if (deleteCount > 0) {
                --deleteCount;
            }

        }

        if (maxPossible == nums.size()) --maxPossible;

        return maxPossible;
    }

};

int main() {

    return (0);
}
