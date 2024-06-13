class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int i, cost = 0, n = students.size();

        for (i = 0; i < n; ++i) {
            cost += abs(students[i] - seats[i]);
        }

        return cost;
    }
};