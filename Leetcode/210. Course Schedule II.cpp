class Solution {
    int courseState[2000+5];
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> row;
        vector<vector<int>>individualPrerequisites;

        int i, a, b, n = numCourses;
        for(i = 0; i < n; ++i) {
            individualPrerequisites.push_back(row);
        }

        for (i = 0; i < prerequisites.size(); ++i) {
            a = prerequisites[i][0];
            b = prerequisites[i][1]; 
            individualPrerequisites[a].push_back(b);
        }
        memset(courseState, 0, sizeof(courseState));

        vector<int> ans;
        bool possible = true;
        for (i = 0; i < n; ++i) {
            vector<int> courseOrder;
            if(!isPossible(i, individualPrerequisites, courseOrder)) {
                possible = false;
                break;
            }

            for (int j = 0; j < courseOrder.size(); ++j) {
                ans.push_back(courseOrder[j]);
            }
        }

        if (!possible) ans.clear();

        return ans;
    }

    bool isPossible(int course, const vector<vector<int>> & individualPrerequisites, vector<int> & courseOrder) {
        if (courseState[course] == 1) return false;
        if (courseState[course] == 2) return true;

        courseState[course] = 1;
        int i, nextCourse;

        for (i = 0; i < individualPrerequisites[course].size(); ++i) {
            nextCourse = individualPrerequisites[course][i];
            if (!isPossible(nextCourse, individualPrerequisites, courseOrder)) return false;
        }

        courseState[course] = 2;
        courseOrder.push_back(course);

        return true;
    }
};