class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int i = 0, n = sentence.size();
        string str;

        stringstream ss(sentence);
        while(ss >> str) {
            ++i;
            size_t found = str.find(searchWord);
            if (found == 0) {
                return i;
            }
        }

        return -1;
    }
};