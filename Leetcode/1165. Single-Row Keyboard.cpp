class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> hashMap;
        int i = 0, ans = 0;

        for (char ch : keyboard) {
            hashMap[ch] = i;
            ++ i;
        }

        i = 0;
        for (char ch : word) {
            ans += abs(hashMap[ch] - i);
            i = hashMap[ch];
        }

        return ans;
    }
};