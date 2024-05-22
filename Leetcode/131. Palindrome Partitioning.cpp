class Solution {
    vector< vector<string> > result;
public:
    vector<vector<string>> partition(string s) {
        vector<string> currentList;

        backtrack(s, 0, currentList);

        return result;
    }

    void backtrack(string & s, int start, vector<string>& currentList) {
        if (start >= s.size()) {
            result.push_back(currentList);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (isPalindrome(s, start, end)) {
                currentList.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1, currentList);
                currentList.pop_back();
            }
        }
    }

    bool isPalindrome(string & s, int low, int high) {
        while(low < high) {
            if (s[low] != s[high]) return false;
            ++low;
            --high;
        }

        return true;
    }
};