#include <bits/stdc++.h>

using namespace std;

string decodeString(string s) {
        int i, j, numberOfRepetition;
        string ans = "", decodedStr = "", repeatedStr, numberOfRepetitionStr = "";
        bool isDigitStarted = true;
        
        pair<int, string> tempPair;
        stack<pair<int, string>> stk;

        for (i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                if (isDigitStarted) {
                    numberOfRepetitionStr += s[i];
                }
                else {
                    numberOfRepetition = stoi(numberOfRepetitionStr);
                    // add to stack
                    stk.push(make_pair(numberOfRepetition, decodedStr));
                    // reset variables
                    decodedStr = "";
                    isDigitStarted = true;
                    numberOfRepetitionStr = "";
                    numberOfRepetitionStr += s[i];
                }
                
            }
            else if (s[i] == '[') {
                isDigitStarted = false;
                
            }
            else if (isalpha(s[i])) {
                decodedStr += s[i];
                isDigitStarted = false;
            }
            else if (s[i] == ']') {

                if (numberOfRepetitionStr.size() > 0) {
                    numberOfRepetition = stoi(numberOfRepetitionStr);
                    // add to stack
                    stk.push(make_pair(numberOfRepetition, decodedStr));

                    // reset variables
                    decodedStr = "";
                    isDigitStarted = true;
                    numberOfRepetitionStr = "";
                }

                // Process task
                tempPair = stk.top();
                stk.pop();
                cerr << "tempPair " << tempPair.first << " " << tempPair.second << endl;

                repeatedStr = "";
                for (j = 0; j < tempPair.first; ++j) {
                    repeatedStr += tempPair.second;
                }

                if (stk.empty()) {
                    ans += repeatedStr;
                } else {
                    tempPair.second += repeatedStr;
                    stk.push(tempPair);
                }
            }
            else {
                ans += s[i];
            }
        }

        return ans;
    }

int main() {

    string s1 = "3[a]2[bc]";
    string s2 = "3[2[c]]2[b]";
    string s3 = "3[a2[c]]2[bc]";

    cout << decodeString(s3) << endl;

    return (0);
}