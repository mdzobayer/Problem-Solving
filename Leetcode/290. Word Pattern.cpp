class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> mapper;
        map<string, char> reMapper;

        stringstream ss(s);
        string str;

        int i = 0;

        while(ss >> str) {
            if (mapper.find(pattern[i]) != mapper.end()) {
                if (mapper[pattern[i]] != str) return false;
            }
            else if (reMapper.find(str) != reMapper.end()) {
                if (reMapper[str] != pattern[i]) return false;
            }
            else {
                mapper[pattern[i]] = str;
                reMapper[str] = pattern[i];
            }

            ++i;
        }

        return i == pattern.size();
    }
};