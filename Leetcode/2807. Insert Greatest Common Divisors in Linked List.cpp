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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* cursor = head;

        while(cursor != nullptr && cursor->next != nullptr) {
            int gcdValue = gcd(cursor->val, cursor->next->val);
            cursor->next = new ListNode(gcdValue, cursor->next);
            cursor = cursor->next->next;
        }

        return head;
    }

    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
};