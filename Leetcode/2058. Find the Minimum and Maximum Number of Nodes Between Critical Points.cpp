/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int counter = 0;
        vector<int> ans{-1, -1};
        vector<int> criticalPoints;

        ListNode * cursor1, * cursor2;
        cursor1 = head;
        if (cursor1 == nullptr) {
            return ans;
        }

        while(cursor1 != nullptr) {
            cursor2 = cursor1->next;

            if (cursor2 == nullptr || cursor2->next == nullptr) {
                break;
            }

            if (cursor1->val < cursor2->val && cursor2->val > cursor2->next->val) {
                criticalPoints.push_back(counter);
            }
            else if (cursor1->val > cursor2->val && cursor2->val < cursor2->next->val) {
                criticalPoints.push_back(counter);
            }

            cursor1 = cursor2;
            ++counter;
        }

        if (criticalPoints.size() < 2) {
            return ans;
        }

        ans[0] = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); ++i) {
            ans[0] = min(ans[0], criticalPoints[i] - criticalPoints[i - 1]);
        }
        ans[1] = criticalPoints.back() - criticalPoints.front();

        return ans;
    }
};