class Solution {
    int rows, cols;
    vector<int> dirs = {0,1,0,-1,0};
    unordered_set<string> visited, cleaned;
public:
    int numberOfCleanRooms(vector<vector<int>>& room) {
        rows = room.size();
        cols = room[0].size();

        return solve(room, 0, 0, 0);
    }

    int solve(vector<vector<int>>& room, int row, int col, int direction) {
        if (visited.find(to_string(row) + to_string(col) + to_string(direction)) != visited.end()) {
            return cleaned.size();
        }

        visited.insert(to_string(row) + to_string(col) + to_string(direction));
        cleaned.insert(to_string(row) + to_string(col));

        int newRow = row + dirs[direction], newCol = col + dirs[direction + 1];
        if (newRow >= 0 && newCol >= 0 && newRow < rows && newCol < cols && room[newRow][newCol] == 0) {
            return solve(room, newRow, newCol, direction);
        }

        return solve(room, row, col, (direction + 1) % 4);
    }
};