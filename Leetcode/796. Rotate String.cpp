class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        deque<char> ss(s.begin(), s.end());

        int i = 0;
        while(i < s.size()) {
            ++i;

            if (compare(ss, goal)) return true;;

            char ch = ss.front();
            ss.push_back(ch);
            ss.pop_front();
        }

        return false;
    }

    bool compare(const deque<char> & ss, const string & goal) {
        auto it1 = ss.begin();
        auto it2 = goal.begin();

        while(it1 != ss.end()) {

            if (*it1 != *it2) return false;

            ++it1; ++it2;
        }

        return true;
    }
};