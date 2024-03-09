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
    ListNode* frequenciesOfElements(ListNode* head) {

        vector<int> counts(100001, 0);

        explore(head, counts);

        ListNode * newHead, * cursor;
        newHead = new ListNode();
        cursor = newHead;

        for (int i = 0; i < counts.size(); ++i) {
            if (counts[i] > 0) {
                cursor->next = new ListNode(counts[i]);
                cursor = cursor->next;
            }
        }

        return newHead->next;
    }

    void explore(ListNode * root, vector<int> &counts) {
        if(root == nullptr) return;

        counts[root->val] += 1;
        explore(root->next, counts);
    }
};