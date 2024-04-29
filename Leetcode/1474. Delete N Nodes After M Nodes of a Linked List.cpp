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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        ListNode * newHead, * cursor1, * cursor2;

        newHead = new ListNode();
        cursor2 = newHead;
        cursor1 = head;
        bool take = true;
        int x = 0;

        while(cursor1 != nullptr) {
            ++ x;
            if (take) {
                cursor2->next = new ListNode(cursor1->val);
                cursor2 = cursor2->next;
            }

            if (take && x == m) {
                take = false;
                x = 0;
            }

            if (!take && x == n) {
                take = true;
                x = 0;
            }

            cursor1 = cursor1->next;
        }

        return newHead->next;
    }
};