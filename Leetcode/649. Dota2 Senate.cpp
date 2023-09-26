#include <bits/stdc++.h>

using namespace std;

string predictPartyVictory(string senate) {
        int i, frontValue, rCount = 0, dCount = 0, ignoreRaCount = 0, ignoreDaCount = 0,  len;
        string ans = "";

        queue<int> senatorsQueue;

        len = senate.size();
        for (i = 0; i < len; ++i) {
            senatorsQueue.push(senate[i]);
            if (senate[i] == 'R') ++rCount;
            else ++dCount;
        }

        while(!senatorsQueue.empty() && dCount > 0 && rCount > 0) {
            frontValue = senatorsQueue.front();
            senatorsQueue.pop();
            

            if (frontValue == 'R') {
                if (ignoreRaCount > 0) {
                    --ignoreRaCount;
                    --rCount;
                }
                else {
                    ++ignoreDaCount;
                    senatorsQueue.push(frontValue);
                }
                
            } 
            else {
                if (ignoreDaCount > 0) {
                    --ignoreDaCount;
                    --dCount;
                }
                else {
                    ++ignoreRaCount;
                    senatorsQueue.push(frontValue);
                }
            } 
        }

        if (dCount > 0) {
            ans = "Dire";
        }
        else {
            ans = "Radiant";
        }
        

        return ans;
    }

int main() {

    cerr << predictPartyVictory("DDRRR") << endl;

    return (0);
}