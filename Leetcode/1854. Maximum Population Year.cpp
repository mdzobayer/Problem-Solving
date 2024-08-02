class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        const int base = 1950;
        vector<int> population(100 + 1, 0);
        vector<int> died(100 + 1, 0);
        int i, count = 0, year = 0, n = logs.size();

        for (i = 0; i < n; ++i) {
            ++ population[logs[i][0] - base];
        }

        for (i = 1; i < 100; ++i) {
            population[i] += population[i - 1];
        }

        for (i = 0; i < n; ++i) {
            ++ died[logs[i][1] - base];
        }

        population[0] -= died[0];
        count = population[0];

        for (i = 1; i < 100; ++i) {
            died[i] += died[i - 1];
            population[i] -= died[i];

            if (count < population[i]) {
                count = population[i];
                year = i;
            }
        }

        return year + base;
    }
};