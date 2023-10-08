class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        pair<int, int> pairItem;
        int i, j, cAns;
        vector<int> ans;

        //stk.push_back(temperatures.back());
        //ans.push_back(0);

        for (i = temperatures.size() - 1; i >= 0; --i) {
            j = i;
            cAns = 1;

            while(!stk.empty()) {
                pairItem = stk.top();
                if (pairItem.first <= temperatures[i]) {
                    stk.pop();
                }
                else {
                    break;
                }
            }

            if(stk.empty()) {
                cAns = 0;
            }
            else {
                pairItem = stk.top();
                cAns = pairItem.second - i;
            }

            stk.push(make_pair(temperatures[i], i));
            ans.push_back(cAns);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};