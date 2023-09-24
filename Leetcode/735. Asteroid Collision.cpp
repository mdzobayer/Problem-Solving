#include <bits/stdc++.h>

using namespace std;


    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        int i, item, negativeItem;

        vector<int> ans;

        for (i = 0; i < asteroids.size(); ++i) {
            if (asteroids[i] >= 0) {
                stk.push(asteroids[i]);
            }
            else if (!stk.empty()) {
                bool isDestroyed = false;

                while(!stk.empty()){
                    item = stk.top();
                    negativeItem = asteroids[i] * -1;
                    //cerr << "item " << item << " asteroids[i] " << asteroids[i] << endl;

                    if (item < negativeItem) {
                        stk.pop();
                        continue;
                    }
                    else if (item > negativeItem) {
                        isDestroyed = true;
                        break;
                    }
                    else {
                        isDestroyed = true;
                        stk.pop();
                        break;
                    }
                }

                if (!isDestroyed) {
                    ans.push_back(asteroids[i]);
                }
            }
            else {
                ans.push_back(asteroids[i]);
            }
            
        }
        
        vector<int> temp;
        while(!stk.empty()) {
            item = stk.top();
            temp.push_back(item);
            stk.pop();
        }

        reverse(temp.begin(), temp.end());

        for (i = 0; i < temp.size(); ++i) {
            ans.push_back(temp[i]);
        }

        return ans;
    }


int main() {

    vector<int> asteroids{8,-8};

    vector<int> result = asteroidCollision(asteroids);

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return (0);
}