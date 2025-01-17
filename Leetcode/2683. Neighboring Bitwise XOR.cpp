class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int Xor = 0;

        for (int item : derived) {
            Xor ^= item;
        }

        return Xor == 0;
    }
};