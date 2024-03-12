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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode * cursor = head;
        int i, j, k, sub, sum, n = 0;
        vector<int> oldList;

        while(cursor != nullptr) {
            oldList.push_back(cursor->val);
            cursor = cursor->next;
        }

        n = oldList.size();
        vector<bool> available(n, true);

        for (i = 0; i < n; ++i) {
            sum = 0;
            for (j = i; j < n && available[j]; ++j) {
                sum += oldList[j];

                if (sum == 0) {
                    for (k = i; k <= j; ++k) {
                        available[k] = false;
                    }
                    break;
                }
            }
        }

        ListNode newHead;
        cursor = &newHead;

        for (i = 0; i < n; ++i) {
            if (available[i]) {
                cursor->next = new ListNode(oldList[i]);
                cursor = cursor->next;
            }
        }

        return newHead.next;
    }
};