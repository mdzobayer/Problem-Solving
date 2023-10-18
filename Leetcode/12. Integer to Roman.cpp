class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> symbolMap;
        
        symbolMap.push_back(make_pair(1000, "M"));
        symbolMap.push_back(make_pair(500, "D"));
        symbolMap.push_back(make_pair(100, "C"));
        symbolMap.push_back(make_pair(50, "L"));
        symbolMap.push_back(make_pair(10, "X"));
        symbolMap.push_back(make_pair(5, "V"));
        symbolMap.push_back(make_pair(1, "I"));
        //symbolMap.push_back(make_pair(1, "I"));

        string ans = "";
        int i = 0;
        while(num > 0 && i < symbolMap.size()) {
            if (symbolMap[i].first <= num) {
                ans += symbolMap[i].second;
                num -= symbolMap[i].first;
            }
            else {
                int j = possibleValueIndex(symbolMap, symbolMap[i].second);
                if (j < symbolMap.size()) {
                    int possValue = symbolMap[i].first - symbolMap[j].first;
                    if (possValue <= num) {
                        num -= possValue;

                        ans += symbolMap[j].second;
                        ans += symbolMap[i].second;
                    }
                }

                ++ i;
            }
        }
        
        return ans;
    }

    int possibleValueIndex(vector<pair<int, string>> & symbolMap, string current) {

        if (current == "L" || current == "C") return 4;
        else if (current == "D" || current == "M") return 2;
        else return 6;
    }
};