class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int i, level, ans = -1;
        string str;
        pair<int, string> mutationWithLevel;

        set<string> visitedMutation;

        queue<pair<int, string>> q;
        q.push(make_pair(0, startGene));
        visitedMutation.insert(startGene);

        while(!q.empty()) {
            mutationWithLevel = q.front();
            q.pop();

            level = mutationWithLevel.first;
            if (mutationWithLevel.second == endGene) {
                ans = level;
                break;
            }
            
            for (i = 0; i < bank.size(); ++i) {
                if (mutationGap(mutationWithLevel.second, bank[i]) == 1 &&
                visitedMutation.find(bank[i]) == visitedMutation.end()) {
                    q.push(make_pair(level + 1, bank[i]));
                    visitedMutation.insert(bank[i]);
                }
            }

        }

        return ans;
    }

    int mutationGap(const string & s1, const string & s2) {
        int gap = 0, i;

        for (i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) ++gap;
        }

        return gap;
    }
};