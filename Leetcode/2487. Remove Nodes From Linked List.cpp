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
    ListNode* removeNodes(ListNode* head) {
        clearNodes(head);

        return head;
    }

    int clearNodes(ListNode * head) {
        
        if (head->next == nullptr) {
            return head->val;
        }

        int rightMax = clearNodes(head->next);

        if (rightMax > head->val) {
            head->val = head->next->val;
            head->next = head->next->next;
        }

        return max(rightMax, head->val);
    }
};