class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        set<int> hashLengths;
        unordered_set<string> hashSet;

        for (string dict : dictionary) {
            hashSet.insert(dict);
            hashLengths.insert((int)dict.size());
        }

        string word, ans = "";
        stringstream ss(sentence);
        bool addSpace = false;
        while(ss >> word) {

            if (addSpace) ans += " ";

            bool replaceDone = false;
            for(int len : hashLengths) {
                if (len > word.size()) break;

                string sub = word.substr(0, len);
                if (hashSet.find(sub) != hashSet.end()) {
                    ans += sub;
                    replaceDone = true;
                    break;
                }
            }

            if (!replaceDone) {
                ans += word;
            }

            addSpace = true;
        }
        
        return ans;
    }
};