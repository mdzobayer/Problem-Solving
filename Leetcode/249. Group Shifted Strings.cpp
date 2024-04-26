class Solution {
public:

    string getHash(string & s) {
        string hashKey;
        int i;

        for (i = 1; i < s.size(); ++i) {
            hashKey += ((s[i] - s[i - 1] + 26) % 26) + 'a';
        }

        return hashKey;
    }

    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ans;
        int i, j, len;
        unordered_map<string, vector<string>> group; 

        for (i = 0; i < strings.size(); ++i) {
            string hashKey = getHash(strings[i]);
            group[hashKey].push_back(strings[i]);
        }

        for (auto it = group.begin(); it != group.end(); ++it) {
            ans.push_back(it->second);
        }

        return ans;
    }
};