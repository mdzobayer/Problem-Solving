#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {

        int chars1[130], chars2[130];
        memset(chars1, 0, sizeof(chars1));
        memset(chars2, 0, sizeof(chars2));

        if (word1.size() != word2.size()) return false;

        for (int i = 0; i < word1.size(); ++i) {
            chars1[word1[i]] += 1;
            chars2[word2[i]] += 1;
        }

        vector<int> vt1, vt2;
        for (int i = 'a'; i <= 'z'; ++i) {
            if (chars1[i] == 0 && chars2[i] > 0) return false;
            if (chars2[i] == 0 && chars1[i] > 0) return false;

            if (chars1[i] > 0)
                vt1.push_back(chars1[i]);

            if (chars2[i] > 0)
                vt2.push_back(chars2[i]);
        }

        if(vt1.size() != vt2.size()) return false;

        sort(vt1.begin(), vt1.end());
        sort(vt2.begin(), vt2.end());

        // map<char, int>:: iterator it1, it2;
        // for (it1 = count1.begin(); it1 != count1.end(); ++it1) {
        //     it2 = count2.find(it1->first);
        //     if(it2 == count2.end()) return false;

        //     if (it1->second != it2->second) return false;
        // }

        for (int i = 0; i < vt1.size(); ++i) {
            if (vt1[i] != vt2[i]) return false;
        }

        return true;
    }
};
