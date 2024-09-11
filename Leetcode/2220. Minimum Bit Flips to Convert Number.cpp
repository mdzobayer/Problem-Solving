class Solution {
public:
    int minBitFlips(int start, int goal) {
        vector<bool> bits1, bits2;

        while(start > 0) {
            if (start & 1) bits1.push_back(true);
            else bits1.push_back(false);

            start >>= 1;
        }

        while(goal > 0) {
            if (goal & 1) bits2.push_back(true);
            else bits2.push_back(false);

            goal >>= 1;
        }

        int ans = 0, i = 0, j = 0;
        while(i < bits1.size() && j < bits2.size()) {

            if (bits1[i] != bits2[j]) ++ ans;

            ++i;
            ++j;
        }

        while(i < bits1.size()) {
            if (bits1[i]) ++ ans;
            ++i;
        }

        while(j < bits2.size()) {
            if (bits2[j]) ++ ans;
            ++j;
        }


        return ans;
    }
};