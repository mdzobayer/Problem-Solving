class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, vector<int>> busStops;
        map<int, bool> visitedBusStops;
        map<int, bool> visitedBuses;

        pair<int,int> busStop;
        int i, j, busIndex, ans = -1;

        for (i = 0; i < routes.size(); ++i) {
            visitedBuses[i] = false;
            for (j = 0; j < routes[i].size(); ++j) {
                if (busStops.find(routes[i][j]) != busStops.end()) {
                    busStops[routes[i][j]].push_back(i);
                }
                else {
                    vector<int> busList;
                    busStops[routes[i][j]] = busList;
                    busStops[routes[i][j]].push_back(i);
                }

                visitedBusStops[routes[i][j]] = false;
            }
        }

        queue<pair<int, int>> q;
        q.push(make_pair(source, 0));
        visitedBusStops[source] = true;

        while(!q.empty()) {
            busStop = q.front();
            q.pop();

            if (busStop.first == target) return busStop.second;

            vector<int> buses = busStops[busStop.first];
            for (i = 0; i < buses.size(); ++i) {
                busIndex = buses[i];
                if (visitedBuses[busIndex]) continue;

                visitedBuses[busIndex] = true;

                for (j = 0; j < routes[busIndex].size(); ++j) {
                    if (visitedBusStops[routes[busIndex][j]]) continue;

                    visitedBusStops[routes[busIndex][j]] = true;

                    if (routes[busIndex][j] == target) return busStop.second + 1;

                    q.push(make_pair(routes[busIndex][j], busStop.second + 1));
                }
            }


        }



        return ans;
    }
};