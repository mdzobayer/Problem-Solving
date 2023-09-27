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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode * cursor1, * newHead, * cursor2;
        int n = 1, i;

        cursor1 = head;
        newHead = new ListNode(cursor1->val);
        cursor2 = newHead;
        cursor1 = cursor1->next;

        while(cursor1 != nullptr) {
            ++n;

            cursor2->next = new ListNode(cursor1->val);

            cursor2 = cursor2->next;
            cursor1 = cursor1->next;
        }

        int middleNodeIndex = (n / 2);
        if (n > 1) {
            --middleNodeIndex;
        }
        if (n == 1) {
            middleNodeIndex = 0;
            delete newHead;
            newHead = nullptr;
        }

        cursor2 = newHead;
        for (i = 0; i < n && n > 1; ++i) {
            
            if (i == middleNodeIndex) {
                cursor1 = cursor2->next;
                if (cursor1 != nullptr) {
                    cursor2->next = cursor1->next;
                }
                else {
                    cursor2 = nullptr;
                }

                delete cursor1;
                break;
            }

            cursor2 = cursor2->next;;
        }

        return newHead;
    }
};