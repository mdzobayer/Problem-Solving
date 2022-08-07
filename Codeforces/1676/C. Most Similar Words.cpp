#include <bits/stdc++.h>

#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define fileRead freopen("in.txt", "r", stdin);

using namespace std;

int calculateCost(string s1, string s2, int m) {
    int i, cost = 0;

    for (i = 0; i < m; ++i) {
        cost += abs(s1[i] - s2[i]);
    }

    return cost;
}

int main() {


    // fastIO
    // fileRead

    int test, n, m, i, j, specificCost, minimumCost;
    string word;

    cin >> test;
    while(test--) {
        cin >> n >> m;
        
        vector <string> words;

        for (i = 0; i < n; ++i) {
            cin >> word;
            words.push_back(word);
        }

        // sort(words.begin(), words.end());
        minimumCost = INT_MAX;

        for (i = 0; i < n; ++i) {

            for (j = 0; j < n; ++j) {
                if (i == j) continue;
                minimumCost = min(minimumCost, calculateCost(words[i], words[j], m));
            }

        }
            
        cout << minimumCost << endl;
    }

    return (0);
}