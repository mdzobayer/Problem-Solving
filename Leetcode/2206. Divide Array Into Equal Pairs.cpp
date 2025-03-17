class Solution {
    public:
        bool divideArray(vector<int>& nums) {
            unordered_map<int, int> freq;
    
            for (int num : nums) {
                ++freq[num];
            }
    
            for (auto item : freq) {
                if (item.second % 2) return false;
            }
    
            return true;
        }
    };