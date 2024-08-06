class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        vector< pair<int, int> > freqOrder;
        int i, ans = 0, n = 26;

        for (char ch : word) {
            ++freq[ch - 'a'];
        }

        for(i = 0; i < 26; ++i) {
            freqOrder.push_back({freq[i], i});
        }
        sort(freqOrder.begin(), freqOrder.end(), greater<pair<int, int>>());

        for (i = 0; i < n; ++i) {
            if (i < 8) {
                ans += freqOrder[i].first;
            }
            else {
                int multiplier = (i / 8) + 1;
                ans += (freqOrder[i].first * multiplier);
            }
        }

        return ans;
    }
};