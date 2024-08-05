class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<string> distinctArr;
        unordered_map<string, int> freq;

        for (string str : arr) {
            ++ freq[str];
        }

        for (string str : arr) {
            if (freq[str] == 1) {
                distinctArr.push_back(str);
            }
        }

        if (distinctArr.size() < k) {
            return string("");
        }

        return distinctArr.at(k - 1);
    }
};