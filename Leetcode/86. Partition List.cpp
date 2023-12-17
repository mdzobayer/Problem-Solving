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
    ListNode* partition(ListNode* head, int x) {
        
        if (head == nullptr) return head;

        ListNode *before, *after, *cursor1, *cursor2;

        before = new ListNode(0);
        cursor1 = before;
        after = new ListNode(0);
        cursor2 = after;

        while(head != nullptr) {
            if (head->val < x) {
                cursor1->next = new ListNode(head->val);
                cursor1 = cursor1->next;
            }
            else {
                cursor2->next = new ListNode(head->val);
                cursor2 = cursor2->next;
            }

            head = head->next;
        }

        cursor1->next = after->next;
        head = before;
        before = before->next;

        delete after;
        delete head;;

        return before;
    }
};