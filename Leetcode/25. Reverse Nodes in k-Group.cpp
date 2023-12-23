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
    ListNode * reverseNode(ListNode * head, int k) {
        ListNode * previous, * cursor, * nextNode;
        previous = nullptr;
        cursor = head;

        while(k > 0) {
            nextNode = cursor->next;
            cursor->next = previous;
            previous = cursor;
            cursor = nextNode;

            --k;
        }

        return previous;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        vector<ListNode*> pointers, segment;
        int i, count = 0, n = 0;
        ListNode * cursor = head;


        while(count < k && cursor != nullptr) {
            ++count;
            cursor = cursor->next;
        }

        if (count == k) {
            ListNode * reversedCursor = reverseNode(head, k);

            head->next = reverseKGroup(cursor, k);
            return reversedCursor;
        }

        return head;
    }
};