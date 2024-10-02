class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        if (arr.size() == 0) return vector<int>();

        vector<int> sortedArr(arr.begin(), arr.end());
        unordered_map<int, int> rank;
        sort(sortedArr.begin(), sortedArr.end());

        int i, currentRank = 1;
        rank[sortedArr[0]] = currentRank;
        for (i = 1; i < sortedArr.size(); ++i) {
            if (sortedArr[i] != sortedArr[i - 1]) ++ currentRank;
            rank[sortedArr[i]] = currentRank;
        }

        vector<int> ans(arr.size(), 0);
        for (i = 0; i < arr.size(); ++i) {
            ans[i] = rank[arr[i]];
        }

        return ans;
    }
};