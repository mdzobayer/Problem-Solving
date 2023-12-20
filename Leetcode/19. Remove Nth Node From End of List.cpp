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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * previous = nullptr, *cursor = head;
        int len = 0, cnt = 1;

        while(cursor != nullptr) {
            ++len;
            cursor = cursor->next;
        }

        int target = len - n + 1;

        if (target == 1) {
            cursor = head->next;
            delete head;
            return cursor;
        }

        cursor = head;
        while(cursor != nullptr) {
            if (cnt == target) {
                if (previous != nullptr) {
                    previous->next = cursor->next;
                }
                delete cursor;
                break;
            }
            previous = cursor;
            cursor = cursor->next;
            ++cnt;
        }

        return head;
    }
};