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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode * cursor1 = head;
        unordered_map<int, int> freq;

        while(cursor1 != nullptr) {
            ++ freq[cursor1->val];
            cursor1 = cursor1->next;
        }

        while(head != nullptr && freq[head->val] > 1) {
            cursor1 = head;
            head = head->next;

            //delete cursor1;
        }

        cursor1 = head;
        while(cursor1 != nullptr) {
            if (cursor1->next != nullptr && freq[cursor1->next->val] > 1) {
                auto willDeleteCursor = cursor1->next;
                cursor1->next = cursor1->next->next;

                //delete willDeleteCursor;
            }
            else {
                cursor1 = cursor1->next;
            }
        }

        return head;
    }
};