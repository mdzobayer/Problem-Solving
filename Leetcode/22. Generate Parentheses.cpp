class Solution {
  vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        
        string str = "";

        solve(n, 0, str);

        return ans;
    }

    void solve(int openCount, int closeCount, string & str) {
      if (closeCount == 0 && openCount == 0) {
        ans.push_back(str);
        return;
      }
      
      if (openCount > 0) {
        str.push_back('(');
        solve(openCount - 1, closeCount + 1, str);
        str.pop_back();
      }
      
      if (closeCount > 0) {
        str.push_back(')');
        solve(openCount, closeCount - 1, str);
        str.pop_back();
      }
    }
};