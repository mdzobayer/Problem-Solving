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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode* cursor = head;
        int len = 0;

        while(cursor != nullptr) {
            ++len;
            cursor = cursor->next;
        }

        vector<ListNode*> ans(k, nullptr);

        int outer = len / k, reminder = len % k, inner;
        cursor = head;

        bool balanceNeed = len > k;

        for (int i = 0; i < k; ++i) {
            ans[i] = cursor;
            for (int j = 0; cursor != nullptr && j < outer - 1; ++j) {
                cursor = cursor->next;
            }
            
            if (balanceNeed && reminder > 0) {
                cursor = cursor->next;
                --reminder;
            }

            ListNode* lastNode = cursor;
            if (cursor != nullptr)  cursor = cursor->next;
           
            if (lastNode != nullptr) lastNode->next = nullptr;
        }
        

        return ans;
    }
};