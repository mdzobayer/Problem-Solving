class Solution {
    vector< vector<int> > dirs = {{1,3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450", startState;
        int moves = 0;

        for (auto &boar : board) {
            for (int digit : boar) {
                startState += to_string(digit);
            }
        }

        unordered_set<string> visited;
        queue<string> queue;
        queue.push(startState);

        visited.insert(startState);

        while(!queue.empty()) {
            int size = queue.size();

            while(size-- > 0) {
                string currentState = queue.front();
                queue.pop();

                if (currentState == target) {
                    return moves;
                }

                int zeroPos = currentState.find('0');

                for (int newPos : dirs[zeroPos]) {
                    string nextState = currentState;
                    swap(nextState[zeroPos], nextState[newPos]);

                    if (visited.count(nextState)) continue;

                    queue.push(nextState);
                    visited.insert(nextState);
                }
            }
            ++moves;
        }

        return -1;
    }
};