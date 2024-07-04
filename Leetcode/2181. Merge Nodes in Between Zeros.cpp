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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * cursor1, * cursor2;

        cursor1 = head;

        while(cursor1 != nullptr) {
            cursor2 = cursor1->next;
            int sum = 0;

            while(cursor2 != nullptr && cursor2->val != 0) {
                sum += cursor2->val;
                cursor2 = cursor2->next;
            }

            if (sum > 0) {
                ListNode * newNode = new ListNode(sum, cursor2);
                cursor1->next = newNode;
            }

            cursor1 = cursor2;
        }

        cursor1 = head->next;

        while(cursor1 != nullptr) {
            cursor2 = cursor1->next;
            
            if(cursor2 != nullptr && cursor2->val == 0) {
                cursor1->next = cursor2->next;
                cursor2 = cursor2->next;
            }
            cursor1 = cursor2;
        }
        
        return head->next;
    }
};