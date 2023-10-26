class Solution {
public:
    int strStr(string haystack, string needle) {
        auto index = haystack.find(needle);

        return (int) index;
    }
};