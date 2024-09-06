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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hashSet;
        for (int item : nums) {
            hashSet.insert(item);
        }

        while(head != nullptr && (hashSet.find(head->val) != hashSet.end())) {
            head = head->next;
        }

        ListNode * cursor = head;

        while(cursor != nullptr && cursor->next != nullptr) {
            if ((hashSet.find(cursor->next->val) != hashSet.end())) {
                cursor->next = cursor->next->next;
                continue;
            }
            cursor = cursor->next;
        }

        return head;
    }
};