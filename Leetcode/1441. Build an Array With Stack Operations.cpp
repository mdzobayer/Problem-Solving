class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 0, stream = 1;
        vector<string> operation;

        for (stream = 1; stream <= n && i < target.size(); ++ stream) {
            if (stream == target[i]) {
                operation.push_back("Push");
                ++i;
            }
            else {
                operation.push_back("Push");
                operation.push_back("Pop");
            }
        }

        return operation;
    }
};