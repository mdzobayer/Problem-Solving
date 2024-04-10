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
    ListNode* plusOne(ListNode* head) {
        bool carry = solve(head);
        ListNode* cursor;

        if(carry) {
            cursor = new ListNode(1, head);
            return cursor;
        }

        return head;
    }

    bool solve(ListNode * head) {
        if (head == nullptr) return true;

        bool carry = solve(head->next);

        if (carry) {
            head->val += 1;
            carry = false;
            if (head->val > 9) {
                head->val = 0;
                carry = true;
            }
        }

        return carry;
    }
};