class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> childParentMap;

        for (auto & regionArray : regions) {
            string parentNode = regionArray[0];

            for (int i = 1; i < regionArray.size(); ++i) {
                childParentMap[regionArray[i]] = parentNode;
            }
        }

        auto path1 = fetchPathForRegion(region1, childParentMap);
        auto path2 = fetchPathForRegion(region2, childParentMap);

        int i = 0, j = 0;

        string lowestCommonAncestor;
        while(i < path1.size() && j < path2.size() && path1[i] == path2[j]) {
            lowestCommonAncestor = path1[i];
            ++i;
            ++j;
        }

        return lowestCommonAncestor;
    }

    vector<string> fetchPathForRegion(string currNode, unordered_map<string, string> & childParentMap) {
        vector<string> path;

        path.push_back(currNode);

        while(childParentMap.find(currNode) != childParentMap.end()) {
            string parentNode = childParentMap[currNode];
            path.push_back(parentNode);
            currNode = parentNode;
        }

        reverse(path.begin(), path.end());

        return path;
    }
};