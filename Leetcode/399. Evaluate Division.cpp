
class Solution {
    map<string, vector<pair<string, double>>> ajList;
    map<string, bool> visited;
    vector<double> answers;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<pair<string,double>> edges;
        int i;
        for (i = 0; i < equations.size(); ++i) {

            if (ajList.find(equations[i][0]) == ajList.end()) {
                ajList.insert(make_pair(equations[i][0], edges));
            }

            if (ajList.find(equations[i][1]) == ajList.end()) {
                ajList.insert(make_pair(equations[i][1], edges));
            }

            ajList[equations[i][0]].push_back(make_pair(equations[i][1], values[i]));
            ajList[equations[i][1]].push_back(make_pair(equations[i][0], (1.0 / values[i])));

            visited[equations[i][0]] = false;
            visited[equations[i][1]] = false;
        }

        for (i = 0; i < queries.size(); ++i) {
            string x = queries[i][0];
            string y = queries[i][1];

            if (visited.find(x) == visited.end() || visited.find(y) == visited.end()) {
                answers.push_back(-1.0);
                continue;
            }

            if (x == y) {
                answers.push_back(1.0);
                continue;
            }

            map<string, bool>::iterator it;
            for(it = visited.begin(); it != visited.end(); ++it) {
                it->second = false;
            }

            if (!dfs(1.0, y, x)) {
                answers.push_back(-1.0);
            }
        }

        return answers;
    }

    bool dfs(double cumulativeProduct, string & target, string & current) {
        if (target == current) {
            answers.push_back(cumulativeProduct);
            return true;
        }

        visited[current] = true;

        vector<pair<string, double>> connectedEdges = ajList[current];
        for (int i = 0; i < connectedEdges.size(); ++i) {
            if (!visited[connectedEdges[i].first]) {
                bool found = dfs(cumulativeProduct * connectedEdges[i].second, target, connectedEdges[i].first);
                if(found) return found;
            }
        }

        return false;
    }


};