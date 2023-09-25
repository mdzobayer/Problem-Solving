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
    ListNode* reverseList(ListNode* head) {
        ListNode * currNode, * headNode;

        stack<int> numbersStack;
        currNode = head;
        while(currNode != nullptr) {
            numbersStack.push(currNode->val);
            currNode = currNode->next;
        }

        headNode = nullptr;
        if(!numbersStack.empty()){
            int num = numbersStack.top();
            numbersStack.pop();

            headNode = new ListNode(num);
            currNode = headNode;
        }

        while(!numbersStack.empty()){
            int num = numbersStack.top();
            numbersStack.pop();

            currNode->next = new ListNode(num);
            currNode = currNode->next;
        }

        return headNode;
    }
};