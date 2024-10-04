class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());

        int i, n = skill.size();
        long long ans = 0, last = skill.front() + skill.back();

        for (i = 0; i < n / 2; ++i) {
            if (skill[i] + skill[n - 1 - i] != last) {
                return -1;
            }

            ans += ((long long)skill[i] * skill[n - 1 - i]);
        }

        return ans;
    }
};