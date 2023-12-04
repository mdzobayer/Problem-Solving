class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;

        int i;
        string s, ans = "";
        for (i = 0; i < path.size(); ++i) {
            if (path[i] == '/') path[i] = ' ';
        }

        stringstream ss(path);
        while(ss >> s) {
            if (s == ".") continue;
            else if (s == "..") {
                if (stack.size() > 0) stack.pop_back();
            }
            else {
                stack.push_back(s);
            }
        }

        for (i = 0; i < stack.size(); ++i) {
            ans = ans + "/" + stack[i];
        }
        if (ans == "") ans = "/";

        return ans;
    }
};