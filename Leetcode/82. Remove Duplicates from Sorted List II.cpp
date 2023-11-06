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
    ListNode* deleteDuplicates(ListNode* head) {

        if (head == nullptr) return head;

        map<int,int> counts;
        ListNode * previous, * cursor = head;

        while(cursor != nullptr) {
            counts[cursor->val] += 1;
            cursor = cursor->next;
        }

        while(counts[head->val] > 1) {
            cursor = head;
            head = head->next;
            delete cursor;

            if (head == nullptr) return head;
        }

        cursor = head->next;
        previous = head;
        while(cursor != nullptr) {
            
            if (counts[cursor->val] > 1) {
                previous->next = cursor->next;
                
                delete cursor;
                cursor = previous->next;
                continue;
            }

            previous = cursor;
            cursor = cursor->next;
        }

        return head;
    }
};