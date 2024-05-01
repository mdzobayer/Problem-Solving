class Solution {
public:
    string reversePrefix(string word, char ch) {
        int position = word.find(ch);
        if (position == -1) return word;

        string reverse_sub = word.substr(0, position + 1);
        reverse(reverse_sub.begin(), reverse_sub.end());

        return reverse_sub + word.substr(position + 1);
    }
};