class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int i, j, n = arr1.size();
        vector<int> freq(1001, 0);
        vector<int> ans;

        for (i = 0; i < n; ++i) {
            ++ freq[arr1[i]];
        }

        for (i = 0; i < arr2.size(); ++i) {
            while(freq[arr2[i]] > 0) {
                -- freq[arr2[i]];
                ans.push_back(arr2[i]);
            }
        }

        for (i = 0; i <= 1000; ++i) {
            while(freq[i] > 0) {
                -- freq[i];
                ans.push_back(i);
            }
        }

        return ans;
    }
};