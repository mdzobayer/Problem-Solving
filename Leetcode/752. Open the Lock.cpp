class Solution {
    unordered_map<char, char> forwardMove = {
            {'0', '1'}, 
            {'1', '2'}, 
            {'2', '3'}, 
            {'3', '4'}, 
            {'4', '5'},
            {'5', '6'}, 
            {'6', '7'}, 
            {'7', '8'}, 
            {'8', '9'}, 
            {'9', '0'}
        };

        unordered_map<char, char> backwardMove = {
            {'0', '9'}, 
            {'1', '0'}, 
            {'2', '1'}, 
            {'3', '2'}, 
            {'4', '3'},
            {'5', '4'}, 
            {'6', '5'}, 
            {'7', '6'}, 
            {'8', '7'}, 
            {'9', '8'}
        };
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.find("0000") != visited.end()) {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while(!q.empty()) {
            auto combi = q.front();
            q.pop();

            if (combi.first == target) {
                return combi.second;
            }

            for (int i = 0; i < 4; ++i) {
                string newCombi = combi.first;
                    
                newCombi[i] = forwardMove[newCombi[i]];
                if (visited.find(newCombi) == visited.end()) {
                    visited.insert(newCombi);
                    q.push({newCombi, combi.second + 1});                    
                }

                newCombi = combi.first;
                newCombi[i] = backwardMove[newCombi[i]];
                if (visited.find(newCombi) == visited.end()) {
                    visited.insert(newCombi);
                    q.push({newCombi, combi.second + 1});
                }
            }
        }

        return -1;
    }
};