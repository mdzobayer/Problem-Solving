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
    vector<int> nodes;
public:
    string gameResult(ListNode* head) {
        traverse(head);

        int i, even = 0, odd = 0;

        for (i = 1; i < nodes.size(); i += 2) {
            if (nodes[i - 1] > nodes[i]) {
                ++ even;
            }
            else if (nodes[i - 1] < nodes[i]) {
                ++ odd;
            }
        }

        string ans = "Tie";
        if (even > odd) {
            ans = "Even";
        }
        else if (even < odd) {
            ans = "Odd";
        }

        return ans;
    }

    void traverse(ListNode * head) {
        if (head == nullptr) return;

        nodes.push_back(head->val);
        traverse(head->next);
    }
};