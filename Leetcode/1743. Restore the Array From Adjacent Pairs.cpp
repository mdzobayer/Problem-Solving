class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> mappedPairs;
        map<int, bool> takenItem;
        int i, item, n = adjacentPairs.size();
        vector<int> ans;

        for (i = 0; i < n; ++i) {
            if (mappedPairs.find(adjacentPairs[i][0]) == mappedPairs.end()) {
                vector<int> vt;
                mappedPairs[adjacentPairs[i][0]] = vt;
            }

            if (mappedPairs.find(adjacentPairs[i][1]) == mappedPairs.end()) {
                vector<int> vt;
                mappedPairs[adjacentPairs[i][1]] = vt;
            }

            mappedPairs[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            mappedPairs[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
            takenItem.insert({adjacentPairs[i][0], false});
            takenItem.insert({adjacentPairs[i][1], false});
        }

        list<int> originalList;
        originalList.push_back(adjacentPairs[0][0]);
        originalList.push_back(adjacentPairs[0][1]);
        takenItem[adjacentPairs[0][0]] = true;
        takenItem[adjacentPairs[0][1]] = true;

        // add items on back
        while(true) {
            vector<int> items = mappedPairs[originalList.back()];
            item = items.front();
            if (takenItem[item] == false) {
                takenItem[item] = true;
                originalList.push_back(item);
                continue;
            }
            item = items.back();
            if (takenItem[item] == false) {
                takenItem[item] = true;
                originalList.push_back(item);
                continue;
            }
            break;
        }

        // add items on front
        while(true) {
            vector<int> items = mappedPairs[originalList.front()];
            item = items.front();
            if (takenItem[item] == false) {
                takenItem[item] = true;
                originalList.push_front(item);
                continue;
            }
            item = items.back();
            if (takenItem[item] == false) {
                takenItem[item] = true;
                originalList.push_front(item);
                continue;
            }
            break;
        }

        for (auto x : originalList) {
            ans.push_back(x);
        }

        return ans;
    }
};