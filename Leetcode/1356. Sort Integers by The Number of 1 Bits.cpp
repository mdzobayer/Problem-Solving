class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int i = 0;
        vector<pair<int, int>> arrPair;
        for (i = 0; i < arr.size(); ++i) {
            arrPair.push_back(make_pair(findNumberOfOneBit(arr[i]),arr[i]));
        }

        sort(arrPair.begin(), arrPair.end());
        vector<int> ans;
        for (i = 0; i < arrPair.size(); ++i) {
            ans.push_back(arrPair[i].second);
        }

        return ans;
    }

    int findNumberOfOneBit(int x) {
        int count = 0;
        while(x > 0) {
            if (x & 1) {
                ++ count; 
            }

            x >>= 1;
        }

        return count;
    }
};