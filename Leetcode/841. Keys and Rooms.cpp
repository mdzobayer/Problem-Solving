class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int i, length = rooms.size();

        bool isVisited[length + 5];
        memset(isVisited, false, sizeof(isVisited));

        bool result = canVisit(rooms, isVisited, 0);
        if (result) {
            for (i = 0; i < length; ++i) {
                if (isVisited[i] == false) {
                    result = false;
                    break;
                }
            }
        }

        return result;
    }

    bool canVisit(vector<vector<int>>& rooms, bool isVisited[], int index) {
        int i;
        bool result = true;

        if (isVisited[index]) return isVisited[index];

        isVisited[index] = true;

        for (i = 0; i < rooms[index].size(); ++i) {
            result = canVisit(rooms, isVisited, rooms[index][i]);

            if (!result) break;
        }

        return result;
    }
};