class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st;
        int i, ans = nums.size();

        for (i = 0; i < nums.size(); ++i) {
            st.insert(nums[i]);
        }

        vector<int> distinctNums;
        
        for (auto it = st.begin(); it != st.end(); ++it) {
            distinctNums.push_back(*it);
        }
        sort(distinctNums.begin(), distinctNums.end());
        
        for (auto it = distinctNums.begin(); it != distinctNums.end(); ++it) {
            int left = *it;
            int right = left + nums.size() - 1;

            auto posIterator = upper_bound(it, distinctNums.end(), right);

            int itemHave = posIterator - it;
            int operatorNeed = nums.size() - itemHave;

            ans = min(ans, operatorNeed);
        }

        return ans;
    }
};