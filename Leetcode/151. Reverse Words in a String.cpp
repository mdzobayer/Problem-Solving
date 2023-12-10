class Solution {
public:
    string reverseWords(string s) {
        stringstream strstream(s);
        string str;
        vector<string> vt;

        while(strstream >> str) {
            vt.push_back(str);
        }

        string ans = "";
        for (int i = vt.size() - 1; i >= 0; --i) {
            if (i < vt.size() - 1) {
                ans += " ";
            }

            ans += vt[i];
        }

        return ans;
    }
};