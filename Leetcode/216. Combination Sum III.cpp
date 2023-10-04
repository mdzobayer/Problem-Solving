class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();

        if (k > 0 && n > 0) {
            vector<int> elements;
            prepareCombinationSum(elements, k, n, 1);
        }

        return ans;
    }

    void prepareCombinationSum(vector<int> elements, int k, int n, int digit) {

        if (k == 0 && n == 0) {
            ans.push_back(elements);
            return;
        }
        else if (k == 0 || n == 0) return;
        
        for (int i = digit; i < 10; ++i) {
            vector<int> tempElements = elements;
            tempElements.push_back(i);

            prepareCombinationSum(tempElements, k - 1, n - i, i + 1);
        }
    }
};