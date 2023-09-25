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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> oddNumbers, evenNumbers;
        int i = 1;
        ListNode * currNode, * headNode;

        currNode = head;
        while(currNode != nullptr) {
            if (i & 1) {
                oddNumbers.push_back(currNode->val);
            }
            else {
                evenNumbers.push_back(currNode->val);
            }

            currNode = currNode->next;
            ++i;
        }

        headNode = nullptr;
        if (oddNumbers.size() > 0) {
            headNode = new ListNode(oddNumbers[0]);
            currNode = headNode;
        }

        for (i = 1; i < oddNumbers.size(); ++i) {
            currNode->next = new ListNode(oddNumbers[i]);
            currNode = currNode->next;
        }

        for (i = 0; i < evenNumbers.size(); ++i) {
            currNode->next = new ListNode(evenNumbers[i]);
            currNode = currNode->next;
        }


        return headNode;
    }
};