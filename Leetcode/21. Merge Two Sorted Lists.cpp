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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = new ListNode(0), *cursor = head;

        while(list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                cursor->next = new ListNode(list1->val);
                cursor = cursor->next;

                list1 = list1->next;
            }
            else {
                cursor->next = new ListNode(list2->val);
                cursor = cursor->next;
                
                list2 = list2->next;
            }
        }

        while(list1 != nullptr) {
            cursor->next = new ListNode(list1->val);
            cursor = cursor->next;
            list1 = list1->next;
        }

        while(list2 != nullptr) {
            cursor->next = new ListNode(list2->val);
            cursor = cursor->next;
            list2 = list2->next;
        }

        cursor = head;
        head = head->next;
        delete cursor;

        return head;
    }
};