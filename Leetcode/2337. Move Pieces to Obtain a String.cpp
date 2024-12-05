class Solution {
public:
    bool canChange(string start, string target) {
        int i = 0, j = 0, len = start.size();

        while(i < len || j < len) {
            while(i < len && start[i] == '_') ++i;

            while(j < len && target[j] == '_') ++j;

            if (i == len || j == len) {
                return i == len && j ==  len;
            }

            if (start[i] != target[j] || (start[i] == 'L' && i < j) ||
            (start[i] == 'R' && i > j)) {
                return false;
            }

            ++j;
            ++i;
        }
        
        return true;
    }
};