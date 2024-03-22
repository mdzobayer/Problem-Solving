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
    ListNode * frontCursor;
    bool solve(ListNode * head) {

        if (head != nullptr) {
            if (!solve(head->next)) return false;
            if (head->val != frontCursor->val) return false;

            frontCursor = frontCursor->next;
        }

        return true;
    }

    bool isPalindrome(ListNode* head) {
        
        frontCursor = head;
        return solve(head);
    }
};