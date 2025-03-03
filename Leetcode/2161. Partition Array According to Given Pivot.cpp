class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int> lessThen, greaterThen;
            int pivotCount = 0;
    
            for (int num : nums) {
                if (num < pivot) {
                    lessThen.push_back(num);
                }
                else if (num > pivot) {
                    greaterThen.push_back(num);
                }
                else ++pivotCount;
            }
    
            while(pivotCount > 0) {
                --pivotCount;
                lessThen.push_back(pivot);
            }
    
            lessThen.insert(lessThen.end(), greaterThen.begin(), greaterThen.end());
    
            return lessThen;
        }
    };