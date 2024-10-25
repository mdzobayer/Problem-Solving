class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> folderSet(folder.begin(), folder.end());

        vector<string> ans;

        for (string & path : folder) {
            string prefix = path;
            bool isParentFolder = true;

            while(!prefix.empty()) {
                size_t pos = prefix.find_last_of('/');
                if (pos == string::npos) break;

                prefix = prefix.substr(0, pos);

                if (folderSet.count(prefix) > 0) {
                    isParentFolder = false;
                    break;
                }
            }

            if (isParentFolder) {
                ans.push_back(path);
            }
        }
        

        return ans;
    }
};