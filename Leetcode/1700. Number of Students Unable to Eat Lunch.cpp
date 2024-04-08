class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int ans = 0, demand0 = 0, demand1 = 0, supply0 = 0, supply1 = 0;
        queue<int> q;
        unordered_map<int, int> hashMap;

        for (int choice: students) {
            ++ hashMap[choice];
            q.push(choice);
        }

        for (int topElement : sandwiches) {
            if (hashMap[topElement] == 0) {
                break;
            }

            while(!q.empty()) {
                int choice = q.front();
                q.pop();

                if (choice == topElement) {
                    -- hashMap[topElement];
                    break;
                }

                q.push(choice);
            }
        }

        return q.size();
    }
};