class Solution {
public:
    struct manhattanDistance {
        int dis, workerIndex, bikeIndex;
    };

    bool static compare(const manhattanDistance & a, const manhattanDistance & b) {
        if (a.dis != b.dis) return a.dis < b.dis;

        if (a.workerIndex != b.workerIndex) return a.workerIndex < b.workerIndex;

        return a.bikeIndex < b.bikeIndex;
    }

    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int i, j, n = workers.size();
        int m = bikes.size();

        vector<bool> assignedWorker(n, false);
        vector<bool> assignedBike(m, false);

        vector<manhattanDistance> allDistances;

        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                manhattanDistance newDistance;
                newDistance.workerIndex = i;
                newDistance.bikeIndex = j;
                newDistance.dis = calculateManhattanDistance(workers, bikes, i, j);

                allDistances.push_back(newDistance);
            }
        }

        vector<int> ans(n, 0);
        sort(allDistances.begin(), allDistances.end(), compare);

        for (i = 0; i < allDistances.size(); ++i) {
            auto aDistance = allDistances[i];
            if (!assignedWorker[aDistance.workerIndex] && !assignedBike[aDistance.bikeIndex]) {
                assignedWorker[aDistance.workerIndex] = true;
                assignedBike[aDistance.bikeIndex] = true;

                ans[aDistance.workerIndex] = aDistance.bikeIndex;
                -- n;
            }

            if (n == 0) break;
        }

        return ans;
    }

    int calculateManhattanDistance(const vector<vector<int>>& workers, const vector<vector<int>>& bikes, int workerIndex, int bikeIndex) {
        return abs(workers[workerIndex][0] - bikes[bikeIndex][0]) + abs(workers[workerIndex][1] - bikes[bikeIndex][1]);
    }
};