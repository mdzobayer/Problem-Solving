class Solution {
    
public:
    string countOfAtoms(string formula) {
        int runningMultiplier = 1, currentMultipiler, i;
        string currAtom = "", currMulti = "";

        unordered_map<string, int> atomFreq;
        stack<int> previousMultiplier;

        for (i = formula.size() - 1; i >= 0; --i) {
            
            if (isdigit(formula[i])) {
                currMulti = formula[i] + currMulti;
            }
            else if (islower(formula[i])) {
                currAtom = formula[i] + currAtom;
            }
            else if (isupper(formula[i])) {
                currAtom = formula[i] + currAtom;
                
                currentMultipiler = currMulti.empty() ? 1 : stoi(currMulti);

                atomFreq[currAtom] += currentMultipiler * runningMultiplier;

                currMulti = "";
                currAtom = "";
            }
            else if (formula[i] == ')') {
                currentMultipiler = currMulti.empty() ? 1 : stoi(currMulti);
                previousMultiplier.push(currentMultipiler);
                runningMultiplier *= currentMultipiler;

                currMulti = "";
            }
            else {
                runningMultiplier /= previousMultiplier.top();
                previousMultiplier.pop();
            }
        }

        map<string, int> sortedAtomFreq(atomFreq.begin(), atomFreq.end());

        string ans = "";

        for (auto [atom, count] : sortedAtomFreq) {
            ans += atom;
            if (count > 1) {
                ans += to_string(count);
            }
        }

        return ans;
    }
};