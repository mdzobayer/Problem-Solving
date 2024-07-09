class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        //sort(customers.begin(), customers.end());

        long long totalWaitingTime = 0, chefWillFree = 0;

        for (auto customer : customers) {
            if (customer[0] >= chefWillFree) {
                chefWillFree = customer[0] + customer[1];
                totalWaitingTime += customer[1];
            }
            else {
                chefWillFree += customer[1];
                totalWaitingTime += (chefWillFree - customer[0]);
            }
        }

        return static_cast<double>(totalWaitingTime) / (int) customers.size();
    }
};