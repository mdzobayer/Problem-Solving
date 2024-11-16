class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i, len = nums.size();
        vector<int> result(len - k + 1, -1);
        deque<int> indexDeq;

        for (i = 0; i < len; ++i) {
            if (!indexDeq.empty() && indexDeq.front() < i - k + 1) {
                indexDeq.pop_front();
            }

            if (!indexDeq.empty() && nums[i] != nums[i - 1] + 1) {
                indexDeq.clear();
            }

            indexDeq.push_back(i);

            if (i >= k - 1) {
                if (indexDeq.size() == k) {
                    result[i - k + 1] = nums[indexDeq.back()];
                }
                else {
                    result[i - k + 1] = -1;
                }
            }
        }

        return result;
    }
};