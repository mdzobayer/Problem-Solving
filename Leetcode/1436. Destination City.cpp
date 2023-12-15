class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> nextRoute;

        for (int i = 0; i < paths.size(); ++i) {
            nextRoute[paths[i][0]] = paths[i][1];
        }

        string currentCity = paths[0][0];
        while(nextRoute.find(currentCity) != nextRoute.end()) {
            currentCity = nextRoute[currentCity];
        }

        return currentCity;
    }
};