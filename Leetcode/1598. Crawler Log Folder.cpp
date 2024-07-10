class Solution {
public:
    int minOperations(vector<string>& logs) {
        int i, step = 0;

        for (i = 0; i < logs.size(); ++i) {
            if (logs[i] == "../") {
                --step;
                step = max(0, step);
            }
            else if (logs[i] != "./") {
                ++step;
            }
        }

        return step;
    }
};