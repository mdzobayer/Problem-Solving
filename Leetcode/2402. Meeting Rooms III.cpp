#define ll long long int
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        int i, index, endTime;

        vector<int> meetingCounts(n, 0);
        priority_queue< pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>> > usedRoom;
        priority_queue<int, vector<int>, greater<int>> unusedRoom;

        for (i = 0; i < n; ++i) {
            unusedRoom.push(i);
        }

        sort(meetings.begin(), meetings.end());

        for (i = 0; i < meetings.size(); ++i) {

            while(!usedRoom.empty() && usedRoom.top().first <= meetings[i][0]) {
                auto room = usedRoom.top();
                usedRoom.pop();
                unusedRoom.push(room.second);
            }

            if (!unusedRoom.empty()) {
                int roomNumber = unusedRoom.top();
                unusedRoom.pop();
                usedRoom.push(make_pair(meetings[i][1], roomNumber));

                ++ meetingCounts[roomNumber];
            }
            else {
                auto room = usedRoom.top();
                usedRoom.pop();
                usedRoom.push(make_pair(room.first + (meetings[i][1] - meetings[i][0]), room.second));

                ++ meetingCounts[room.second];
            }
            
        }

        index = 0;
        for (i = 1; i < n; ++i) {
            if (meetingCounts[index] < meetingCounts[i]) {
                index = i;
            }
        }

        return index;
    }
};