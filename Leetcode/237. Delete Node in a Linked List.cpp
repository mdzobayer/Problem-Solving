/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node, *next = node->next;

        while(next != nullptr) {
            curr->val = next->val;

            if (next->next == nullptr) {
                curr->next = nullptr;
                break;
            }

            curr = next;
            next = next->next;
        }
    }
};