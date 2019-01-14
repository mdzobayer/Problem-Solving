#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector< pair<string, int> > v;

int main() {
    pair<string, int> p;
    string s = "mississippi";
    for (int i = 0; i < s.size(); ++i) {
//        p = make_pair(s.substr(i),i);
//        v.push_back(p);
        ///v.push_back({s.substr(i), i});
        v.push_back(make_pair(s.substr(i), i));
    }
    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].second << " " << v[i].first << endl;
    }

    return (0);
}
