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
    void reorderList(ListNode* head) {
        vector<int> list;
        int i, j;
        ListNode * cursor = head;

        while (cursor != nullptr) {
            list.push_back(cursor->val);
            cursor = cursor->next;
        }

        cursor = head;

        i = 0; j = list.size() - 1;
        while(i < j) {

            cursor->val = list[i];
            cursor = cursor->next;

            cursor->val = list[j];
            cursor = cursor->next;

            ++i; --j;
        }

        if (i == j) {
            cursor->val = list[i];
            cursor = cursor->next;
        }
    }
};