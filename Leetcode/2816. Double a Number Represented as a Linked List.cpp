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
    ListNode* doubleIt(ListNode* head) {
        int carry = solve(head);
        if (carry == 0) return head;

        ListNode *newHead = new ListNode(carry, head);

        return newHead;
    }

    int solve(ListNode * head) {
        int carry = 0;
        if (head->next != nullptr) {
            carry = solve(head->next);
        }

        head->val *= 2;
        head->val += carry;
        carry = (head->val > 9) ? 1 : 0;
        head->val %= 10;

        return carry;
    }
};