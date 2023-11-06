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
    ListNode* rotateRight(ListNode* head, int k) {

        if (head == nullptr) return head;

        ListNode * cursor = head;
        int i, n = 0;

        while(cursor != nullptr) {
            ++n;
            cursor = cursor->next;
        }

        k %= n;

        if (k == 0) return head;

        cursor = head;
        i = 0;
        while(cursor != nullptr && i < (n - k)) {
            ++ i;
            if (i == (n - k)) break;
            cursor = cursor->next;
        }

        ListNode * newHead = cursor->next;
        cursor->next = nullptr;
        cursor = newHead;
        while(cursor->next != nullptr) {
            cursor = cursor->next;
        }
        cursor->next = head;

        return newHead;
    }
};