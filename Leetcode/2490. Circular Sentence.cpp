class Solution {
public:
    bool isCircularSentence(string s) {
        stringstream ss(s);
        vector<string> words;
        string str;

        while(ss >> str) words.push_back(str);

        for (int i = 1; i < words.size(); ++i) {
            if (words[i - 1].back() != words[i].front()) return false;
        }

        str = words.back();

        return words[0].front() == str.back();
    }
};