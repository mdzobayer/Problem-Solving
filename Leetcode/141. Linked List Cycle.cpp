/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    set<ListNode *> visited;
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) return false;
        if (visited.find(head) != visited.end()) return true;
        
        visited.insert(head);

        return hasCycle(head->next);
    }
};