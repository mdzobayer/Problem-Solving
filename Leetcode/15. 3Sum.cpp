class Solution {

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        int i, j, k, n = nums.size();
        sort(nums.begin(), nums.end());

        set<string> st;

        for (i = 0; i < n && nums[i] <= 0; ++i) {

            if (i == 0) {
                twoSum(nums, i, ans);
            }
            else if (nums[i] != nums[i - 1]) {
                twoSum(nums, i, ans);
            }

        }

        return ans;
    }

    void twoSum(vector<int>& nums, int index, vector<vector<int>>& ans) {
        int sum, low = index + 1, high = nums.size() - 1;

        while(low < high) {
            sum = nums[index] + nums[low] + nums[high];

            if (sum < 0) {
                ++ low;
            }
            else if (sum > 0) {
                -- high;
            }
            else {
                vector<int> tempTriple, triple{nums[index], nums[low], nums[high]};
                if (ans.size() > 0) {

                    if (ans.back() != triple) {
                        ans.push_back(triple);
                    }
                }
                else {
                    ans.push_back(triple);
                }
                
                ++ low;
                -- high;
            }
        }
    }
};