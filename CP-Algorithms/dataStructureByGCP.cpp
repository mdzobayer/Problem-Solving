#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> indexed_set;

int main() {

    vector<int> v = {2, 4, 2, 5, 1};

    vector<int> a(8);
    vector<int> b(8, 2);

    for (int i = 0; i < b.size(); ++i) {
        cout << b[i] << "\n";
    }
    cout << "auto" << endl;
    v.push_back(10);
    for (auto x : v) {
        cout << x << "\n";
    }

    cout << "v.back() = " << v.back() << endl;

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    random_shuffle(v.begin(), v.end());
    for (auto x : v) {
        cout << x << "\n";
    }

    v = {2, 3, 3, 5, 5, 5, 7, 8, 8, 8};
    auto c = lower_bound(v.begin(), v.end(), 5);
    auto e = upper_bound(v.begin(), v.end(), 5);

    cout << c - v.begin() << " " << e - v.begin() << "\n";

    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto x : v) {
        cout << x << " ";
    }
    cout << endl;

    deque<int> d;
    cout << "No data = " << d.front() << endl;
    d.push_back(5);
    d.push_back(2);
    d.push_front(3);
    cout << d.front() << " " << d.back() << endl;
    d.pop_front();
    d.pop_back();
    cout << d.front() << " " << d.back() << endl;

    // stack and queue avaliable also

    // Set Structure

    set<int> s;
    s.insert(3);
    s.insert(3);
    s.insert(3);
    s.insert(2);
    s.insert(5);
    cout << "Set Count = " << s.count(3) << endl;
    cout << "Set Count = " << s.count(4) << endl;
    auto iteratorSet = s.find(10);
    if (iteratorSet == s.end()) {
        cout << "not found" << endl;
    }

    cout << "Set = ";
    for (auto x : s) {
        cout << x << " ";
    }
    cout << endl;


    // Policy based sets

    indexed_set iset;

    iset.insert(2);
    iset.insert(3);
    iset.insert(7);
    iset.insert(9);

    auto x = iset.find_by_order(2);

    cout << *x << endl;

    cout << iset.order_of_key(7) << endl;

    return (0);
}