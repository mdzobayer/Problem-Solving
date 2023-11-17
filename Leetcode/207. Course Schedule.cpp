class Solution {
    int courseState[2000+5];
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        bool ans = true;
        for (i = 0; i < n; ++i) {
            if(!isPossible(i, individualPrerequisites)) {
                ans = false;
                break;
            }
        }

        return ans;
    }

    bool isPossible(int course, const vector<vector<int>> & individualPrerequisites) {
        if (courseState[course] == 1) return false;
        if (courseState[course] == 2) return true;

        courseState[course] = 1;
        int i, nextCourse;

        for (i = 0; i < individualPrerequisites[course].size(); ++i) {
            nextCourse = individualPrerequisites[course][i];
            if (!isPossible(nextCourse, individualPrerequisites)) return false;
        }

        courseState[course] = 2;

        return true;
    }
};