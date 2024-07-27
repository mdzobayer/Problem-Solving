// Topological Sort, Kahn's Algorithm
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = topologicalSort(k, rowConditions);
        vector<int> colOrder = topologicalSort(k, colConditions);

        if (rowOrder.size() != k || colOrder.size() != k) return {};

        vector< vector<int> > ans(k, vector<int>(k, 0));

        int i, j;
        for (i = 0; i < k; ++i) {
            for (j = 0; j < k; ++j) {
                if (rowOrder[i] == colOrder[j]) {
                    ans[i][j] = rowOrder[i];
                }
            }
        }

        return ans;
    }

    vector<int> topologicalSort(int k, vector<vector<int>>& conditions) {
        vector<int> order, inDegrees(k + 1, 0);
        vector< vector<int> > ajlist(k + 1, vector<int>());

        int i, currentTask, nextTask;
        for (i = 0; i < conditions.size(); ++i) {
            ajlist[conditions[i][0]].push_back(conditions[i][1]);
            ++ inDegrees[conditions[i][1]];
        }

        queue<int> q;
        for (i = 1; i <= k; ++i) {
            if (inDegrees[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            currentTask = q.front();
            q.pop();
            order.push_back(currentTask);

            for (i = 0; i < ajlist[currentTask].size(); ++i) {
                nextTask = ajlist[currentTask][i];

                -- inDegrees[nextTask];
                if (inDegrees[nextTask] == 0) {
                    q.push(nextTask);
                }
            }
        }


        return order;
    }
};